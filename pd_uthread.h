#ifndef PD_UTHREAD_H_
#define PD_UTHREAD_H_

#include "pd_define.h"

PD_CPP_START

struct PdUThreadMgr;
struct PdUThreadNode;

typedef void *(*pd_uthread_func_pt) (struct PdUThreadNode*, void*);

////////////////////////////////////////////////////////////////////////////////////////////////////
extern struct PdUThreadNode *getPdUThreadMgr_ready_list_head(struct PdUThreadMgr *uthread_mgr);

extern struct PdUThreadMgr *pd_uthread_init_mgr();

extern void pd_uthread_destroy_mgr(struct PdUThreadMgr *uthread_mgr);

extern struct PdUThreadNode *pd_uthread_init_node(struct PdUThreadMgr *uthread_mgr, pd_uthread_func_pt uthread_func, void *uthread_arg);

extern void pd_uthread_destroy_node(struct PdUThreadNode *uthread_node);

////////////////////////////////////////////////////////////////////////////////////////////////////

extern void pd_uthread_schedule(struct PdUThreadMgr *uthread_mgr);
//返回值 1--还有任务, 0--没有任务
extern int pd_uthread_scheduleII(struct PdUThreadMgr *uthread_mgr);

extern void pd_uthread_yield(struct PdUThreadNode *uthread_node, const int ready);

extern void pd_uthread_wakeup(struct PdUThreadNode *uthread_node);

extern void pd_uthread_exit(struct PdUThreadNode *uthread_node);

PD_CPP_END

#endif

