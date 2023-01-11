//
// Created by ColorXJH on 2023/1/11.
// 何时使用&
#include <stdio.h>
int main(void){
    int age;
    float assert;
    char pet[30];
    printf("enter your age,assert,and favorite pet.\n");
    //scanf()函数使用空白（换行符、制表符和空格）把输入分成多个字段。
    //在依次把转换说明和字段匹配时跳过空白
    scanf("%d %f",&age,&assert);
    scanf("%s",pet);
    printf("result:%d-%.2f-%s*\n",age,assert,pet);
    //除了%c,其他转换说明都会自动跳过输入值前面的所有空白，因此，scanf("%d%d",&n,&m)与scanf("%d   %d",&n,&m)的行为相同
    //scanf("%c",&ch)从输入中的第一个字符开始读取,scanf(" %c",&ch)从第一个非空白字符串开始读取
    return 0;
}

