//
// Created by ColorXJH on 2023-02-09.
// 打开一个文件并显示该文件
#include <stdio.h>
#include <stdlib.h> //为了使用exit()
int main(void){
    int ch;
    FILE *fp;
    char fname[100];//存储文件名
    printf("enter the name of file\n");
    scanf("%s",fname);
    //E:\jetbrains-2020\clion\workSpace\MyFirstCProject\chapter08\book.txt
    //windows命令行夏如果在同一个文件夹夏则不需要前缀，直接写文件名
    fp= fopen(fname,"r");//打开待读取文件
    if(fp==NULL){//如果失败
        printf("file to open the file,bye!\n");
        exit(1);
    }
    while ((ch= getc(fp))!=EOF){
        putchar(ch);
    }
    fclose(fp);//关闭文件
    return 0;
}


