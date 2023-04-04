//
// Created by ColorXJH on 2023-04-04.
// 用qsort排序一组数字
#include <stdlib.h>
#include <stdio.h>
#define NUM 40
void fillarray(double ar[],int n);
void showarray(const double ar[],int n);
int mycomp(const void * p1,const void *p2);
int main(void){
    double vals[NUM];
    fillarray(vals,NUM);
    puts("random list:");
    showarray(vals,NUM);
    //ansi允许把指向任何数据类型的指针强制转换成指向void的指针
    qsort(vals,NUM,sizeof (double ),mycomp);
    puts("sorted list:");
    showarray(vals,NUM);
    return 0;
}

void fillarray(double ar[],int n){
    int index;
    for (index = 0; index <n ; index++) {
        ar[index]=(double )rand()/((double )rand()+0.1);
    }
}
void showarray(const double ar[],int n){
    int index;
    for (index = 0; index < n; ++index) {
        printf("%9.4f",ar[index]);
        if(index%6==5){
            putchar('\n');
        }
    }
    if(index%6!=0){
        putchar('\n');
    }
}
int mycomp(const void * p1,const void *p2){
    //在c中不是必须使用类型转换，但是在c++中是必须的，所以这里遵循c++建议，为移植做准备
    //虽然他们都可以将任意类型指针转换为void类型的指针，但是c++需要强制类型转换，c则不是必须
    const double *a1=(const double *)p1;
    const double *a2=(const double *)p2;
    if(*a1<*a2){
        return -1;
    }else if(*a1==*a2){
        return 0;
    }else{
        return 1;
    }
}

