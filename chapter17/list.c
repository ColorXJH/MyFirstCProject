//
// Created by ColorXJH on 2023-04-10.
// 实现list.h的接口，即实现List的接口，支持链表操作的一系列函数
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
//局部函数原型
static void CopyToNode(Item item,Node *pnode);
//接口函数(始终记住：plist就是头指针的地址，*plist就是头指针的值)
//把链表设置为空
void InitializeList(List *plist){
    *plist=NULL;
}
//如果链表为空，返回true
bool ListIsEmpty(const List *plist){
    if(*plist==NULL)
        return true;
    else
        return false;
}
//如果链表已满，返回true
bool ListIsFull(const List *plist){
    Node *pt;
    bool full;
    //对链表而言，链表的大小取决于可用内存量
    //尝试为新项分配空间
    pt=(Node*) malloc(sizeof (Node));
    //如果分配失败，说明链表已满；如果分配成功，则必须释放刚才分配的内存供真正的项所用
    //注意:这里并没有设定链表最多能存多少项，只是确定系统的内存空间是否够用
    if(pt==NULL){
        full=true;
    } else{
        full=false;
        free(pt);
    }
    return full;
}
//返回节点的数量
//const 表示 不改变*plist的值，即不改变指针plist所指向的值，但是他不保证*plist指向的数据是const,
//只保证plist指向的数据(*plist)为const,*plist指向的数据**plist(即：Node)的数据可以改变：
//如：Node.item.rating=3==》(*plist)->item.rating=3==>(**plist).item.rating=3
unsigned int ListItemCount(const List *plist){
    unsigned int count=0;
    Node *pnode=*plist;//设置链表的开始
    while (pnode!=NULL){
        ++count;
        pnode=pnode->next;//设置下一个节点
    }
    return count;
}
//创建存储项的节点，并将其添加至plist指向的链表末尾（较慢的实现）
bool AddItem(Item item,List *plist){
    Node *pnew;
    Node *scan=*plist;
    pnew=(Node*) malloc(sizeof (Node));
    if(pnew==NULL){
        return false;//失败时退出函数
    }
    CopyToNode(item,pnew);
    pnew->next=NULL;
    if(scan==NULL){
        //空链表，将pnew放在表头
        *plist=pnew;
    } else{
        while (scan->next!=NULL)
            scan=scan->next;//找到链表的末尾
        scan->next=pnew;//把pnew添加到链表末尾
    }
    return true;
}
//访问每个节点并主席那个pfun指向的函数
void Traverse(const List *plist,void (*pfun)(Item item)){
    Node *pnode=*plist;//设置链表的开始
    while (pnode!=NULL){
        (*pfun)(pnode->item);//把函数应用于链表的每一项
        pnode=pnode->next;//前进到下一项
    }
}
//释放malloc()分配的内存
//设置链表指针为NULL
void EmptyTheList(List *plist){
    Node  *psave;
    //当到达链表末尾时，*plist为NULL(*plist是指向Node的指针)，表明原始的实际参数现在被设为NULL
    while (*plist!=NULL){
        psave=(*plist)->next;//保存下一个节点的地址
        free(*plist);//释放当前节点
        *plist=psave;//前进到下一个节点
    }
}

//拷贝数据
static void CopyToNode(Item item,Node *pnode){
    pnode->item=item;//拷贝结构

}

