//
// Created by ColorXJH on 2023-03-16.
// 把文件压缩成原来的三分之一
#include <stdio.h>
#include <stdlib.h>//exit()
#include <string.h>//strcpy(),strcat()
#define LEN 40
int main(void){
    //相同的文件指针可以处理不同的
    //文件，前提是这些文件不需要同时打开
    FILE *in,*out;//两个文件指针
    int ch;
    char name1[LEN];//存储输入文件的名称
    char name2[LEN];//存储输出文件的名称
    int count=0;
    //F:\AHBF\test1.txt   F:\AHBF\test2.txt
    puts("please enter the read file location:");
    //该函数不存在获取末尾换行符操作
    scanf("%s",name1);
    printf("so the read file name is %s\n",name1);
    puts("please enter the write file location:");
    scanf("%s",name2);
    printf("so the write file name is %s\n",name2);
    if((in= fopen(name1,"r"))==NULL){
        fprintf(stderr,"i couldn't open the file\"%s\"\n",name1);
        exit(EXIT_FAILURE);
    }
    if((out= fopen(name2,"w"))==NULL){
        fprintf(stderr,"can not create output file \"%s\"\n",name2);
        exit(3);
    }
    while ((ch= getc(in))!=EOF){
        //回车换行符保留
        if(ch=='\r\n'||ch=='\n'||ch=='\r'){
            putc(ch,out);
        }
        if(count++%3==0){
            putc(ch,out);
        }
    }
    if(fclose(in)!=0|| fclose(out)!=0){
        fprintf(stderr,"error in closing files\n");
    }
    printf("file success copy with 1/3 !\n");
    return 0;
}

