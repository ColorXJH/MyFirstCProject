//
// Created by ColorXJH on 2023-03-17.
// 一本书的图书目录
#include <stdio.h>
#include <string.h>
char *s_gets(char *st,int n);
#define MAX_TITLE 41
#define MAX_AUTH 31
struct book{//结构模板，标记是book
    char title[MAX_TITLE];
    char author[MAX_AUTH];
    float value;
};
int main(void){
    struct book library;//把library声明为一个book类型的变量
    printf("please enter the book title:\n");
    s_gets(library.title,MAX_TITLE);
    printf("please enter the book author:\n");
    s_gets(library.author,MAX_AUTH);
    printf("please enter the book price:\n");
    scanf("%f",&library.value);//.的优先级比&高==》&(library.value)
    printf("now the book title is %s \n"
           "and book author is %s \n"
           "and book price is %.2f \n",library.title,library.author,library.value);
    return 0;
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

