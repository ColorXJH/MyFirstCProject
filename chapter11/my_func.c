//
// Created by ColorXJH on 2023-03-02.
// puts函数修改版 打印字符串，不添加\n
#include <stdio.h>
void put1(const char* string);
void put2(const char string[] );
int main(void){
    char *ch="asdasdadad";
    char chs[]="addkkkskks";
    printf("%p\n",ch);
    printf("%p\n","addkkkskks");
    printf("%p\n",chs);
    put1(ch);
    put1(ch);
    puts("---------------------");
    put2(ch);
    put2(chs);
    return 0;
}
void put1(const char* string){
    printf("%p\n",string);
    //string首元素的地址 *string首元素的值
    //当string指向空字符时 *string的值是0，即测试条件为假，结束循环，这样写也可以
    while(*string)
    //while (*string!='\0')
        //++优先级高于* 则该行表示打印这个元素后，指针递增1，（指向下一个元素准备打印）
        putchar(*string++);
}
void put2(const char strings[] ){
    printf("%p\n",strings);
    int i=0;
    while (strings[i])
    //while (strings[i]!='\0')
    {
        putchar(strings[i++]);
    }
}
//可以把 put1 程序作为编写字符串处理函数的模型。因为每个字符串都
//以空字符结尾，所以不用给函数传递字符串的大小。函数依次处理每个字
//符，直至遇到空字符


//打印一个字符串，并统计打印的字符数
int put3(const char * string){
    int count=0;
    while (*string) {
        //打印之后，每次先指针递增，然后求值
        putchar(*string++);
        count++;
    }
    putchar('\n');//不统计换行符
    return count;
}
