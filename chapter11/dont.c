//
// Created by ColorXJH on 2023-03-02.
// 使用put一定要记得使用空字符
#include <stdio.h>
int main(void){
    char side_a[]="size a";
    char dont[]={'d','o','n','t'};//注意这里没有空字符结尾，不止一个字符串
    char yes[]={'y','e','s','\0'};
    char yes2[]={'y','e','s',' '};
    char side_b[]="size b";
    //为了让puts()能尽快读到空字符，我们把dont放在side_a和side_b之间
    //puts(dont);//不是一个字符串，他会继续读取内存中知道找到空字符为止
    //puts(yes)则没有这个问题，因为他有空字符结尾作为字符串
    puts(yes);
    //yes2也不行
    puts(yes2);
    return 0;
}
