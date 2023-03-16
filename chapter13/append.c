//
// Created by ColorXJH on 2023-03-16.
// 把文件附加到另一个文件末尾
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
char *s_gets(char *st,int n);
void append(FILE *source,FILE *dest);
int main(void){
    FILE *fa,*fs;//目标文件与源文件
    int files=0;//附加文件的数量
    char file_app[SLEN];//目标文件名
    char file_src[SLEN];//源文件名
    int ch;
    puts("enter name of destination file:");
    //F:\AHBF\test1.txt
    s_gets(file_app,SLEN);
    //以追加方式打开目标文件
    //该程序示例使用文本模式的文件。使用"ab+"和"rb"模式可以处理二进制文件
    if((fa= fopen(file_app,"a+"))==NULL){
        fprintf(stderr,"can not open %s\n",file_app);
        exit(EXIT_FAILURE);
    }
    //创建输出缓冲区
    //创建一个供标准IO流的缓冲区,供后续fa流文件对其进行操作
    //指针fa识别待处理的流,NULL指向待使用的存储区,没有则创建一个默认的，_IOFBF表示完全缓冲（在缓冲区满时刷新），BUFSIZE告诉缓冲区数组的大小
    if(setvbuf(fa,NULL,_IOFBF,BUFSIZE)!=0){
        fputs("can not create output buffer\n",stderr);
        exit(EXIT_FAILURE);
    }
    puts("enter name of first source file (empty line to quit):");
    //F:\AHBF\test2.txt  F:\AHBF\test3.txt
    while(s_gets(file_src,SLEN)&&file_src[0]!='\0'){
        if(strcmp(file_src,file_app)==0){
            fputs("can not append file to itself\n",stderr);
        }
        else if((fs= fopen(file_src,"r"))==NULL){
            fprintf(stderr,"can not open %s\n",file_src);
        }else{
            //创建输入缓冲区
            if(setvbuf(fs,NULL,_IOFBF,BUFSIZE)!=0){
                fputs("can not create input buffer\n",stderr);
                continue;
            }
            //文件添加
            append(fs,fa);
            //读写文件是否异常
            if(ferror(fs)!=0){
                fprintf(stderr,"error in reading file %s.\n",file_src);
            }
            if(ferror(fa)!=0){
                fprintf(stderr,"error in writing file %s.\n",file_app);
            }
            //关闭源文件输入流
            fclose(fs);
            files++;
            printf("file %s appended.\n",file_src);
            puts("Next file(empty line to quit):");
        }

    }
    printf("done appending %d files append.\n",files);
    //文件输出流定位到开头，方便读取
    rewind(fa);
    printf("%s contents:\n",file_app);
    while ((ch= getc(fa))!=EOF){
        putchar(ch);
    }
    puts("done displaying");
    fclose(fa);
    return 0;
}
//添加文件数据
void append(FILE *source,FILE *dest){
    size_t bytes;
    static char temp[BUFSIZE];
    //重要，在输入流读取之前先放入一个换行符，读取的时候先读取换行符在接着读输入流，保证每次读文件都是另起一行
    ungetc('\n',source);
    //从源文件中按照块读取
    while ((bytes= fread(temp,sizeof (char),BUFSIZE,source))>0){
        //写目标文件
        fwrite(temp,sizeof (char),bytes,dest);
    }
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

