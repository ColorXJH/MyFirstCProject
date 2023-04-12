//
// Created by ColorXJH on 2023-04-07.
// 简单链表类型的头文件

#ifndef MYFIRSTCPROJECT_LIST_H
#define MYFIRSTCPROJECT_LIST_H

#endif //MYFIRSTCPROJECT_LIST_H


#ifndef LSIT_H_
#define LIST_H_
#include <stdbool.h>
#define TSIZE 45
struct film{
    char title[TSIZE];
    int rating;
};
//定义一般类型
typedef struct film Item;
typedef struct node{
    Item item;
    struct node *next;
} Node;
typedef Node *List; //定义一个List变量,List实质上是一个结构类型指针
//函数原型
//统一使用List类型的地址作为参数，不使用List变量作为参数，以下所有函数均使用指针参数
/*
 * 操作：初始化一个链表
 * 前置条件：plist指向一个链表
 * 后置条件：链表初始化为空
 * */
void InitializeList(List *plist);//想要传递结构指针，不能指定结构名，需要在前面加上地址符&,  plist是Node(node)指针的指针
/*
 * 操作：确定链表是否为空，plist指向一个已经初始化的链表
 * 后置条件：如果链表为空，该函数返回true,否则返回false
 * */
bool ListIsEmpty(const List *plist);
/*
 * 操作：确定链表是否已满，plist指向一个已经初始化的链表
 * 后置条件：如果满则返回true,如果不满则返回false
 * */
bool ListIsFull(const List *plist);
/*
 * 操作：确定链表的项数，plist指向一个初始化的链表
 * 后置条件：该函数返回链表中的项数
 * */
unsigned int ListItemCount(const List *plist);
/*
 * 操作：在链表的末尾添加项，
 * 前置条件：item是一个待添加的项，plist是一个初始化的链表
 * 后置条件：如果可以，在链表末尾添加项，并且返回true,否则返回false
 * */
bool AddItem(Item item,List *plist);
/*
 * 操作：把函数作用于链表的每一项
 * 前置条件：plist指向一个初始化链表，pfun指向一个函数，该函数接受一个Item类型的参数且无返回值
 * 后置条件：pfun指向的函数作用于链表的每一项一次
 * */
void Traverse(const List *plist,void (*pfun)(Item item));//例如pfun可以指向显示列表项的函数
/* 操作：释放已分配的内存，如果有的话
 * 前置操作：plist指向一个初始化的链表
 * 后置条件：释放了为链表分配的所有内存，链表设置为空
 * */
void EmptyTheList(List *plist);
#endif


