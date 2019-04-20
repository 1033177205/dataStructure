/**
  ******************************************************************************
  * @file    single_linklist.h
  * @author  CGR
  * @version V1.0.0
  * @date    2018-9-16
  * @brief   单链表的实现
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SINGLE_LINKLIST_H
#define __SINGLE_LINKLIST_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "kernel.h"
#include "stdlib.h"

/** @addtogroup DataStruct_Driver
  * @{
  */

/** @addtogroup single_linklist
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup 单链表的头结点
  * @{
  */ 
struct single_linklist_head{
    struct single_linklist_node *prev;          //指向前一个结点
    struct single_linklist_node *next;          //指向链表的下一结点
};

/** @defgroup 单链表的数据类型
  * @{
  */ 
struct single_linklist_node{
    struct single_linklist_node *next;       //指向链表的下一结点
};

/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/
#define SINGLE_LINKLIST_HEAD_INIT(name) { NULL, NULL }

//初始化头结点
#define SINGLE_LINKLIST_HEAD(name) \
	struct single_linklist_head name = SINGLE_LINKLIST_HEAD_INIT(name)

/* Exported functions --------------------------------------------------------*/

/**
  * @brief  初始化节点
  * @param  list : 链表节点
  * @retval None
  */
static inline void INIT_SINGLE_LINKLIST_NODE(struct single_linklist_node *list)
{
	list->next = NULL;
}

/**
  * @brief  头插法
  * @param  newN : 新结点
  * @param  head : 链表的头节点
  * @retval None
  */
static inline void singlelist_add(struct single_linklist_node *newN, struct single_linklist_head *head)
{
    newN->next = head->next;
    head->next = newN;
}

/**
  * @brief  尾插法
  * @param  newN : 新结点
  * @param  head : 链表头节点
  * @retval None
  */
static inline void singlelist_add_tail(struct single_linklist_node *newN, struct single_linklist_head *head)
{
	//__list_add(newN, head->prev, head);
    (head->prev) ? ( head->prev->next = newN) : (head->next = newN);  
    head->prev = newN;
}

/*
 * @brief  链表节点删除
 * @param  pos  : 前一个节点的指针
 * @param  head : 链表头节点
 * @retval None
 */
#define singlelist_del(p_prev, head) ({		       \
	(p_prev)->next = (p_prev)->next->next;         \
    if(!(p_prev)->next)                            \
        (head)->prev = (struct single_linklist_node *)p_prev; })
// static inline void singlelist_del(struct single_linklist_node * prev, struct single_linklist_head *head)
// {
//     prev->next = prev->next->next;
//     if(!prev->next)            //如果是最后一个节点
//     {
//         head->prev = prev;
//     }
// }

/*
 * @brief  链表节点替换
 * @param  pos  : 前一个节点的指针
 * @param  head : 链表头节点
 * @retval None
 */
#define singlelist_replace(old_prev, newN, head) ({		    \
    (newN)->next = (old_prev)->next->next;                  \
    (old_prev)->next = newN;                                \
    if(!(newN)->next)                                       \
        (head)->prev = (struct single_linklist_node *)newN; })

/*
 * @brief  查看链表是否是最后一个节点
 * @param  list : 节点的指针
 * @retval None
 */
static inline int singlelist_is_last(const struct single_linklist_node *list)
{
	return list->next == NULL;
}

/*
 * @brief  查看链表是否是空链表
 * @param  head : 链表头指针
 * @retval None
 */
static inline int singlelist_empty(const struct single_linklist_head *head)
{
	return head->next == NULL;
}

/**
 * @brief   获取结构体条目
 * @param   ptr:	结构体成员的指针
 * @param   type:	结构体的类型
 * @param   member:	结构体的成员
 */
#define singlelist_entry(ptr, type, member) \
	container_of(ptr, type, member)

/**
 * @brief   获取第一个元素
 * @param   ptr:	元素的头
 * @param   type:	结构体的类型
 * @param   member: 结构体的成员
 * @param   note : 该链表默认不为空
 */
#define singlelist_first_entry(ptr, type, member) \
	singlelist_entry((ptr)->next, type, member)

/**
 * @brief   迭代链表
 * @param   pos:	循环的游标
 * @param   head:   链表头节点
 */
#define singlelist_for_each(pos, head) \
	for (pos = (head)->next; pos != NULL; pos = pos->next)

/**
 * @brief   从头迭代链表
 * @param   pos:	type *型的循环游标
 * @param   head:	链表头指针.这是循环链表，要判断等于头指针就结束
 * @param   member:	链表中的成员，其实就是list，这个只是遍历链表，找到每个list下的结构体指针
 * @param   note:   for (pos = singlelist_entry((head)->next, typeof(*pos), member); &pos->member != (head); pos = singlelist_entry(pos->member.next, typeof(*pos), member))
 */
#define singlelist_for_each_entry(pos, head, member)				\
	for (pos = singlelist_entry((head)->next, typeof(*pos), member);	\
	     &pos->member != NULL; 	\
	     pos = singlelist_entry(pos->member.next, typeof(*pos), member))

/**
 * @brief   继续迭代链表
 * @param   pos:	type *型的循环游标
 * @param   head:	链表头指针.这是循环链表，要判断等于头指针就结束
 * @param   member:	链表中的成员，其实就是list，这个只是遍历链表，找到每个list下的结构体指针
 * @param   note : 继续迭代给定类型的列表，继续当前位置。
 */
#define singlelist_for_each_entry_continue(pos, head, member) 		\
	for (pos = singlelist_entry(pos->member.next, typeof(*pos), member);	\
	    &pos->member != NULL;	\
	    pos = singlelist_entry(pos->member.next, typeof(*pos), member))

/**
 * @brief   从当前点迭代给定类型的列表
 * @param   pos:	type *型的循环游标
 * @param   head:	链表头指针.这是循环链表，要判断等于头指针就结束
 * @param   member:	链表中的成员，其实就是list，这个只是遍历链表，找到每个list下的结构体指针
 * @param   note : 迭代给定类型的列表，从当前位置继续。
 */
#define singlelist_for_each_entry_from(pos, head, member) 			\
	for (; &pos->member != NULL;	\
	     pos = singlelist_entry(pos->member.next, typeof(*pos), member))


/**
  * @}
  */

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* __SINGLE_LINKLIST_H */

/******************* (C) HOME 2018 深圳龙华 *****END OF FILE****/
