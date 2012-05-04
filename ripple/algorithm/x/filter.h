# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides, Paul Fultz II 2003-2012.         *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://github.com/pfultz2/Ripple for most recent version.   *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_X_FILTER_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_X_FILTER_H
#
# include <ripple/comparison/not_equal.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/facilities/optional.h>
# include <ripple/generics/core.h>
# include <ripple/generics/typeof.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/buffer.h>
# include <ripple/recursion/expr.h>
# include <ripple/recursion/phase.h>
# include <ripple/seq/core.h>
# include <ripple/tuple/eat.h>
#
# /* RPP_FILTER_X */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FILTER_X(size, pred, ...) RPP_FILTER_X_S(RPP_STATE(), size, pred, __VA_ARGS__)
# else
#    define RPP_FILTER_X(size, pred, g, data) RPP_FILTER_X_S(RPP_STATE(), size, pred, g, data)
# endif
#
# define RPP_FILTER_X_ID() RPP_FILTER_X
#
# /* RPP_FILTER_X_S */
#
# if CONFIG_RIPPLE_STD
#    define RPP_FILTER_X_S(s, size, pred, ...) \
        DETAIL_RPP_FILTER_X_U(s, size, pred, RPP_NON_OPTIONAL(__VA_ARGS__), RPP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
# else
#    define RPP_FILTER_X_S(s, size, pred, g, data) DETAIL_RPP_FILTER_X_U(s, size, pred, g, (data))
# endif
#
# define RPP_FILTER_X_S_ID() RPP_FILTER_X_S
#
# define DETAIL_RPP_FILTER_X_U(s, size, pred, g, pd) \
    DETAIL_RPP_FILTER_X_I( \
        RPP_NEXT(s), (RPP_NEXT(s)), RPP_FIXED_S(s, size), \
        0, pred, RPP_CALL(pred), RPP_TYPEOF(g), g, RPP_NIL(RPP_TYPEOF(g)), pd \
    ) \
    /**/
# define DETAIL_RPP_FILTER_X_INDIRECT() DETAIL_RPP_FILTER_X_I
# define DETAIL_RPP_FILTER_X_I(s, jump, fix, mode, pred, _p, type, g, res, pd) \
    RPP_IIF(RPP_NOT_EQUAL(s, fix))( \
        RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
            DETAIL_RPP_FILTER_X_II, DETAIL_RPP_FILTER_X_III \
        ), \
        DETAIL_RPP_FILTER_X_V \
    )(RPP_PHASE(0), s, jump, fix, mode, pred, _p, type, g, res, pd) \
    /**/
# define DETAIL_RPP_FILTER_X_II(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    _(1, RPP_EXPR_S)(s)( \
        DETAIL_RPP_FILTER_X_III(_, s, (RPP_NEXT(s)) jump, fix, mode, pred, _p, type, g, res, pd) \
    ) \
    /**/
# define DETAIL_RPP_FILTER_X_III(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    RPP_IIF(RPP_IS_CONS(g))( \
        DETAIL_RPP_FILTER_X_ ## mode, \
        RPP_IIF(mode)( \
            res RPP_TUPLE_EAT(11), \
            DETAIL_RPP_FILTER_X_IV \
        ) \
    )(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    /**/
# define DETAIL_RPP_FILTER_X_IV(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    RPP_IIF(RPP_IS_CONS(res))( \
        DETAIL_RPP_FILTER_X_1, res RPP_TUPLE_EAT(11) \
    )(_, s, jump, fix, 1, pred, _p, type, res, g, pd) \
    /**/
# define DETAIL_RPP_FILTER_X_V(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    DETAIL_RPP_FILTER_X_VI(RPP_SEQ_HEAD(jump), RPP_SEQ_TAIL(jump), fix, mode, pred, _p, type, g, res, pd) \
    /**/
# define DETAIL_RPP_FILTER_X_VI(s, jump, fix, mode, pred, _p, type, g, res, pd) \
    RPP_IIF(RPP_NOT_EQUAL(s, RPP_PREV(fix)))( \
        DETAIL_RPP_FILTER_X_II, DETAIL_RPP_FILTER_X_III \
    )(RPP_PHASE(1), s, RPP_IIF(RPP_SEQ_IS_NIL(jump))((s), jump), fix, mode, pred, _p, type, g, res, pd) \
    /**/
# define DETAIL_RPP_FILTER_X_0(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_FILTER_X_INDIRECT)()( \
        RPP_NEXT(s), jump, fix, mode, pred, _p, type, RPP_TAIL(g), \
        _(1, RPP_IIF)(_(0, _p)()(s, pred, RPP_ITEM(type, RPP_HEAD(g)) _(0, RPP_EXPOSE)(pd)))( \
            _(1, RPP_CONS)(res, RPP_HEAD(g)), res \
        ), \
        pd \
    )) \
    /**/
# define DETAIL_RPP_FILTER_X_1(_, s, jump, fix, mode, pred, _p, type, g, res, pd) \
    _(1, RPP_EXPR_S)(s)(_(1, DETAIL_RPP_FILTER_X_INDIRECT)()( \
        RPP_NEXT(s), jump, fix, mode, pred, _p, type, RPP_TAIL(g), RPP_CONS(res, RPP_HEAD(g)), pd \
    )) \
    /**/
#
# endif