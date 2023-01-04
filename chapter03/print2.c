//
// Created by ColorXJH on 2023/1/4.
// 更多printf()的特性
#include <stdio.h>
#include <stdlib.h>
#define uint32 unsigned int
void FuncOutputBin(uint32 value);
int main(void){
    //10110010110100000101111000000000
    unsigned int un=3000000000;//int为32位和short为16位的系统
    //10110010110100000101111000000000
    //无符号值 3000000000和有符号值?129496296,在系统内存中的内部表示完全相同
    int ums=-1294967296;
    short end=200;
    long big=65537;
    long long veryBig=12345678908642;
    printf("un=%u and not %d\n",un,un);
    //在给函数传递参数时，C编译器把short类型的值自动转换成int类型的值
    //为什么要进行转换？h修饰符有什么用？
    //1:int类型被认为是计算机处理整数类型时最高效的类型。因此，在short和int类型的大小不同的计算机中，用int类型的参数传递速度更快
    printf("end=%hd and %d\n",end,end);
    //2:使用h修饰符可以显示较大整数被截断成 short 类型值的情况
    //65537以二进制格式写成一个32位数是00000000000000010000000000000001。使用%hd，printf()只会查看后16位，所以显示的值是1
    printf("big=%ld and not %hd\n",big,big);
    printf("veryBig=%lld and not %ld\n",veryBig,veryBig);
    FuncOutputBin(un);
    FuncOutputBin(ums);
    return 0;
}
void FuncOutputBin(uint32 value)
{
    char string[33];   //形参类型uint32最大为32位，因此我这里定义了大小为33的字符串数组存放
    itoa(value, string, 2);
    printf("库函数得到的二进制为：%s\r\n",string);
}