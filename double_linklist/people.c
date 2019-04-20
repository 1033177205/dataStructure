/**
  ******************************************************************************
  * @file    people.c
  * @author  CGR
  * @version V1.0.0
  * @date    2018-10-6
  * @brief   用双链表来管理人
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "double_linklist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct people
{
    char name[10];
    int age;
    struct double_linklist_head list;        //这是包含，也是一种继承
};

//初始化头指针，应该是循环链表
DOUBLE_LINKLIST_HEAD(people_list);

/**
  * @brief  添加人
  * @param  None
  * @retval None
  */
int people_add(char *name, int age)
{
    //1.先分配内存
    struct people *s = malloc(sizeof(struct people));

    if(s == NULL)
    {
        printf("people_add malloc error\n");
        return -1;
    }

    //初始化这个链表的节点
    INIT_DOUBLE_LINKLIST_HEAD(&s->list);

    //初始化结构体其他成员
    strcpy(s->name, name);
    s->age = age;

    //添加链表,两个传参都要地址
    // doublelist_add(&s->list, &people_list);
    doublelist_add_tail(&s->list, &people_list);

    return 0;
}

/**
  * @brief  删除学生
  * @param  None
  * @retval None
  */
int people_delete(char *name)
{
    struct people *s;            
    doublelist_for_each_entry(s, &people_list, list)        //这是把包含链表结构体的结构体指针
    {
        if(strcmp(s->name, name) == 0)
        {
            doublelist_del(&s->list);
            free(s);
            return 0;
        }
    }
    return -1;
}

/**
  * @brief  替换学生
  * @param  None
  * @retval None
  */
int people_replace(char *old_name, char *new_name, int new_age)
{
    struct people *s;

    struct people *s_n = malloc(sizeof(struct people));
    //初始化这个链表的节点
    INIT_DOUBLE_LINKLIST_HEAD(&s_n->list);

    //初始化结构体其他成员
    strcpy(s_n->name, new_name);
    s_n->age = new_age;

    doublelist_for_each_entry(s, &people_list, list)        //这是把包含链表结构体的结构体指针
    {
        //printf("s->name %s\r\n", s->name);
        if(strcmp(s->name, old_name) == 0)
        {
            doublelist_replace_init(&s->list, &s_n->list);
            free(s);
            return 0;
        }
    }
    return -1;
}

/**
  * @brief  遍历学生
  * @param  None
  * @retval None
  */
int people_bianli(void)
{
    struct people *s;
    doublelist_for_each_entry(s, &people_list, list)        //这是把包含链表结构体的结构体指针
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
