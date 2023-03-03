//
// Created by ColorXJH on 2023-03-03.
// 演示strcpy()函数
#include <stdio.h>
#include <string.h>
#define SIZE 40
#define LIM 5
char *s_gets(char *st,int n);
int main(void){
    char st[20]="sasasa";
    //编译错误，表达式必须为可修改的左值，而st不可修改。
    //st="xasaasa";//因为name作为数组名，是一个指针常量，储存了这个字符数组的起始地址，不可指向其他字符串、
    printf("%s\n",st);
    //字符指针可以用字符串赋值，因为它储存的是字符串常量的首地址。
    //但是，此处必须用字符常量指针！因为赋值给ps的“xxxxx”是一个字符串，字符串是常量！不加const修饰会存在间址修改常量的风险
    char *ps;
    ps="xxxxx";
    char st1[20]="xxxxx";
    printf("%s---arr:%p--char:%p\n",st1,st1,ps);
    //移动指针
    ps++;
    printf("now ps=%s\n",ps);
    char qwords[LIM][SIZE];
    char temp[SIZE];
    int i=0;
    printf("enter %d words beginning with q:\n",LIM);
    while (i<LIM&& s_gets(temp,SIZE)){
        if(temp[0]!='q'){
            printf("%s doesn't begin with q!\n",temp);
        }else{
            strcpy(qwords[i],temp);
            i++;
        }
    }
    printf("here are the words accepted:\n");
    for (int i = 0; i < LIM; ++i) {
        puts(qwords[i]);
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


