//
// Created by ColorXJH on 2023/1/9.
// 演示与用户交互
#include <stdio.h>
#include <string.h>//提供strlen()函数的原型
#define DENSITY 62.4 //人体密度
int main(void){
    float weight,volume;
    int size,letters;
    //40个存储单元，只能存39个字符，最后一个位置留给空字符\0
    char name[40];//names是一个可容纳40个字符的数组
    printf("hi!,what's your first name?\n");
    //使用%s转换说明来处理字符串的输入和输出,只读取一个单词
    //这意味着程序在下一次读取输入时，首先读到的是上一次停止读取时的字符
    //(scanf()会在字段结尾或第1个空白字符处停止读取)"Color 144"输入会让name读取“Color”,下一次输入将自动读取“144”
    scanf("%s",name);
    printf("%s,what's your weight in pounds?\n",name);
    scanf("%f",&weight);
    size=sizeof name;
    letters= strlen(name);
    volume=weight/DENSITY;
    printf("%f------yyyy\n",weight);
    printf("well,%s,your volume is %.2f cubic feet.\n",name,volume);
    printf("also,your first name has %d letters,\n",letters);
    printf("and we have %d bytes to store it.\n",size);
    return 0;
}

