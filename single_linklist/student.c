/**
  ******************************************************************************
  * @file    student.c
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
#include "single_linklist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct student
{
    char name[10];
    int age;
    struct single_linklist_node list;        //这是包含，也是一种继承
};

//初始化头指针，应该是循环链表
SINGLE_LINKLIST_HEAD(student_list);

/**
  * @brief  添加学生
  * @param  None
  * @retval None
  */
int student_add(char *name, int age)
{
    //1.先分配内存
    struct student *s = malloc(sizeof(struct student));

    if(s == NULL)
    {
        printf("student_add malloc error\n");
        return -1;
    }

    //初始化这个链表的节点
    INIT_SINGLE_LINKLIST_NODE(&s->list);

    //初始化结构体其他成员
    strcpy(s->name, name);
    s->age = age;

    //添加链表,两个传参都要地址
    //singlelist_add(&s->list, &student_list);
    singlelist_add_tail(&s->list, &student_list);

    return 0;
}

/**
  * @brief  删除学生
  * @param  None
  * @retval None
  */
int student_delete(char *name)
{
    struct student *s;
    struct single_linklist_node *list = student_list.next;                   
    singlelist_for_each_entry(s, &student_list, list)        //这是把包含链表结构体的结构体指针
    {
        //printf("s->name %s\r\n", s->name);
        if(strcmp(s->name, name) == 0)
        {
            if(&s->list == student_list.next)
            {
               singlelist_del(&student_list, &student_list);
            }
            else
            {
                singlelist_del(list, &student_list);
            }
            free(s);
            return 0;
        }
        list = &s->list;
    }
    return -1;
}

/**
  * @brief  替换学生
  * @param  None
  * @retval None
  */
int student_replace(char *old_name, char *new_name, int new_age)
{
    struct student *s;
    struct single_linklist_node *list = student_list.next;    

    struct student *s_n = malloc(sizeof(struct student));
    //初始化这个链表的节点
    INIT_SINGLE_LINKLIST_NODE(&s_n->list);

    //初始化结构体其他成员
    strcpy(s_n->name, new_name);
    s_n->age = new_age;

    singlelist_for_each_entry(s, &student_list, list)        //这是把包含链表结构体的结构体指针
    {
        //printf("s->name %s\r\n", s->name);
        if(strcmp(s->name, old_name) == 0)
        {
            if(&s->list == student_list.next)
            {
               singlelist_replace(&student_list, &s_n->list, &student_list);
            }
            else
            {
                singlelist_replace(list, &s_n->list, &student_list);
            }
            free(s);
            return 0;
        }
        list = &s->list;
    }
    return -1;
}

/**
  * @brief  遍历学生
  * @param  None
  * @retval None
  */
int student_bianli(void)
{
    struct student *s;
    singlelist_for_each_entry(s, &student_list, list)        //这是把包含链表结构体的结构体指针
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
