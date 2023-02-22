//
// Created by 金辉夏 on 2023/2/22.
// 处理数组的函数
#include <stdio.h>
#define SIZE 5
void show_array(const double arr[],int n);
void mult_array(double array[],int n,double val);
int main(void){
    double dip[SIZE]={22.34,34.45,12.01,0.89,44,45};
    printf("the original dip array :\n");
    show_array(dip,SIZE);
    mult_array(dip,SIZE,2.5);
    printf("the dip array after calling multi_array():\n");
    show_array(dip,SIZE);
    return 0;
}
//显示数组内容
void show_array(const double  array[],int n){
    for(int i=0;i<n;i++){
        printf("%8.3f",array[i]);
    }
    putchar('\n');
}
//把数组的每个元素都乘以相同值
void mult_array(double array[],int n,double mult){
    for(int i=0;i<n;i++){
        array[i]*=mult;
    }
}
