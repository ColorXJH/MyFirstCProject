//
// Created by ColorXJH on 2023-03-02.
// 拼接两个字符串
#include <stdio.h>
#include <string.h>
#define SIZE 80
char *s_gets(char *st,int n);
int main(void){
    char flowers[SIZE];
    char addon[]="s smell like old shoes";
    puts("what's your favorite flowers?");
    if(s_gets(flowers,SIZE)){
        strcat(flowers,addon);
        puts(flowers);
        puts(addon);
    }else{
        puts("end of file encountered!");
        puts("bye");
    }
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