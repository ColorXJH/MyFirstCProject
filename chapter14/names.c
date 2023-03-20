//
// Created by ColorXJH on 2023-03-20.
// 使用结构指针，并显示分配内存空间
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SLEN 81
struct names{
    char *first;
    char *last;
    int letters;
};
void getinfo(struct names *pt);
char *s_gets(char *st,int n);
int main(void){
    //注意这里pt结构名称不是一个指针，他和数组不同，这里不能用别名指代结构指针，它需要使用变量修饰符指代指针（即地址）：&pt
    struct names pt;
    getinfo(&pt);
    printf("now the first name is %s and the last name is %s\n",(&pt)->first,pt.last);
    free(pt.first);
    free((&pt)->last);
    return 0;
}

void getinfo(struct names *pt){
    printf("the size of char is %d\n",sizeof (char));
    char temp[SLEN];
    printf("please enter your first name:\n");
    s_gets(temp,SLEN);
    printf("input first name is %s\n",temp);
    //分配内存存储名称
    pt->first=(char *)malloc(strlen(temp)+1);
    //拷贝内容到该地址
    strcpy(pt->first,temp);
    printf("enter the last name:\n");
    s_gets(temp,SLEN);
    printf("input last name is %s\n",temp);
    //字符串长度加上结尾的'\0'空字符
    pt->last=(char*) malloc(strlen(temp)+1);
    strcpy(pt->last,temp);
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
