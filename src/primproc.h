#ifndef PRIMPROC_H
#define PRIMPROC_H
#include "sicpstd.h"

#include "obj.h"

obj add_pp(const obj);
obj sub_pp(const obj);
obj mul_pp(const obj);
obj div_pp(const obj);

obj lt_pp(const obj);
obj lte_pp(const obj);
obj eqn_pp(const obj);
obj gte_pp(const obj);
obj gt_pp(const obj);

obj and_pp(const obj);
obj or_pp(const obj);
obj not_pp(const obj);

#endif
