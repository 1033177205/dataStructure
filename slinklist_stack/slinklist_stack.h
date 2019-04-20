/**
  ******************************************************************************
  * @file    slinklist_stack.h
  * @author  CGR
  * @version V1.0.0
  * @date    2018-10-21
  * @brief   链表实现的栈
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SLINKLIST_STATIC_H
#define __SLINKLIST_STATIC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "dataStruct_type.h"
#include "single_linklist.h"
#include "kernel.h"

/** @addtogroup DataStruct_Driver
  * @{
  */

/** @addtogroup slinklist_stack
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup 链表实现栈的扩展类型
  * @{
  */ 

/** 
  * @brief 栈的数据类型
  */ 
typedef struct 
{
    struct single_linklist_node *top;               /* 栈顶指针 */
    len_t size;                                     /* 栈的长度 */
}SlinkStack, *pSlinkStack;


/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/
#define SLINKLIST_STACK_HEAD_INIT(name) { NULL, 0 }

//初始化头结点
#define SLINKLIST_STACK_HEAD(name) \
	SlinkStack name = SLINKLIST_STACK_HEAD_INIT(name)


/* Exported functions --------------------------------------------------------*/ 
/* Initialization and de-initialization functions *******************************/
/** @addtogroup slinklist_stack_Exported_Functions
  * @{
  */

/** @addtogroup slinklist_stack_Exported_Functions_Group1
  * @{
  */

/**
  * @brief  初始化节点
  * @param  list : 链表节点
  * @retval None
  */
static inline void INIT_SLINKLIST_STACK_NODE(struct single_linklist_node *list)
{
	list->next = NULL;
}

/**
  * @}
  */

/* operation functions *******************************************************/
/** @addtogroup slinklist_stack_Exported_Functions_Group2
  * @{
  */

/**
  * @brief  入栈
  * @param  newN : 新结点
  * @param  stack : 栈的头指针
  * @retval None
  */
static inline void slinklist_stack_Push(struct single_linklist_node *newN, SlinkStack *stack)
{
    newN->next = stack->top;
    stack->top = newN;
    stack->size++;
}

/**
  * @brief  出栈
  * @param  stack : 栈的头指针
  * @retval 栈顶指针
  */
static inline SlinkStack *slinklist_stack_Pop(SlinkStack *stack)
{
    SlinkStack *stack_Pop = NULL;
    if(stack->top)
    {
        stack_Pop = stack->top;
        stack->top = stack->top->next;
        stack->size--;
    }  
    return stack_Pop;
}

/**
  * @brief  窥视栈的数据
  * @param  stack : 栈的头指针
  * @retval 栈顶指针
  */
static inline SlinkStack *slinklist_stack_Pop_peek(SlinkStack *stack)
{
    SlinkStack *stack_Pop = NULL;
    if(stack->top)
    {
        stack_Pop = stack->top;
    }  
    return stack_Pop;
}

/**
 * @brief   获取结构体条目
 * @param   ptr:	结构体成员的指针
 * @param   type:	结构体的类型
 * @param   member:	结构体的成员
 */
#define slinklist_stack_entry(ptr, type, member) \
	container_of(ptr, type, member)

/**
 * @brief   从头迭代链表
 * @param   pos:	type *型的循环游标
 * @param   head:	链表头指针.这是循环链表，要判断等于头指针就结束
 * @param   member:	链表中的成员，其实就是list，这个只是遍历链表，找到每个list下的结构体指针
 * @param   note:   for (pos = singlelist_entry((head)->next, typeof(*pos), member); &pos->member != (head); pos = singlelist_entry(pos->member.next, typeof(*pos), member))
 */
#define slinklist_stack_for_each_entry(pos, head, member)				\
	for (pos = slinklist_stack_entry((head), typeof(*pos), member);	\
	     &pos->member != NULL; 	\
	     pos = slinklist_stack_entry(pos->member.next, typeof(*pos), member))

/**
 * @brief   栈使用的长度
 * @param   stack:	栈的指针
 * @retval  栈的使用长度
 */
static inline len_t slinklist_stack_len(SlinkStack *stack)
{
	return stack->size;
}

/**
 * @brief   判断栈是否为空
 * @param   stack:	栈的指针
 * @retval  
 */
static inline len_t slinklist_stack_is_empty(SlinkStack *stack)
{
	return stack->size == 0;
}

/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* __SLINKLIST_STATIC_H */

/******************* (C) HOME 2018 深圳龙华 *****END OF FILE****/
