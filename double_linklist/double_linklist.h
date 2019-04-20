/**
  ******************************************************************************
  * @file    double_linklist.h
  * @author  CGR
  * @version V1.0.0
  * @date    2018-10-5
  * @brief   双链表的实现
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DOUBLE_LINKLIST_H
#define __DOUBLE_LINKLIST_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "kernel.h"
#include "stdlib.h"

/** @addtogroup DataStruct_Driver
  * @{
  */

/** @addtogroup double_linklist
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup 单链表的头结点
  * @{
  */ 
struct double_linklist_head{
    struct double_linklist_head *prev;
    struct double_linklist_head *next;
};

/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/
#define DOUBLE_LINKLIST_HEAD_INIT(name) { &(name), &(name) }

//初始化头结点
#define DOUBLE_LINKLIST_HEAD(name) \
	struct double_linklist_head name = DOUBLE_LINKLIST_HEAD_INIT(name)

/* Exported functions --------------------------------------------------------*/

/**
  * @brief  初始化节点
  * @param  list : 链表节点
  * @retval None
  */
static inline void INIT_DOUBLE_LINKLIST_HEAD(struct double_linklist_head *list)
{
    list->prev = list;
	list->next = list;
}

/**
  * @brief  _添加链表节点
  * @param  newN : 链表新节点
  * @param  prev : 链表前一个节点
  * @param  next : 链表后一个节点
  * @retval None
  */
static inline void __doublelist_add(struct double_linklist_head *newN, struct double_linklist_head *prev, struct double_linklist_head *next)
{
    prev->next = newN;
    newN->prev = prev;
    newN->next = next;
    next->prev = newN;
}

/**
  * @brief  头插法
  * @param  newN : 新结点
  * @param  head : 链表的头节点
  * @retval None
  */
static inline void doublelist_add(struct double_linklist_head *newN, struct double_linklist_head *head)
{
    __doublelist_add(newN, head, head->next);
}

/**
  * @brief  尾插法
  * @param  newN : 新结点
  * @param  head : 链表头节点
  * @retval None
  */
static inline void doublelist_add_tail(struct double_linklist_head *newN, struct double_linklist_head *head)
{
    __doublelist_add(newN, head->prev, head);
}

/**
  * @brief  _删除节点
  * @param  prev : 要删除链表前一个节点
  * @param  next : 要删除链表后一个节点
  * @retval None
  */
static inline void _doublelist_del(struct double_linklist_head *prev, struct double_linklist_head *next)
{
    prev->next = next;
    next->prev = prev;
}

/**
  * @brief  删除节点
  * @param  entry : 要删除的节点
  * @retval None
  */
static inline void doublelist_del(struct double_linklist_head *entry)
{
    _doublelist_del(entry->prev, entry->next);
    entry->prev = NULL;
    entry->next = NULL;
}

/*
 * @brief  链表节点替换
 * @param  pos  : 前一个节点的指针
 * @param  head : 链表头节点
 * @retval None
 */
static inline void doublelist_replace(struct double_linklist_head *old, struct double_linklist_head *newN)
{
    newN->prev = old->prev;
    newN->next = old->next;
    newN->prev->next = newN;
    newN->next->prev = newN;    
}

static inline void doublelist_replace_init(struct double_linklist_head *old, struct double_linklist_head *newN)
{
	doublelist_replace(old, newN);
	INIT_DOUBLE_LINKLIST_HEAD(old);
}

/*
 * @brief  查看链表是否是最后一个节点
 * @param  list : 节点的指针
 * @retval None
 */
static inline int doublelist_is_last(const struct double_linklist_head *list, const struct double_linklist_head *head)
{
	return list->next == head;
}

/*
 * @brief  查看链表是否是空链表
 * @param  head : 链表头指针
 * @retval None
 */
static inline int list_empty(const struct double_linklist_head *head)
{
	return head->next == head;
}

/**
 * @brief   获取结构体条目
 * @param   ptr:	结构体成员的指针
 * @param   type:	结构体的类型
 * @param   member:	结构体的成员
 */
#define doublelist_entry(ptr, type, member) \
	container_of(ptr, type, member)

/**
 * @brief   继续迭代链表
 * @param   pos:	type *型的循环游标
 * @param   head:	链表头指针.这是循环链表，要判断等于头指针就结束
 * @param   member:	链表中的成员，其实就是list，这个只是遍历链表，找到每个list下的结构体指针
 * @param   note :  继续迭代给定类型的列表，继续当前位置。
 */
#define doublelist_for_each_entry(pos, head, member)				    \
	for (pos = doublelist_entry((head)->next, typeof(*pos), member);	\
	    &pos->member != (head); 	                            \
	    pos = doublelist_entry(pos->member.next, typeof(*pos), member))

/**
  * @}
  */

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* __DOUBLE_LINKLIST_H */

/******************* (C) HOME 2018 深圳龙华 *****END OF FILE****/
