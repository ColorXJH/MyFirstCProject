//
// Created by ColorXJH on 2023-03-06.
// 读入字符串并排序字符串
#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 5
#define HALT ""

void stsrt(char * strings[],int num);
char *s_gets(char *st,int n);
int main(void){
    char input[LIM][SIZE];//存储输入的数组
    char *ptstr[LIM];//内含指针变量的数组
    int ct=0;//输入计数
    int k;//输出计数
    printf("input up to %d lines,and i will sort them\n",LIM);
    printf("to stop,press the enter key at a line's start.\n");
    while (ct<LIM&& s_gets(input[ct],SIZE)!=NULL&&input[ct][0]!='\0'){
        ptstr[ct]=input[ct];//设置指针指向字符串
        ct++;
    }
    stsrt(ptstr,ct);//字符串排序函数
    puts("\nHere's the sorted list:\n");
    for ( k = 0; k <ct ; ++k) {
        puts(ptstr[k]);
    }
    puts("-----original arrays:");
    for (int i = 0; i <LIM ; ++i) {
        puts(input[i]);
    }
    return 0;
}

void stsrt(char * strings[],int num){
    char *temp;
    int top,seek;
    //选择排序-排序的是指针
    //利用for循环依次将每个元素与首元素比较,n个元素n-1轮轮，每轮比较完之后都会确定一个最大的，所以会越来越少
    for (top = 0; top <num-1 ; ++top) {
        for(seek=top+1;seek<num;seek++){
            if(strcmp(strings[top],strings[seek])>0){
                temp=strings[top];
                strings[top]=strings[seek];
                strings[seek]=temp;
            }
        }
    }
}

char *s_gets(char *st,int n){
    char *ret_val;
    int i=0;
    ret_val= fgets(st,n,stdin);
    if(ret_val){
        while (st[i]!='\n'&&st[i]!='\0'){
            i++;
        }
        if(st[i]=='\n'){
            st[i]='\0';
        }else{
            while(getchar()!='\n'){
                continue;
            }
        }
    }
    return ret_val;
}


