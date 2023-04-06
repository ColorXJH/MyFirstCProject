//
// Created by ColorXJH on 2023-04-06.
// 使用memcpy()和memmove()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
void show_array(const int arr[],int n);

_Static_assert(sizeof (double )==2*sizeof (int),"double not twice int size");
int main(void){
    int values[SIZE]={1,2,3,4,5,6,7,8,9,10};
    int target[SIZE];
    double curious[SIZE / 2] = { 2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30 };
    puts("memcpy() used:");
    puts("values(original data):");
    show_array(values,SIZE);
    memcpy(target,values,SIZE*sizeof (int));
    puts("target(copy of values):");
    show_array(target,SIZE);
    puts("\nUsing memmove() with overlapping ranges:");
    memmove(values+2,values,5*sizeof (int));
    puts("values--element 0-4 copied to 2-6:");
    show_array(values,SIZE);
    puts("\nUsing memcpy() to copy double to int:");
    memcpy(target,curious,(SIZE/2)*sizeof (double ));
    //程序中最后一次调用 memcpy()从 double 类型数组中把数据拷贝到 int 类
    //型数组中，这演示了memcpy()函数不知道也不关心数据的类型，它只负责从
    //一个位置把一些字节拷贝到另一个位置（例如，从结构中拷贝数据到字符数
    //组中）。而且，拷贝过程中也不会进行数据转换
    puts("target---5 double into 10 int positions:");
    show_array(target,SIZE/2);
    show_array(target+5,SIZE/2);
    return 0;
}

void show_array(const int arr[],int n){
    for (int i = 0; i < n; ++i) {
        printf("%d",arr[i]);
        putchar('\n');
    }
}