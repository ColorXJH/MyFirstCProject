//
// Created by ColorXJH on 2023-03-14.
// 数据被存储在何处
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int static_store=30;
const char* pcg="String Literal";
int main(void){
    int auto_store=40;
    char auto_string []="Auto char array";
    int *pi;
    char *pcl;
    pi= (int *)malloc(sizeof (int));
    *pi=35;
    pcl=(char *) malloc(strlen("Dynamic String")+1);
    strcpy(pcl,"Dynamic String");
    printf("static_store:%d at %p\n",static_store,&static_store);//1 静态数据（包括字符串字面量）
    printf("auto_store:%d at %p\n",auto_store,&auto_store);//2 自动数据
    printf("*pi:%d at %p\n",*pi,pi);//3 动态分配的数据
    printf("%s at %p\n",pcg,pcg);//1 静态数据（包括字符串字面量）
    printf("%s at %p\n",auto_string,auto_string);//2 自动数据
    printf("%s at %p\n",pcl,pcl);//3 动态分配的数据
    printf("%s at %p\n","My String","My String");//1 静态数据（包括字符串字面量）
    free(pi);
    free(pcl);
    return 0;
}

