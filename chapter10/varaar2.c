//
// Created by ColorXJH on 2023-02-27.
// 使用变长数组的函数
#include <stdio.h>
#define ROWS 3
#define COLS 4
int sum2(int rows,int cols,int arr[rows][cols]);
int main(void){
    int arr[ROWS][COLS]={
            {1,2,3,4},{2,3,4,5},{3,4,5,6}
    };
    sum2(ROWS,COLS,arr);
    return 0;
}

int sum2(int rows,int cols,int arr[rows][cols]){
    int i=0,j=0,total=0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            total+=arr[i][j];
        }
    }
    printf("the array total sum is %d\n",total);
    return total;
}
