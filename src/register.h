#ifndef REGISTER_H
#define REGISTER_H
#include "sicpstd.h"

#include "obj.h"

struct core {
	obj argl; //  1
	obj cont; //  2
	obj env; //   3
	obj expr; //  4
	obj proc; //  5
	obj stack; // 6
	obj unev; //  7
	obj val; //   8
};
#define nreg 8
#define ncore 16

// global-env      // 1
extern obj ambenv; // 2
extern obj anenv; //  3
extern obj svtmp; //  4
#define nother 4

struct core *dfltcore(void);
obj getroot(void);
void setroot(obj);

#endif
