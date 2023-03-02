//
// Created by ColorXJH on 2023-03-02.
// 使用puts()函数
#include <stdio.h>
#define DEF "I am a #defined string"
int main(void){
    char str1[80]="an array was initialized to me.";
    const char * str2="a pointer was initialized to me.";
    //puts会在末尾添加一个换行符
    puts("i am an argument to puts().");
    puts(DEF);
    puts(str1);
    puts(str2);
    //从str1的第六个元素开始输出
    puts(&str1[5]);
    //从str2的第五个元素开始输出
    puts(str2+4);
    return 0;
}
//用双引号括起来的是字符串常量，且被视为该字符串的地址，另外存储字符串的数组名也被看作是地址
//puts()如何知道在何处停止？该函数在遇到空字符时就停止输出，所以必须确保有空字符
//char　dont[]　=　{　'W',　'O',　'W',　'!'　};
//puts(dont)//dont不是一个字符串，它会一直打印dont后面内存中的内容，直到从内存中发现一个空字符为止