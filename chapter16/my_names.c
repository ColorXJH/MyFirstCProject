//
// Created by ColorXJH on 2023-03-31.
// 定义names.h中的函数
#include <stdio.h>
#include "names.h"//包含头文件
//函数定义
void get_names(names *pn){
    printf("please enter your first name:\n");
    s_gets(pn->first,SLEN);
    printf("please enter your last name:\n");
    s_gets(pn->last,SLEN);
}
void show_names(const names *pn){
    printf("%s %s\n",pn->first,pn->last);
}
//获取输入，处理换行符等问题
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


