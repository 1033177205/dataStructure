/**
  ******************************************************************************
  * @file    sstudent.c
  * @author  CGR
  * @version V1.0.0
  * @date    2018-9-22
  * @brief   用单链表来管理学生
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "slinklist_stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct sstudent
{
    char name[10];
    int age;
    struct single_linklist_node list;        //这是包含，也是一种继承
};

//初始化头指针，应该是循环链表
SLINKLIST_STACK_HEAD(sstudent_list);

/**
  * @brief  添加学生
  * @param  None
  * @retval None
  */
int sstudent_add(char *name, int age)
{
    //1.先分配内存
    struct sstudent *s = malloc(sizeof(struct sstudent));
    // printf("s = %p\n", s->list);
    if(s == NULL)
    {
        printf("student_add malloc error\n");
        return -1;
    }

    //初始化这个链表的节点
    INIT_SLINKLIST_STACK_NODE(&s->list);

    //初始化结构体其他成员
    strcpy(s->name, name);
    s->age = age;

    //添加链表,两个传参都要地址
    slinklist_stack_Push(&s->list, &sstudent_list);

    return 0;
}

/**
  * @brief  删除学生
  * @param  None
  * @retval None
  */
int sstudent_delete(void)
{
    struct single_linklist_node *plist;
    struct sstudent *s;  
        struct sstudent *pos;           

    plist = slinklist_stack_Pop(&sstudent_list);
    
    if(plist)
    {
        s = slinklist_stack_entry(plist, struct sstudent, list);    //通过链表指针地址推算回结构体的指针地址
        printf("s = %s %d\n", s->name, s->age);
        free(s);
    }
    return 0;
}

/**
  * @brief  遍历学生
  * @param  None
  * @retval None
  */
int sstudent_bianli(void)
{
    struct sstudent *s;
    slinklist_stack_for_each_entry(s, sstudent_list.top, list)        //这是把包含链表结构体的结构体指针
    {
        printf("s->name %s\r\n", s->name);
    }

    return 0;
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

/************************ (C) HOME 2018 深圳龙华 *****END OF FILE****/
