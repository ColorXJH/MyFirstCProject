//
// Created by ColorXJH on 2023-02-27.
// 有趣的常量
#include <stdio.h>
#define COLS 4
int sum2(const int arr[][COLS],int rows);
int sum(const int arr[],int n);
int main(void){
    int total1,total2,total3;
    int *pt1;
    int (*pt2)[COLS];
    pt1=(int[2]){10,20};
    pt2=(int[2][COLS]){{1,2,3,-9},{4,5,6,-8}};
    total1= sum(pt1,2);
    total2= sum2(pt2,2);
    total3= sum((int[]){4,4,4,5,5,5},6);
    //记住，复合字面量是提供只临时需要的值的一种手段。复合字面量具有
    //块作用域，这意味着一旦离开定义复合字面量的块，程序将无法保证该字面量是否存在。
    //也就是说，复合字面量的定义在最内层的花括号中。
    printf("total1 =%d\n",total1);
    printf("total2 =%d\n",total2);
    printf("total3 =%d\n",total3);
    return 0;
}
int sum(const int arr[],int rows){
    int i;
    int total=0;
    for (int i = 0; i < rows; ++i) {
        total+=arr[i];
    }
    return total;
}

int sum2(const int arr[][COLS],int rows){
    int i,j;
    int total=0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < COLS; ++j) {
            total+=arr[i][j];
        }
    }
    return total;
}

