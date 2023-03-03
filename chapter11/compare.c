//
// Created by ColorXJH on 2023-03-03.
// 字符串的比较
#include <string.h>
#include <stdio.h>
#define ANSWER "Grant"
#define SIZE 40
char *s_gets(char *st,int n);
int main(void){
    char try[SIZE];
    puts("guess what's my name?");
    s_gets(try,SIZE);
    //strcmp(try,ANSWER)
    while (strcmp(try,ANSWER)!=0){
        puts("no,please guess again");
        s_gets(try,SIZE);
    }
    puts("that's right");
    return 0;
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

