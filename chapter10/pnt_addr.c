//
// Created by ColorXJH on 2023-02-15.
// 指针地址，指针与数组的关系
#include <stdio.h>
#define SIZE 4
int main(void){
    short dates[SIZE];
    short * pti;
    short index;
    double bills[SIZE];
    double *ptf;
    pti=dates;//把数组地址赋值给指针
    ptf=bills;
    printf("%23s  %15s\n","short","double");
    //在我们的系统中，地址按字节编址，short类型占用两个字节，double类型占8个字节，在C中，指针加1指的是增加一个存储单元，
    //对数组而言，这意味着把下一个存储单元的地址是该地址，而不是下一个字节的地址，这也是必须声明指针所指向对象类型的原因之一，
    //只知道地址是不够的，还需要知道存储对象需要多少字节（即使指针指向的是标量变
    //量，也要知道变量的类型，否则*pt 就无法正确地取回地址上的值）
    for(index=0;index<SIZE;index++){
        printf("pointers +%d: %10p  %10p\n",index,pti+index,ptf+index);
    }
    int y=5;
    int dateww[4],*ps;
    ps=dateww;//ps=&date[0];
    printf("this address is same : %p     %p     %p\n",ps,dateww,&dateww[0]);
    int FLAG=(&dateww==&dateww[0]);//取址运算符
    int FLAG1=(&dateww==ps);//取址运算符 与指针对比
    printf("%d --- %d\n",FLAG,FLAG1);
    printf("%p\n",&dateww[0]);
    printf("%p\n",dateww);
    return 0;
}

