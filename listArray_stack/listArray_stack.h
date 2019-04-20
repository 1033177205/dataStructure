/**
  ******************************************************************************
  * @file    listArray_static.h
  * @author  CGR
  * @version V1.0.0
  * @date    2018-10-6
  * @brief   数组实现的栈
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LISTARRAY_STATIC_H
#define __LISTARRAY_STATIC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "dataStruct_type.h"

/** @addtogroup DataStruct_Driver
  * @{
  */

/** @addtogroup listArray_stack
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup 数组实现栈的扩展类型
  * @{
  */ 

/** 
  * @brief 栈的数据类型
  */ 
typedef struct 
{
    uint8_t *buffer;                     /* 数据缓冲区 */
    len_t size;                          /* buffer的大小 */
    len_t item;                          /* 多少个条目 */
    len_t item_size;                     /* 一个条目的大小 */
    len_t top;                           /* 栈顶指针 */
}SqStack, *pSqStack;

/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/


/* Exported macro ------------------------------------------------------------*/
/**
 * @brief   初始化宏
 * @param   b:  栈的缓冲区地址
 * @param   n:	多少个条目
 * @param   ns:	一个条目的大小
 */
#define __listArray_stack_initializer(b, n, ns)                     \
	(SqStack) {                                                     \
		.size	= n * ns,                                           \
		.buffer = b,                                                \
        .top = -1,                                                   \
        .item = n,                                                  \
        .item_size = ns                                             \
	}

/**
 * @brief   声明栈的缓冲区
 * @param   name:	栈的名字
 * @param   size:   栈的大小
 * @note    
 */
#define DECLARE_LISTARRAY_STACK(name, item, item_size)              \
union {                                                             \
	SqStack name;                                                   \
	uint8_t name##SqStack_buffer[item*item_size + sizeof(SqStack)]; \
}

/**
 * @brief   初始化这个DECLARE_LISTARRAY_STACK宏定义的栈
 * @param   name:	栈的名字
 * @param   note:   name = (SqStack) {                              \
		.size	= item * item_size,     \   //大的结构体大小减去小的结构体大小就等于buffer的大小
		.buffer = name##SqStack_buffer + sizeof(SqStack)            \  //应为内存是要包括那个结构体的，所以buffer要偏移
        .top = 0,                                                   \
        .item = item,                                               \
        .item_size = item_size                                      \               
	}
 */
#define INIT_LISTARRAY_STACK(name, item, item_size)                 \
	name = __listArray_stack_initializer(name##SqStack_buffer + sizeof(SqStack), item, item_size)

/**
 * @brief   定义栈的缓冲区并初始化
 * @param   name:	栈的名字  直接写名字不需要用“”号
 * @param   size:   栈的大小
 * @note    DEFINE_KFIFO(name, item, item_size)
 *              unsigned char name##SqStack_buffer[item*item_size]; 
 *              SqStack name = (SqStack) {                          \
		        .size	= item * item_size,                         \
		        .buffer = name##SqStack_buffer                      \    
                .top = 0,                                           \
                .item = item,                                       \
                .item_size = item_size           
	}
 */
#define DEFINE_LISTARRAY_STACK(name, item, item_size)               \
	unsigned char name##SqStack_buffer[item*item_size];             \
	SqStack name = __listArray_stack_initializer(name##SqStack_buffer, item, item_size)

/* Exported functions --------------------------------------------------------*/ 
/* Initialization and de-initialization functions *******************************/
/** @addtogroup listArray_stack_Exported_Functions
  * @{
  */

/** @addtogroup listArray_stack_Exported_Functions_Group1
  * @{
  */
SqStack *listArray_stack_init(void *buffer, len_t item, len_t item_size);
SqStack *listArray_stack_alloc(len_t item, len_t item_size);
void listArray_stack_free(SqStack *stack);

/**
  * @}
  */

/* operation functions *******************************************************/
/** @addtogroup listArray_stack_Exported_Functions_Group2
  * @{
  */
void listArray_stack_print(SqStack *stack);
len_t listArray_stack_Push(SqStack *stack, const void *from, len_t len);
len_t listArray_stack_Pop(SqStack *stack, void *to, len_t len);
len_t listArray_stack_Pop_peek(SqStack *stack, void *to, len_t len);

/**
 * @brief   栈的重启
 * @param   name:	栈的名字
 * @param   size:   栈的大小
 * @retval  
 */
static inline void listArray_stack_reset(SqStack *stack)
{
	stack->top = -1;
}

/**
 * @brief   栈的大小
 * @param   stack:	栈的指针
 * @retval  栈的大小
 */
static inline len_t listArray_stack_size(SqStack *stack)
{
	return stack->size;
}

/**
 * @brief   栈使用的长度
 * @param   stack:	栈的指针
 * @retval  栈的使用长度
 */
static inline len_t listArray_stack_len(SqStack *stack)
{
	return stack->top;
}

/**
 * @brief   栈剩余的长度
 * @param   stack:	栈的指针
 * @retval  栈剩余长度
 */
static inline len_t listArray_stack_avail(SqStack *stack)
{
	return listArray_stack_size(stack) - listArray_stack_len(stack);
}

/**
 * @brief   栈顶指针向上增长
 * @param   stack:	栈的指针
 * @param   off:    偏移量
 * @retval  
 */
static inline void __listArray_stack_add_Push(SqStack *stack, len_t off)
{
	stack->top += off;
}

/**
 * @brief   栈顶指针向下增长
 * @param   stack:	栈的指针
 * @param   off:    偏移量
 * @retval  
 */
static inline void __listArray_stack_add_Pop(SqStack *stack, len_t off)
{
	stack->top -= off;
}

/**
 * @brief   判断栈是否为空
 * @param   stack:	栈的指针
 * @retval  
 */
static inline len_t listArray_stack_is_empty(SqStack *stack)
{
	return stack->top == -1;
}

/**
 * @brief   判断栈是否为满
 * @param   stack:	栈的指针
 * @retval  
 */
static inline len_t listArray_stack_is_full(SqStack *stack)
{
    return listArray_stack_size(stack) == listArray_stack_len(stack);
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

#endif /* __LISTARRAY_STATIC_H */

/******************* (C) HOME 2018 深圳龙华 *****END OF FILE****/
