//
// Created by ColorXJH on 2023-03-10.
// 与rand0一起编译
#include <stdio.h>
#include <time.h>
#include "rand0.c"
extern void srand(unsigned int x);
extern unsigned int rand0(void);
int main(void){
    int count;
    unsigned int seed;
    printf("please enter your chioce for seed:\n");
    while (scanf("%d",&seed)==1){
        //也可以恩据日期时间函数自动获取种子 srand((unsigned int)time(0));
        //一般而言，time()接受的参数是一个 time_t 类型对象的地址，而时间值
        //就储存在传入的地址上。当然，也可以传入空指针（0）作为参数，这种情
        //况下，只能通过返回值机制来提供值。
        //srand((unsigned int)time(0));
        srand(seed);//重置种子
        for ( count = 0; count<5 ; count++) {
            printf("%d\n",rand0());
        }
        printf("please enter next seed(q to quit):\n");
    }
    printf("done!\n");
    return 0;
}

