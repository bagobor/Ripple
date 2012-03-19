/* 
 * File:   bind.h
 * Author: pfultz
 *
 * Created on January 20, 2012, 12:36 PM
 */

#ifndef BIND_H
#define	BIND_H

#define PX_BIND(m, ...) PX_BIND_NIL (m, __VA_ARGS__)

//Register BIND_INVOKE with INVOKE
#define PX_INVOKER_PX_BIND_NIL PX_INVOKER(PX_BIND_INVOKE_)

#define DETAIL_PX_BIND_INVOKE_M(b) PX_FIRST b
#define DETAIL_PX_BIND_INVOKE_ARGS(b) PX_TAIL b
//

#define PX_BIND_INVOKE_1(b, args) DETAIL_PX_INVOKE_MACRO_1(DETAIL_PX_BIND_INVOKE_M(b), DETAIL_PX_BIND_PLACE(args, DETAIL_PX_BIND_INVOKE_ARGS(b)))
#define PX_BIND_INVOKE_2(b, args) DETAIL_PX_INVOKE_MACRO_2(DETAIL_PX_BIND_INVOKE_M(b), DETAIL_PX_BIND_PLACE(args, DETAIL_PX_BIND_INVOKE_ARGS(b)))
#define PX_BIND_INVOKE_3(b, args) DETAIL_PX_INVOKE_MACRO_3(DETAIL_PX_BIND_INVOKE_M(b), DETAIL_PX_BIND_PLACE(args, DETAIL_PX_BIND_INVOKE_ARGS(b)))
#define PX_BIND_INVOKE_4(b, args) DETAIL_PX_INVOKE_MACRO_4(DETAIL_PX_BIND_INVOKE_M(b), DETAIL_PX_BIND_PLACE(args, DETAIL_PX_BIND_INVOKE_ARGS(b)))
#define PX_BIND_INVOKE_5(b, args) DETAIL_PX_INVOKE_MACRO_5(DETAIL_PX_BIND_INVOKE_M(b), DETAIL_PX_BIND_PLACE(args, DETAIL_PX_BIND_INVOKE_ARGS(b)))
#define PX_BIND_INVOKE_6(b, args) DETAIL_PX_INVOKE_MACRO_6(DETAIL_PX_BIND_INVOKE_M(b), DETAIL_PX_BIND_PLACE(args, DETAIL_PX_BIND_INVOKE_ARGS(b)))
#define PX_BIND_INVOKE_7(b, args) DETAIL_PX_INVOKE_MACRO_7(DETAIL_PX_BIND_INVOKE_M(b), DETAIL_PX_BIND_PLACE(args, DETAIL_PX_BIND_INVOKE_ARGS(b)))
#define PX_BIND_INVOKE_8(b, args) DETAIL_PX_INVOKE_MACRO_8(DETAIL_PX_BIND_INVOKE_M(b), DETAIL_PX_BIND_PLACE(args, DETAIL_PX_BIND_INVOKE_ARGS(b)))

#endif	/* BIND_H */

