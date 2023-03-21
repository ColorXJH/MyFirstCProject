//
// Created by ColorXJH on 2023-03-21.
// 在文件中保存结构中的内容
//第一次运行，输入数据存入文件，第二次运行从文件读出数据
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TITL 40
#define MAX_AUTH 40
#define MAX_BKS 10
char * s_gets(char *st,int n);
struct book{
    char title[MAX_TITL];
    char author[MAX_AUTH];
    float value;
};
int main(void){
    struct book library[MAX_BKS];
    int count=0;
    int index,filecount;
    FILE *pbooks;
    int size=sizeof(struct book);
    //a+:读取文件并在末尾添加 b:使用二进制格式，为什么使用二进制格式，因为结构中value是double类型不是字符类型，
    if((pbooks= fopen("books.dat","a+b"))==NULL){
        fputs("can not open books.dat file\n",stderr);
        exit(1);
    }
    //确保指针位于文件开始处，为读做准备
    rewind(pbooks);
    //从文件中读结构
    while (count<MAX_BKS&& fread(&library[count],size,1,pbooks)==1){
        if(count==0)
            puts("current content of books.dat");
        printf("%s by %s:$%.2f\n",library[count].title,library[count].author,library[count].value);
        count++;
    }
    //统计已读结构数量
    filecount=count;
    if(count==MAX_BKS){
        fputs("the books.dat is full ",stderr);
        exit(2);
    }
    //循环提示用户输入并添加到数组末尾
    puts("please add new book titles");
    puts("press[enter] at the start of a line to stop.");
    while (count<MAX_BKS&& s_gets(library[count].title,MAX_TITL)!=NULL&&library[count].title[0]!='\0'){
        puts("now enter the author.");
        s_gets(library[count].author,MAX_AUTH);
        puts("now enter the value.");
        scanf("%f",&library[count++].value);
        while (getchar()!='\n')
            continue;//清理输入行
        if(count<MAX_BKS)
            puts("enter then next title.");
    }
    //打印数组，并写入文件
    if(count>0){
        puts("here is the list of your books:");
        for (index = 0; index <count ; index++) {
            printf("%s by %s:$%.2f\n",library[index].title,library[index].author,library[index].value);
        }
        //一次性写入块    起始位置地址 结构大小      新增的几个块       文件流
        fwrite(&library[filecount],size,count-filecount,pbooks);
        //可能每个块不一定完全使用完全，有些浪费内存缺简单，另一种方法是使用可变大小的记录，为了方便读取文件中的这种记录，每个记录
        //以数值字段规定记录的大小（需要使用链式结构与动态内存分配）

    }else{
        puts("no book?too bad\n");
    }
    puts("bye");
    fclose(pbooks);
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

