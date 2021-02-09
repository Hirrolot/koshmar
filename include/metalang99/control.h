/**
 * @file
 * Control expressions.
 */

#ifndef METALANG99_CONTROL_H
#define METALANG99_CONTROL_H

#include <metalang99/lang.h>
#include <metalang99/priv/util.h>
#include <metalang99/uint.h>
#include <metalang99/util.h>

// Desugaring {
/**
 * If @p cond is true, evaluates to @p x, otherwise @p y.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/control.h>
 * #include <metalang99/logical.h>
 *
 * // 123
 * M_if(v(M_true), v(123), v(18))
 *
 * // 18
 * M_if(v(M_false), v(123), v(18))
 * @endcode
 */
#define METALANG99_if(cond, x, y) METALANG99_call(METALANG99_if, cond x y)

/**
 * If @p cond is true, evaluates to @p x, otherwise to emptiness.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/control.h>
 *
 * // 123
 * M_when(v(1), v(123))
 *
 * // M_empty()
 * M_when(v(0), v(123))
 * @endcode
 */
#define METALANG99_when(cond, x) METALANG99_call(METALANG99_when, cond x)

/**
 * If @p cond is true, evaluates to @p f, otherwise to #METALANG99_consume.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/control.h>
 * #include <metalang99/util.h>
 *
 * // 123
 * M_call(M_whenOrConsume(v(1), v(M_id)), v(123))
 *
 * // M_empty()
 * M_call(M_whenOrConsume(v(0), v(M_id)), v(123))
 * @endcode
 */
#define METALANG99_whenOrConsume(cond, f) METALANG99_call(METALANG99_whenOrConsume, cond f)

/**
 * Overloads @p f on a number of arguments.
 *
 * This function counts the number of provided arguments, appends it to @p f and calls the resulting
 * macro identifier with provided arguments.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/control.h>
 *
 * #define X_IMPL(...)    M_overload(v(X_), v(__VA_ARGS__))
 * #define X_1_IMPL(a)    v(Billie & a)
 * #define X_2_IMPL(a, b) v(Jean & a & b)
 *
 * // Billie & 4
 * M_call(X, v(4))
 *
 * // Jean & 5 & 6
 * M_call(X, v(5, 6))
 * @endcode
 *
 * @note This function calls @p f with #METALANG99_call, so no partial application occurs, and so
 * arity specifiers are not needed.
 * @note Currently, this function can accept at most 256 variadic arguments.
 */
#define METALANG99_overload(f, ...) METALANG99_call(METALANG99_overload, f __VA_ARGS__)

/**
 * The plain version of #METALANG99_if.
 */
#define METALANG99_ifPlain(cond, x, y) METALANG99_PRIV_IF(cond, x, y)

/**
 * The plain version of #METALANG99_when.
 */
#define METALANG99_whenPlain(cond, x) METALANG99_ifPlain(cond, x, METALANG99_PRIV_EMPTY())

/**
 * The plain version of #METALANG99_whenOrConsume.
 */
#define METALANG99_whenOrConsumePlain(cond, f) METALANG99_ifPlain(cond, f, METALANG99_PRIV_CONSUME)

/**
 * The plain version of #METALANG99_overload.
 *
 * @note @p f need not be postfixed with `_IMPL`. It is literally invoked as `<f><count of
 * ...>(...)`.
 */
#define METALANG99_overloadPlain(f, ...)                                                           \
    METALANG99_PRIV_CAT(f, METALANG99_variadicsCountPlain(__VA_ARGS__))(__VA_ARGS__)
// }

#ifndef DOXYGEN_IGNORE

// Implementation {
#define METALANG99_overload_IMPL(f, ...)                                                           \
    METALANG99_callTrivial(                                                                        \
        METALANG99_PRIV_CAT(f, METALANG99_variadicsCountPlain(__VA_ARGS__)),                       \
        __VA_ARGS__)

#define METALANG99_if_IMPL(cond, x, y) v(METALANG99_PRIV_if_##cond(x, y))
#define METALANG99_PRIV_if_0(_x, y)    y
#define METALANG99_PRIV_if_1(x, _y)    x

#define METALANG99_when_IMPL(cond, x) v(METALANG99_whenPlain(cond, x))
#define METALANG99_whenOrConsume_IMPL(cond, f)                                                     \
    METALANG99_callTrivial(METALANG99_if, cond, f, METALANG99_consume)
// }

// Arity specifiers {
#define METALANG99_overload_ARITY      2
#define METALANG99_if_ARITY            3
#define METALANG99_when_ARITY          2
#define METALANG99_whenOrConsume_ARITY 2
// }

// Aliases {
#ifndef METALANG99_NO_SMALL_PREFIX

#define M_overload      METALANG99_overload
#define M_if            METALANG99_if
#define M_when          METALANG99_when
#define M_whenOrConsume METALANG99_whenOrConsume

#define M_ifPlain            METALANG99_ifPlain
#define M_overloadPlain      METALANG99_overloadPlain
#define M_whenPlain          METALANG99_whenPlain
#define M_whenOrConsumePlain METALANG99_whenOrConsumePlain

#endif // METALANG99_NO_SMALL_PREFIX
// }

#endif // DOXYGEN_IGNORE

#endif // METALANG99_CONTROL_H
