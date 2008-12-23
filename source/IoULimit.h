/*   copyright: Jonathan Wright, 2007
 *   All rights reserved. See _BSDLicense.txt.
 */

#ifndef IOULimit_DEFINED
#define IOULimit_DEFINED 1

#include "IoObject.h"
#include "IoNumber.h"

#define ISULimit(self) IoObject_hasCloneFunc_(self, (IoTagCloneFunc *)IoULimit_rawClone)

typedef IoObject IoULimit;

IoULimit *IoULimit_rawClone(IoULimit *self);
IoULimit *IoULimit_proto(void *state);
IoULimit *IoULimit_new(void *state);

void IoULimit_free(IoULimit *self);
void IoULimit_mark(IoULimit *self);

/* ----------------------------------------------------------- */

IoObject *IoULimit_setVirtualMemoryLimit(IoULimit *self, IoObject *locals, IoMessage *m);
IoObject *IoULimit_setDataMemoryLimit(IoULimit *self, IoObject *locals, IoMessage *m);
IoObject *IoULimit_setCPUTimeLimit(IoULimit *self, IoObject *locals, IoMessage *m);

#endif
