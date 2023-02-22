//
// Created by 金辉夏 on 2023/2/22.
// 数组元素只和，使用两个指针变量
#include <stdio.h>
# define SIZE 10
int sump(int *start,int *end);
int main(void){
    int members[SIZE]={20,30,10,12,23,12,4,34,4,6};
    long answer;
    //c保证在给数组分配空间时，指向数组后面第一个位置的指针仍然是有效的指针，这种越界指针调用更为简介
    //如果数组后面指定的是数组的最后一个元素，则需要使用sump(members,members+size-1)
    answer=sump(members,members+SIZE);
    printf("total number of members is %ld\n",answer);
    return 0;
}
int sump(int *start,int *end){
    int total=0;
    while(start<end){
        total+=*start;//把数组元素的值加起来
        start++;//让指针指向下一个元素
        //以上等价于:
        //total+=*start++;
        //以上表示*和++等级一致，但是结合率是从右往左，所以先操作++，然后操作*取值，
        //total=total+*start
        //start++

    }
    return total;
}

