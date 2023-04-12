//
// Created by ColorXJH on 2023-04-10.
// Queue的接口

#ifndef MYFIRSTCPROJECT_QUEUE_H
#define MYFIRSTCPROJECT_QUEUE_H

#endif //MYFIRSTCPROJECT_QUEUE_H

//定义开始
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>
//在这里插入Item类型的定义，例如
typedef int Item;
#define MAXQUQUE 10
typedef struct node{
    Item item;
    struct node *next;
}Node;
typedef struct queue{
    Node *front;//指向队列首项的指针
    Node *rear;//指向队列尾项的指针
    int items;//队列中的项数
}Queue;
void InitializeQueue(Queue *pq);
bool QueueIsFull(const Queue *pq);
bool QueueISEmpty(const Queue *pq);
int QueueItemCount(const Queue *pq);
bool EnQueue(Item item,Queue *pq);
bool DeQueue(Item *item,Queue *pq);
void EmptyTheQueue(Queue *pq);
#endif
