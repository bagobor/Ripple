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
# ifndef RIPPLE_PREPROCESSOR_ALGORITHM_APPEND_H
# define RIPPLE_PREPROCESSOR_ALGORITHM_APPEND_H
#
# include <ripple/algorithm/cast.h>
# include <ripple/config.h>
# include <ripple/control/iif.h>
# include <ripple/generics/core.h>
# include <ripple/limits.h>
# include <ripple/recursion/basic.h>
# include <ripple/recursion/expr.h>
#
# /* RPP_APPEND */
#
# define RPP_APPEND(g1, g2) RPP_APPEND_BYPASS(RPP_LIMIT_EXPR, g1, g2)
# define RPP_APPEND_ID() RPP_APPEND
#
# if CONFIG_RIPPLE_STD
# endif
#
# /* RPP_APPEND_BYPASS */
#
# define RPP_APPEND_BYPASS(s, g1, g2) \
    RPP_EXPR_S(s)(DETAIL_RPP_APPEND_I(RPP_OBSTRUCT(), RPP_PREV(s), g1, RPP_CAST_BYPASS(s, RPP_TYPEOF(g1), g2))) \
    /**/
# define RPP_APPEND_BYPASS_ID() RPP_APPEND_BYPASS
#
# if CONFIG_RIPPLE_STD
# endif
#
# define DETAIL_RPP_APPEND_INDIRECT() DETAIL_RPP_APPEND_I
# define DETAIL_RPP_APPEND_I(_, s, g1, g2) \
    RPP_IIF _(RPP_IS_CONS(g1))( \
        RPP_CONS _( \
            RPP_EXPR_S(s) _(DETAIL_RPP_APPEND_INDIRECT _()( \
                RPP_OBSTRUCT _(), RPP_PREV(s), RPP_TAIL _(g1), g2 \
            )), \
            RPP_HEAD _(g1) \
        ), \
        g2 \
    ) \
    /**/
#
# endif