#ifndef AGONY_PP_VARIADICS_GET_H
#define AGONY_PP_VARIADICS_GET_H

#include "../lang.h"

#define AGONY_PP_PRIVATE_VARIADICS_HEAD(x, ...) v(x)
#define AGONY_PP_PRIVATE_VARIADICS_TAIL(x, ...) v(__VA_ARGS__)

#endif // AGONY_PP_VARIADICS_GET_H