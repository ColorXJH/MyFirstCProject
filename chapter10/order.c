//
// Created by 金辉夏 on 2023/2/22.
// 指针运算中的优先级
#include <stdio.h>
int data[2]={100,200};
int mData[2]={300,400};
int main(void){
    int *p1, *p2, *p3;
    p1=p2=data;
    p3=mData;
    printf("*p1=%d *p2=%d *p3=%d\n",*p1,*p2,*p3);//100,100,300
    printf("*p1++=%d,*++p2=%d,(*p3)++=%d\n",*p1++,*++p2,(*p3)++);//100,200,300
    printf("*p1=%d,*p2=%d,*p3=%d\n",*p1,*p2,*p3);//200,200,301
    return 0;
}


