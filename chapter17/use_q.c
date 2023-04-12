//
// Created by ColorXJH on 2023-04-10.
// 驱动程序测试Queue接口
#include <stdio.h>
#include "queue.c"
int main(void){
    Queue queue;
    Item temp;
    char ch;
    InitializeQueue(&queue);
    puts("testing the Queue interface,type a to add a value,");
    puts("type d to delete a value,and type q to quit.");
    while ((ch=getchar())!='q'){
        if(ch!='a'&&ch!='d'){
            continue;
        }
        if(ch=='a'){
            printf("integer to add: ");
            scanf("%d",&temp);
            if(!QueueIsFull(&queue)){
                printf("putting %d into queue\n",temp);
                EnQueue(temp,&queue);
            }else{
                printf("Queue is full!\n");
            }
        }else{
            if(QueueISEmpty(&queue)){
                puts("Nothing to delete!");
            }else{
                DeQueue(&temp,&queue);
                printf("removing %d from queue.\n",temp);
            }
        }
        printf("%d items in queue.\n", QueueItemCount(&queue));
        puts("Type　a　to　add,　d　to　delete,　q　to　quit:");
    }
    EmptyTheQueue(&queue);
    puts("bye!");
    return 0;
}
