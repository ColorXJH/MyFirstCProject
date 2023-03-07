//
// Created by ColorXJH on 2023-03-06.
// 将字符串转化为数字
#include <stdio.h>
#include <stdlib.h>
#define LIM 30
char *s_gets(char *st,int n);
int main(void){
    char number[LIM];
    char *end;
    long value;
    puts("enter a number (empty line to quit):");
    while (s_gets(number,LIM)&&number[0]!='\0'){
        //number是指向带转换字符串的指针，&end指针的地址，指针被设置为标识输入数字结束字符的地址
        //如果读取的是10,则end指向字符串10末尾的空字符，则end表示空，*end表示0（空字符的ascii值），
        value= strtol(number,&end,10);//10进制
        printf("base 10 input,base 10 output: %ld,stopped at %s (%d)\n",value,end,*end);
        puts("next_number:");
    }
    puts("bye-bye");
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