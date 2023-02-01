//
// Created by ColorXJH on 2023-02-01.
// 使用循环处理数组
#include <stdio.h>
#define SIZE 10
#define PAR 72
int main(void){
    int index,score[SIZE];
    int sum=0;
    float average;
    printf("enter %d golf scores:\n",SIZE);
    for(index=0;index<SIZE;index++){
        //注意元素类型要带&，数组不需要带，这里每个拆分开来都是int类型元素
        scanf("%d",&score[index]);
    }
    printf("the scores read in are as follows:\n");
    for(index=0;index<SIZE;index++){
        printf("%5d",score[index]);
    }
    printf("\n");
    for(index=0;index<SIZE;index++){
        sum+=score[index];
    }
    average=(float )sum/SIZE;
    printf("sum of scores=%d,average=%.2f\n",sum,average);
    printf("that's a handicap of %.0f.\n",average-PAR);
    return 0;
}

