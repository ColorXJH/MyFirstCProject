//
// Created by ColorXJH on 2023-02-14.
// 使用指针解决交换函数的问题
#include <stdio.h>
void interChange(int*u,int*v);
int main(void){
    int x=5,y=10;
    printf("original x=%d and y=%d\n",x,y);
    //一般而言，可以办变量相关的两类信息传递给函数，一类是值，一类是地址  function(x),function(&x)
    //第一种类型要求函数形参是变量 int function(int num),第二种类型要求函数形参为指向正确类型的指针 int function(int *x)
    //如果要计算或处理值，那么使用第 1 种形式的函数调用；如果要在被调函数中改变主调函数的变量，则使用第2种形式的函数调用
    //指针让interchange()函数通过自己的局部变量改变main()变量的值
    interChange(&x,&y);
    printf("now x=%d an y=%d\n",x,y);
    return 0;
}


//将内存地址传递过来，函数使用指针类型接收，x,y表示指向int类型的指针变量，声明的时候表示为一个指针 int *x,int *y
//u,v(指针)即为 &x,&y内存地址（u,v即指向x,y变量的内存地址）  *u,*v即为内存地址对应的原始数据的值(*u,*v即指向x,y对应的值)
void interChange(int*u,int*v){
    int temp;
    temp=*u;//temp获得u所指向对象的值
    *u=*v;//将v指针指向的内存地址上的数据值赋值给u指针指向的内存地址上的数据
    *v=temp;
}

