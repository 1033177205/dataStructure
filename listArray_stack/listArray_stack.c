/**
  ******************************************************************************
  * @file    listArray_stack.c
  * @author  CGR
  * @version V1.0.0
  * @date    2018-10-6
  * @brief   用数组实现栈
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "listArray_stack.h"

/** @addtogroup DataStruct_Driver
  * @{
  */

/** @addtogroup listArray_stack
  * @{
  */

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/


/** @defgroup listArray_stack_Exported_Functions listArray_stack Exported Functions
  * @{
  */

/** @defgroup listArray_stack_Exported_Functions_Group1 Initialization and deinitialization functions
 *  @brief    Initialization and Configuration functions
 *
@verbatim    
 ===============================================================================
              ##### Initialization and deinitialization functions #####
 ===============================================================================
  [..]
    This section provides functions allowing to initialize and de-initialize the listArray
    to be ready for use.
 
@endverbatim
  * @{
  */

/**
  * @brief  内部初始化栈
  * @param  stack  : 栈数据结构的指针
  * @param  buffer : 缓冲区
  * @param  size   : 缓冲区的大小
  * @retval 
  */ 
static void _listArray_stack_init(SqStack *stack, void *buffer, len_t item, len_t item_size)
{
	stack->buffer = buffer;
    stack->item = item;
    stack->item_size = item_size;
	stack->size = item_size * item;

	listArray_stack_reset(stack);
}

/**
  * @brief  初始化栈并使用外部buffer
  * @param  buffer : 缓冲区
  * @param  size   : 缓冲区的大小
  * @retval 栈的指针
  */ 
SqStack *listArray_stack_init(void *buffer, len_t item, len_t item_size)
{
    SqStack *stack = NULL;

    stack = (SqStack *)malloc(sizeof(SqStack));
    if(stack == NULL)
    {
        return NULL;
    }

    _listArray_stack_init(stack, buffer, item, item_size);
    return stack;
}

/**
  * @brief  初始化栈并申请内存
  * @param  item        :   多少个条目
  * @param  item_size   :   一个条目的大小  整体的size = item * item_size;
  * @retval 栈的指针
  */ 
SqStack *listArray_stack_alloc(len_t item, len_t item_size)
{
    SqStack *stack = NULL;
	uint8_t *buffer;

    stack = (SqStack *)malloc(sizeof(SqStack));
    if(stack == NULL) {
        printf("stack\n");
        return NULL;
    }

	buffer = malloc(item * item_size);
	if (!buffer) {
		_listArray_stack_init(stack, NULL, 0, 0);
        free(stack);
		return NULL;
	}

	_listArray_stack_init(stack, buffer, item, item_size);

	return stack;
}

/**
  * @brief  释放stack的内部缓冲区
  * @param  stack  : 要释放的栈
  * @retval 
  */ 
void listArray_stack_free(SqStack *stack)
{
	free(stack->buffer);
	_listArray_stack_init(stack, NULL, 0, 0);
}

/**
  * @}
  */

/** @defgroup listArray_stack_Exported_Functions_Group2 operation functions 
 *  @brief   operation functions
 *
@verbatim   
 ===============================================================================
                       ##### operation functions #####
 ===============================================================================
  [..]
    This subsection provides a set of functions allowing to manage the listArray.

@endverbatim
  * @{
  */

/**
  * @brief  把入栈的数据拷贝进来
  * @param  stack  : 要释放的栈
  * @param  from   : 数据缓冲区
  * @param  len    : 长度
  * @retval 
  */ 
static inline void __listArray_stack_Push_data(SqStack *stack, const void *from, len_t len)
{
	memcpy(stack->buffer + stack->top, from, len);
}

/**
  * @brief  把出栈的数据拷贝出去
  * @param  stack  : 要释放的栈
  * @param  to     : 数据缓冲区
  * @param  len    : 长度
  * @retval 
  */ 
static inline void __listArray_stack_Pop_data(SqStack *stack, void *to, len_t len)
{
	memcpy(to, stack->buffer + stack->top - len, len);
}

/**
  * @brief  入栈
  * @param  stack  : 要添加的栈
  * @param  from   : 复制的数据
  * @param  len    : 长度
  * @retval 
  */ 
len_t listArray_stack_Push(SqStack *stack, const void *from, len_t len)
{
    /* 要判断参数是否合理 */
    if(listArray_stack_avail(stack) < len)
    {
        return -DS_RAM_FULL;
    }

    if(stack->item_size < len)
    {
        return DS_PARM_ERROR;
    }

	__listArray_stack_Push_data(stack, from, len);
	__listArray_stack_add_Push(stack, len);
	return len;
}

/**
  * @brief  出栈
  * @param  stack  : 要添加的栈
  * @param  to     : 复制的数据
  * @param  len    : 长度
  * @retval 
  */ 
len_t listArray_stack_Pop(SqStack *stack, void *to, len_t len)
{
	if(listArray_stack_len(stack) < len)
    {
        return -DS_PARM_ERROR;
    }

    if(stack->item_size < len)
    {
        return DS_PARM_ERROR;
    }

	__listArray_stack_Pop_data(stack, to, len);
	__listArray_stack_add_Pop(stack, len);

	return len;
}

/**
  * @brief  窥视栈的数据
  * @param  stack  : 要添加的栈
  * @param  to     : 复制的数据
  * @param  len    : 长度
  * @retval 
  */ 
len_t listArray_stack_Pop_peek(SqStack *stack, void *to, len_t len)
{
	if(listArray_stack_len(stack) < len)
    {
        return -DS_PARM_ERROR;
    }

    if(stack->item_size < len)
    {
        return DS_PARM_ERROR;
    }

	__listArray_stack_Pop_data(stack, to, len);

	return len;
}

/**
  * @brief  打印数据，调试使用
  * @param  stack  : 栈指针
  * @retval 
  */ 
void listArray_stack_print(SqStack *stack)
{
    int i = 0;
    for(i=0; i<stack->top; i+=4)
    {
        printf("buffer = %d\r\n", *(int *)(stack->buffer+i));
    }
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

/************************ (C) HOME 2018 深圳龙华 *****END OF FILE****/
