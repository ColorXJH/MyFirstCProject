//
// Created by ColorXJH on 2023-02-27.
// 处理二维数组的函数
#include <stdio.h>
#define  ROWS 3
#define COLS 4
void sum_rows(int arr[][COLS],int rows);//注意函数中指针数组声明形式，表明为指向列数组，则第二项为行数
void sum_cols(int[][COLS],int);//省略形参名
int sum2d(int (*arr)[COLS],int rows);//(*arr)==arr[]
//int sums(int arr[][],int rows);不正确 arr表示指向数组的指针，但是不知道数组的对象大小
//int sum2d(int (*arr)[COLS],int rows) 表示arr是一个指向内含4个int值的数组的指针 arr+1 表示该地址加上16字节
//int sum2(int ar[3][4], int rows); // 有效声明，但是3将被忽略
//与使用typedef相比，方便的多
typedef int arr4[4];//arr4是一个内含4个int的数组
typedef arr4 arr3[3];//arr3 是一个内含3个arr4的数组
//sumoo sumoo1 sumoo2 sumoo3等价
int sumoo(arr3,int rows);
int sumoo1(int arr[3][4],int rows);
int sum002(int arr[][4],int rows);
int sum003(int (*arr)[4],int rows);
int main(void){
    int junk[ROWS][COLS]={
        {2,4,6,8},
        {3,5,7,9},
        {12,10,8,6}
    };
    sum_rows(junk,ROWS);
    sum_cols(junk,ROWS);
    printf("sum of all element =%d\n", sum2d(junk,ROWS));
    return 0;
}

//统计行
void sum_rows(int arr[][COLS],int rows){
    int r, c,tot;
    for (int r = 0; r < rows; ++r) {
        tot=0;
        for (int c = 0; c < COLS; ++c) {
            tot+=arr[r][c];
        }
        printf("rows %d sum=%d\n",r,tot);
    }
}
//统计列
void sum_cols(int arr[][COLS],int rows){
    int r,c,tot;
    for (int c = 0; c <COLS ; ++c) {
        tot=0;
        for (int r = 0; r < rows; ++r) {
            tot+=arr[r][c];
        }
        printf("cols %d sums =%d\n",c,tot);
    }
}
//计算总和
int sum2d(int (*arr)[COLS],int rows){
    int r,c,tot;
    tot=0;
    for (int r = 0; r <rows ; ++r) {
        for (int c = 0; c <COLS ; ++c) {
            tot+=arr[r][c];
        }
    }
    printf("the sum of array is  %d\n",tot);
    return tot;
}
