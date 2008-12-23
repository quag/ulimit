/*#io
ULimit ioDoc(
		 docCopyright("Jonathan Wright", 2007)
		 docLicense("BSD revised")
		 docDescription("")
		 docCategory("")
		 */

#include "IoULimit.h"
#include "IoState.h"

#include <sys/time.h>
#include <sys/resource.h>

IoTag *IoULimit_newTag(void *state)
{
	IoTag *tag = IoTag_newWithName_("ULimit");
	IoTag_state_(tag, state);
	IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoULimit_free);
	IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoULimit_rawClone);
	return tag;
}

IoULimit *IoULimit_proto(void *state)
{
	IoObject *self = IoObject_new(state);
	IoObject_tag_(self, IoULimit_newTag(state));
	
	IoState_registerProtoWithFunc_(state, self, IoULimit_proto);
	
	{
		IoMethodTable methodTable[] = {
		{"setVirtualMemoryLimit", IoULimit_setVirtualMemoryLimit},
		{"setDataMemoryLimit", IoULimit_setDataMemoryLimit},
		{"setCPUTimeLimit", IoULimit_setCPUTimeLimit},
		{NULL, NULL},
		};
		IoObject_addMethodTable_(self, methodTable);
	}
	return self;
}

IoULimit *IoULimit_rawClone(IoULimit *proto) 
{ 
	IoObject *self = IoObject_rawClonePrimitive(proto);
	return self; 
}

IoULimit *IoULimit_new(void *state)
{
	IoULimit *proto = IoState_protoWithInitFunction_(state, IoULimit_proto);
	return IOCLONE(proto);
}

void IoULimit_free(IoULimit *self) 
{ 
}

/* ----------------------------------------------------------- */

void setLimit(int resource, int limit)
{
	struct rlimit rlim;

	getrlimit(resource, &rlim);
	rlim.rlim_cur = limit;
	setrlimit(resource, &rlim);
}

IoObject *IoULimit_setVirtualMemoryLimit(IoULimit *self, IoObject *locals, IoMessage *m)
{
	setLimit(RLIMIT_AS, IoMessage_locals_intArgAt_(m, locals, 0));
	return self;
}

IoObject *IoULimit_setDataMemoryLimit(IoULimit *self, IoObject *locals, IoMessage *m)
{
	setLimit(RLIMIT_DATA, IoMessage_locals_intArgAt_(m, locals, 0));
	return self;
}

IoObject *IoULimit_setCPUTimeLimit(IoULimit *self, IoObject *locals, IoMessage *m)
{
	setLimit(RLIMIT_CPU, IoMessage_locals_intArgAt_(m, locals, 0));
	return self;
}
