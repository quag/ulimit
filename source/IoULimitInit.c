#include "IoState.h"
#include "IoObject.h"

IoObject *IoULimit_proto(void *state);

void IoULimitInit(IoObject *context)
{
	IoState *self = IoObject_state((IoObject *)context);

	IoObject_setSlot_to_(context, SIOSYMBOL("ULimit"), IoULimit_proto(self));

}
