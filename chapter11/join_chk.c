//
// Created by ColorXJH on 2023-03-02.
// 拼接两个字符串，检查第一个数组的大小
#include <stdio.h>
#include <string.h>
#define SIZE 30
#define BUGSIZE 13
char *s_gets(char *st,int n);
int main(void){
    char flowers[SIZE];
    char addon[]="s smell like old shoes";
    char bug[BUGSIZE];
    int available;
    puts("what's your favorite flower?");
    s_gets(flowers,SIZE);
    if(strlen(addon)+ strlen(flowers)+1<=SIZE){
        strcat(flowers,addon);
    }
    puts(flowers);
    puts("what's your favorite bug?");
    s_gets(bug,BUGSIZE);
    available=BUGSIZE- strlen(bug)-1;
    strncat(bug,addon,available);
    puts(bug);
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

