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
# ifndef RIPPLE_PREPROCESSOR_SEQ_REMOVE_H
# define RIPPLE_PREPROCESSOR_SEQ_REMOVE_H
#
# include <ripple/arithmetic/inc.h>
# include <ripple/config.h>
# include <ripple/seq/drop.h>
# include <ripple/seq/take.h>
#
# /* RPP_SEQ_REMOVE */
#
# define RPP_SEQ_REMOVE(i, seq) \
    RPP_SEQ_TAKE(i, seq) RPP_SEQ_DROP(RPP_INC(i), seq) \
    /**/
# define RPP_SEQ_REMOVE_ID() RPP_SEQ_REMOVE
#
# if CONFIG_RIPPLE_STD
# endif
#
# endif