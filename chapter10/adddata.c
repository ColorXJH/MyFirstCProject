//
// Created by 金辉夏 on 2023/2/22.
// 为数组增加数据
#include <stdio.h>
void add_to(int arr[],int c ,int b);
void myPrint(int arr[],int n);
int main(void){
    int arrs[100]={0};
    add_to(arrs,sizeof(arrs)/sizeof(arrs[0]),2);
    myPrint(arrs,sizeof(arrs)/sizeof(arrs[0]));
    return 0;
}
void add_to(int arr[],int n,int value){
    for(int i=0;i<n;i++){
        arr[i]=arr[i]+value;
    }
}
//因为arrs 对于编译器，也是数组的名称。这是某种特殊的指针。它不是左值：您不能为其分配其他地址；它会始终在其范围内引用该数组。
//arr只是一个指针。编译器知道它指向一个数组（在这种情况下），但是不知道有多少个整数。此外，它是一个有效的左值：您可以为其分配一个新值。
void myPrint(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("this is %d\n",arr[i]);
    }
}

//c语言指针读取数组长度,如何从C中的指针获取数组的大小？
//不，没有办法获得这些信息

