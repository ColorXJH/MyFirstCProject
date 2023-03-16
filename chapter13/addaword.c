//
// Created by ColorXJH on 2023-03-16.
// 使用fprintf(),fscanf(),rewind()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41
int main(void){
    FILE  *fp;
    char words[MAX];
    //E:\jetbrains-2020\clion\workSpace\MyFirstCProject\cmake-build-debug-mingw\no_exists
    if((fp= fopen("no_exists","a+"))==NULL){
        fprintf(stdout,"can't open \"no_exists\"file\n");
        exit(EXIT_FAILURE);
    }
    puts("enter the words to add the file;press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin,"%40s",words)==1)&&(words[0]!='#')){
        fprintf(fp,"%s\n",words);
    }
    puts("file contents:");
    rewind(fp);//返回到文件开始处
    while (fscanf(fp,"%s",words)==1){
        puts(words);
    }
    puts("done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
    return 0;
}

