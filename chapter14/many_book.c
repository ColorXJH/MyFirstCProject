//
// Created by ColorXJH on 2023-03-20.
// 包含多本书的图书目录
#include <stdio.h>
#include <string.h>
char *s_gets(char *st,int n);
#define MAX_TITLE 40
#define MAX_AUTH 40
#define MAX_BOOK 100
struct book{
    char title[MAX_TITLE];
    char author[MAX_AUTH];
    float value;
};
int main(void){
    //注意该数组是自动类型变量，内存在栈中，太大的数组可能会导致分配内存很大
    //可能会抱怨栈大小或者栈溢出，可以手动设置编译期的栈大小或者创建静态或外部数组
    //这样编译期就不会把数组放到栈中
    struct book library[MAX_BOOK];//book结构类型的数组
    int count=0;
    int index;
    printf("please enter the book title.\n");
    printf("please enter at the start of a line to stop.\n");
    //文件结尾返回NULL,字符串是否是空字符串（一开始就按enter键）
    while (count<MAX_BOOK&& s_gets(library[count].title,MAX_TITLE)!=NULL&&library[count].title[0]!='\0'){
        printf("now enter the author.\n");
        s_gets(library[count].author,MAX_TITLE);
        printf("now enter the value.\n");
        scanf("%f",&library[count++].value);
        //弥补了scanf遇到空格或换行符就结束读取的问题
        while (getchar()!='\n')
            continue;
        if(count<MAX_BOOK){
            printf("enter the next title,\n");
        }
    }
    if(count>0){
        printf("here is the list of your books:\n");
        for ( index = 0; index <count ; ++index) {
            printf("%s by %s:$%.2f\n",library[index].title,library[index].author,library[index].value);
        }
    } else{
        printf("no books? to bad.\n");
    }
    return 0;
}
//如果程序不使用浮点数，旧式的Borland  C编译器会尝试使用小版本的
//scanf()来压缩程序。然而，如果在一个结构数组中只有一个浮点值（如程序
//清单14.2中那样），那么这种编译器（DOS的Borland  C/C++  3.1之前的版
//本，不是Borland C/C++ 4.0）就无法发现它存在

//double dummy = sin(0.0);
//这段代码强制编译器载入浮点版本的scanf()。


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

