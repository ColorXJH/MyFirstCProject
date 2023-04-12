//
// Created by ColorXJH on 2023-04-10.
//
#include <stdio.h>
#include <stdlib.h>
#include "queue2.h"
//局部函数
static void CopyToNode(Item item,Node *pn);
static void CopyToItem(Node *pn,Item *pi);
//初始化，置空
void InitializeQueue(Queue *pq){
    pq->front=pq->rear=NULL;
    pq->items=0;
}

bool QueueIsFull(const Queue *pq){
    return pq->items==MAXQUQUE;
}

bool QueueISEmpty(const Queue *pq){
    return pq->items==0;
}

int QueueItemCount(const Queue *pq){
    return pq->items;
}
//入队
bool EnQueue(Item item,Queue *pq){
    Node *pnew;
    //判断是否满了
    if(QueueIsFull(pq)){
        return false;
    }
    //尝试分配内存
    pnew=(Node *) malloc(sizeof (Node));
    //分配不到显示内存不够
    if(pnew==NULL){
        fprintf(stderr,"Unable to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    //将内容赋值到新节点
    CopyToNode(item,pnew);
    //新节点后一个节点置为NULL
    pnew->next=NULL;
    //队列空，则新节点为头节点
    if(QueueISEmpty(pq)){
        pq->front=pnew;
    }else{
        pq->rear->next=pnew;//链接到队列的尾端
    }
    pq->rear=pnew;//记录新的队列尾端的位置（先当与移动到新的pnew节点上，队医上一行相当于后移一位）
    pq->items++;
    return true;
}
//出队
bool DeQueue(Item *item,Queue *pq){
    Node *pt;//存储待删除的节点的位置，front一直被替换为指向下一个节点，如果没有这个临时节点，则不知道该释放那块内存
    //判断是否为空
    if(QueueISEmpty(pq)){
        return false;
    }
    //将值赋值给item
    CopyToItem(pq->front,item);
    //节点指针指向出队队头，以便后面回收
    pt=pq->front;
    //设置队头为后一个元素,
    //注意：当删除最后一项时，会隐式的将font设置为NULL,因为rear.next=NULL,则pq->font=pq->font->next==>rear.next==>NULL
    pq->front=pq->front->next;
    //回收节点引用的内存
    free(pt);
    //项数减1
    pq->items--;
    //如果项数变为0则让尾指针置空
    if(pq->items==0){
        pq->rear==NULL;
    }
    return true;
}
//清空队列（循环调用出队，并且释放内存）
void EmptyTheQueue(Queue *pq){
    Item dummy;
    while (!QueueISEmpty(pq)){
        DeQueue(&dummy,pq);
    }
}

//局部函数
static void CopyToNode(Item item,Node *pn){
    pn->item=item;
}
static void CopyToItem(Node *pn,Item *pi){
    *pi=pn->item;
}

