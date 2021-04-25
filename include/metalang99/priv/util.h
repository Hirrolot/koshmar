#ifndef ML99_PRIV_UTIL_H
#define ML99_PRIV_UTIL_H

#define ML99_PRIV_CAT(x, y)           ML99_PRIV_PRIMITIVE_CAT(x, y)
#define ML99_PRIV_PRIMITIVE_CAT(x, y) x##y

#define ML99_PRIV_EXPAND(...) __VA_ARGS__
#define ML99_PRIV_EMPTY(...)

#define ML99_PRIV_HEAD(...)        ML99_PRIV_HEAD_AUX(__VA_ARGS__, ~)
#define ML99_PRIV_HEAD_AUX(x, ...) x

#define ML99_PRIV_TAIL(...)         ML99_PRIV_TAIL_AUX(__VA_ARGS__)
#define ML99_PRIV_TAIL_AUX(_x, ...) __VA_ARGS__

#define ML99_PRIV_SND(...)            ML99_PRIV_SND_AUX(__VA_ARGS__, ~)
#define ML99_PRIV_SND_AUX(_x, y, ...) y

#define ML99_PRIV_IF(cond, x, y) ML99_PRIV_PRIMITIVE_CAT(ML99_PRIV_IF_, cond)(x, y)
#define ML99_PRIV_IF_0(_x, y)    y
#define ML99_PRIV_IF_1(x, _y)    x

#define ML99_PRIV_NOT(b) ML99_PRIV_PRIMITIVE_CAT(ML99_PRIV_NOT_, b)
#define ML99_PRIV_NOT_0  1
#define ML99_PRIV_NOT_1  0

#define ML99_PRIV_IS_TUPLE(x) ML99_PRIV_NOT(ML99_PRIV_IS_UNTUPLE(x))

#define ML99_PRIV_IS_UNTUPLE(x)        ML99_PRIV_SND(ML99_PRIV_IS_UNTUPLE_TEST x, 1)
#define ML99_PRIV_IS_UNTUPLE_TEST(...) ~, 0

#define ML99_PRIV_CONTAINS_COMMA(...)                      ML99_PRIV_X_AS_COMMA(__VA_ARGS__, ML99_PRIV_COMMA, ~)
#define ML99_PRIV_X_AS_COMMA(_head, x, ...)                ML99_PRIV_CONTAINS_COMMA_RESULT(x, 0, 1, ~)
#define ML99_PRIV_CONTAINS_COMMA_RESULT(x, _, result, ...) result
#define ML99_PRIV_COMMA                                    ,

#endif // ML99_PRIV_UTIL_H
