//
// Created by ColorXJH on 2023/1/10.
// printf()的返回值
#include <stdio.h>
#include <string.h>
int main(void){
    int num=212;
    int rv;
    rv= printf("%d F is water's boiling point\n",num);//31个字符，包含\n换行符

    printf("the printf() function printed %d characters\n",rv);
    int x=sizeof "xy";
    int y= strlen("xy");
    //sizeof包含字符内存最后的\0结束字符，strlen()函数不包含
    printf("sizeof operator xy is %d,but strlen() function is %d",x,y);
    //字符串内换行
    printf("sizeof operator \nxy is %d,but  strlen() function is %d",x,y);
    //一下等效
    printf("Hello, young lovers, wherever you are.");
    printf("Hello, young "   "lovers" ", wherever you are.");
    printf("Hello, young lovers"
           ", wherever you are.");
    return 0;
}

