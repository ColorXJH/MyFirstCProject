//
// Created by ColorXJH on 2023-03-14.
// 动态粉煤数组内存
#include <stdio.h>
#include <stdlib.h>//为malloc()和free()提供原型
int main(void){
    double *ptd;//使用malloc()函数需要声明一一个指针用于接受函数返回值，这样就看可以使用类似数组的表示法取标识声明的数据
    int max;
    int number;
    int i=0;
    puts("whats the maximum number of type double entries?");
    if(scanf("%d",&max)!=1){
        puts("number not correctly entered --bye.");
        exit(EXIT_FAILURE);//标识异常终止==》exit(1)
    }
    ptd=(double *)malloc(max*sizeof (double ));
    if(ptd==NULL){//内存分配失败将返回空指针
        puts("memory allocation failed,goodbye!");
        exit(EXIT_FAILURE);
    }
    //ptd现在指向有max个元素的数组
    //如果程序成功分配内存，便可把ptd视为一个有max个元素的数组名
    puts("enter the values(q to quit):");
    while(i<max&& scanf("%lf",&ptd[i])==1){
        ++i;
    }
    printf("here are your %d entries:\n",number=i);
    for (i = 0;  i<number ; i++) {
        printf("%7.2f",ptd[i]);
        //7个数一行
        if(i%7==6){
            putchar('\n');
        }
    }
    //不为7时另起一行，用于结束时到下一个输入的格式
    if(i%7!=0){
        putchar('\n');
    }
    puts("done!");
    free(ptd);
    return 0;
}

