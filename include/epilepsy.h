/**
 * @file
 * @brief Re-exports all the functionality.
 *
 * @mainpage Introduction
 *
 * @section Summary
 *
 * @subsection _0 Metalanguage syntax
 * @code
 * #include <epilepsy/lang.h>
 * @endcode
 *
 *  - #call(op, ...)
 *  - #v(...)
 *
 * @subsection _1 Evaluation of metaprograms
 * @code
 * #include <epilepsy/eval.h>
 * @endcode
 *
 *  - #EPILEPSY_EVAL(...)
 *
 * @subsection _2 Auxiliary macros
 * @code
 * #include <epilepsy/aux.h>
 * @endcode
 *
 *   - #EPILEPSY_CAT()
 *   - #EPILEPSY_STRINGIFY()
 *   - #EPILEPSY_EMPTY()
 *   - #EPILEPSY_ID(x)
 *   - #EPILEPSY_EXPAND(...)
 *   - #EPILEPSY_CONSUME(...)
 *   - #EPILEPSY_PARENTHESISE(...)
 *   - #EPILEPSY_UNPARENTHESISE(x)
 *
 * @subsection _3 Control expressions
 * @code
 * #include <epilepsy/control.h>
 * @endcode
 *
 *   - #EPILEPSY_IF(cond, x, y)
 *   - #EPILEPSY_WHILE(predicate, op, context)
 *
 * @subsection _4 Implementation limits
 * @code
 * #include <epilepsy/limits.h>
 * @endcode
 *
 *   - #EPILEPSY_UINT_MAX
 *
 * @subsection _5 Boolean algebra
 * @code
 * #include <epilepsy/logical.h>
 * @endcode
 *
 *   - #EPILEPSY_NOT(x)
 *   - #EPILEPSY_AND(x, y)
 *   - #EPILEPSY_OR(x, y)
 *   - #EPILEPSY_XOR(x, y)
 *
 * @subsection _6 Overloading on a number of arguments
 * @code
 * #include <epilepsy/overload.h>
 * @endcode
 *
 *   - #EPILEPSY_OVERLOAD(op, ...)
 *   - #EPILEPSY_OVERLOAD_CALL(op, ...)
 *
 * @subsection _7 Unsigned integers
 * @code
 * #include <epilepsy/uint.h>
 * @endcode
 *
 *   - #EPILEPSY_UINT_INC(x)
 *   - #EPILEPSY_UINT_DEC(x)
 *   - #EPILEPSY_UINT_EQ(x, y)
 *   - #EPILEPSY_UINT_NEQ(x, y)
 *   - #EPILEPSY_UINT_GREATER(x, y)
 *   - #EPILEPSY_UINT_GREATER_EQUAL(x, y)
 *   - #EPILEPSY_UINT_LESSER(x, y)
 *   - #EPILEPSY_UINT_LESSER_EQUAL(x, y)
 *
 * @subsection _8 Utilities for variadic macros
 * @code
 * #include <epilepsy/variadics.h>
 * @endcode
 *
 *   - #EPILEPSY_VARIADICS_COUNT(...)
 *   - #EPILEPSY_VARIADICS_HEAD(...)
 *   - #EPILEPSY_VARIADICS_TAIL(...)
 *
 * @subsection _9 Static assertions
 * @code
 * #include <epilepsy/assert.h>
 * @endcode
 *
 *  - #EPILEPSY_ASSERT(expr)
 *  - #EPILEPSY_ASSERT_WITH_MSG(expr, message)
 *  - #EPILEPSY_ASSERT_EQ(lhs, rhs)
 *  - #EPILEPSY_ASSERT_EQ_WITH_MSG(lhs, rhs)
 *  - #EPILEPSY_C_STATIC_ASSERT(expr)
 *  - #EPILEPSY_C_STATIC_ASSERT_WITH_MSG(expr, message)
 */

#ifndef EPILEPSY_H
#define EPILEPSY_H

#include <epilepsy/assert.h>
#include <epilepsy/aux.h>
#include <epilepsy/control.h>
#include <epilepsy/eval.h>
#include <epilepsy/lang.h>
#include <epilepsy/limits.h>
#include <epilepsy/overload.h>
#include <epilepsy/uint.h>
#include <epilepsy/variadics.h>

#endif // EPILEPSY_H