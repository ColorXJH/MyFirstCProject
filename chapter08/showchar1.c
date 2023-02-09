//
// Created by ColorXJH on 2023-02-09.
// 有较大I/O问题的程序
#include <stdio.h>
void display(char ch,int lines,int width);
int main(void){
    int ch;//待打印字符
    int rows,cols;
    printf("enter a character and two integers:\n");
    //s 4 6(按下换行符enter之后就会出现问题，第一次输出正常，还没等第二次输出就直接推出了，因为结尾的换行符导致的)
    while ((ch=getchar())!='\n'){
        scanf("%d %d",&rows,&cols);
        display(ch,rows,cols);
        printf("enter another character and two integers:\n");
        printf("enter new line to quit:\n");
    }
    printf("bye!\n");
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