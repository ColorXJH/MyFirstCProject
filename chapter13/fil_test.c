//
// Created by ColorXJH on 2023-03-15.
// 文件测试-使用标准io
#include <stdio.h>
#include <stdlib.h>//提供exit()原型
int main(int ars,char *argv[]){
    int ch;//读取文件时，存储每个字符的地方
    //char *chs="F:\\业务中台\\附件\\CryptosUtils.java";
    //char *chs1;//不行，因为没有分配内存
    char chs[100];
    FILE *fp;//文件指针
    unsigned long count=0;
    fgets(chs,100,stdin);
    //F:\业务中台\附件\CryptosUtils.java\n
    //去掉自己回车加上的\n
    for (int i = 0; i < 100; ++i) {
        if(chs[i]=='\n'){
            chs[i]='\0';
            break;
        }
    }
    //scanf("%s",chs1);
    printf("filename is %s\n",chs);
    fp= fopen(chs,"r");
    /*if(ars!=2){
        printf("usage:%s filename\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp= fopen(argv[1],"r"))==NULL){
        printf("can not open %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }*/
    while ((ch= getc(fp))!=EOF){
        putc(ch,stdout);//与putchar(ch)相同
        count++;
    }
    fclose(fp);
    //printf("file %s has %lu characters\n",argv[1],count);
    printf("file %s has %lu characters\n",chs,count);
    return 0;
}
//在terminal中使用命令行参数运行该程序
//1:招待该文件所在路径 gcc file_test.c
//2:运行该文件并附带参数 a.exe F:\业务中台\附件\CryptosUtils.java
//如果不想命令行获取：可以用puts()和fgets()函数替换命令行参数来获得文件名