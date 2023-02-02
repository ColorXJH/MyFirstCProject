//
// Created by ColorXJH on 2023-02-02.
// 更改输入-空格不变
#include <stdio.h>
#define SPACE ' ' //表示单引号空格
int main(void){
    char ch;
    ch=getchar();//读取语句
    while (ch!='\n'){//判断换行
        if(ch==SPACE){//空格保留
            putchar(ch);
        }else{//字符加一
            putchar(ch+1);
        }
        ch=getchar();
    }
    putchar(ch);//打印换行符
    return 0;
}

