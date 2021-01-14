#include <epilepsy/assert.h>
#include <epilepsy/either.h>

// Pattern matching {
#define MATCH_IMPL(either)  E_match(v(either), v(MATCH_))
#define MATCH_left_IMPL(x)  v(E_assertPlain(x == 18))
#define MATCH_right_IMPL(x) v(E_assertPlain(x == 4))

E_eval(E_call(MATCH, E_left(v(18))));
E_eval(E_call(MATCH, E_right(v(4))));

#undef MATCH_IMPL
#undef MATCH_left_IMPL
#undef MATCH_right_IMPL
// }

#define VAL v(abc ? +-148 % "hello world")

// E_isLeft {
E_assert(E_isLeft(E_left(VAL)));
E_assert(E_not(E_isLeft(E_right(VAL))));
// }

// E_isRight {
E_assert(E_isRight(E_right(VAL)));
E_assert(E_not(E_isRight(E_left(VAL))));
// }

#undef VAL
