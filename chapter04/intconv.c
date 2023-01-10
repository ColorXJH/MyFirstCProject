//
// Created by ColorXJH on 2023/1/10.
// 一些不匹配的整形转换
#include <stdio.h>
#define PAGES 336
#define WORDS 65618
int main(void){
    short num=PAGES;
    short nums=-PAGES;
    //没有问题
    printf("num as short and unsigned short:%hd %hu\n",num,num);//num as short and unsigned short:336 336
    //%hu表示转换成无符号类型。-336在short(2字节：0-32767代表本身，32768～65535则表示负数，65535表示-1)，-336表示为65200（即， 65536-336）
    printf("-num as short and unsigned short:%hd %hu\n",nums,nums);//-num as short and unsigned short:-336 65200
    //%c使用字符表示，char在系统中占用一个字节，366在二进制中只能截取最后一个字节，这种截断相当于一个整数除以256（8位能表示的所有数字之和），只保留余数，
    //用专业术语来说，该数字被解释成“以256为模”,即该数字除以256后取其余数
    printf("num as int and char:%d %c\n",num,num);//num as int and char:336 P
    //%hd处理大于两位整数的值时也是经行求模运算，65618/65536=82（65536为16位所有数字之和，等价于1后面16个0的值，256等价于1后面8个0的值），余数82，=》0-32766代表正数，32767～65536代表负数
    //%c也是求模运算（除以256取余数）=82
    printf("WORDS as int ,short ,and char:%d %hd %c\n",WORDS,WORDS,WORDS);//WORDS as int ,short ,and char:65618 82 R
    return 0;
}

