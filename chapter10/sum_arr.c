//
// Created by ColorXJH on 2023-02-17.
// 数组元素之和
#include <stdio.h>
#define SIZE 10
int sum(int arr[],int n);
int main(void){
    int members[SIZE]={21,23,43,3,5,12,67,2,9,23};
    long answer;
    answer= sum(members,SIZE);
    //members的大小是40字节。这没问题，因为members内含10个int类型的值，
    //每个值占4字节，所以整个members的大小是40字节。但是，arr才8字节。
    //这是因为arr并不是数组本身，它是一个指向 members 数组首元素的指针,
    //我们的系统中用 8 字节储存地址，所以指针变量的大小是 8字节
    printf("the total of members is %ld\n",answer);
    printf("the size of members is %zd\n",sizeof members);
    return 0;
}

int sum(int arr[],int n){
    int i;int total=0;
    for(i=0;i<n;i++){
        total+=arr[i];
    }
    //变量地址的大小等价与指针大小（地址，指针类型8字节）
    printf("the size of arr is %zd bytes\n",sizeof arr);
    printf("the size of &n(== *point) is %zd bytes\n",sizeof &n);
    //实际变量存储值的大小（int类型4字节）
    printf("the size of n is %zd bytes\n",sizeof n);
    return total;
}

