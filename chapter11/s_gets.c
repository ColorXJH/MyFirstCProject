//
// Created by ColorXJH on 2023-03-01.
// 自定义函数：读取整行输入并用空字符代替换行符，或者读取一部分输入，并丢弃其余部分
#include <stdio.h>
char *s_get(char *st,int n);
int main(void){
    char ch[5];
    char *ret=s_get(ch,4);
    puts(ret);
    return 0;
}

char *s_get(char *st,int n){
    char * ret_val;
    int i=0;
    ret_val= fgets(st,n,stdin);
    if(ret_val){//ret_val!=NULL
        while (st[i]!='\n'&& st[i]!='\0')
            i++;
        if(st[i]=='\n'){
            st[i]='\0';
        }else{
            while (getchar()!='\n')
                continue;
        }
    }
    return  ret_val;
}

