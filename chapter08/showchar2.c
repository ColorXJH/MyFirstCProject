//
// Created by ColorXJH on 2023-02-09.
// 按照指定的行，列打印字符
#include <stdio.h>
#include <ctype.h>
void display(char ch,int lines,int width);
int main(void){
    int ch;
    int rows,cols;
    printf("enter a character and tow integers:\n");
    while((ch=getchar())!='\n'){
        if(!islower(ch)){//输入不是字符的跳过
            continue;
        }
        if(scanf("%d %d",&rows,&cols)!=2){//参数不匹配的退出或者遇到文件结尾，则退出
            break;
        }
        display(ch,rows,cols);
        while (getchar()!='\n')//结尾的换行符号跳过，不然下次直接失败
            continue;
        printf("enter a another character and two integers;\n");
        printf("enter a new line to quit:\n");
    }
    printf("bye !\n");
    return 0;
}



void display(char ch,int lines,int width){
    int row,col;
    for(row=1;row<=lines;row++){
        for(col=1;col<=width;col++){
            putchar(ch);
        }
        putchar('\n');
    }
}

