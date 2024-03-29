//
// Created by ColorXJH on 2023/1/5.
// 可移植整数类型名
#include <stdio.h>
#include <inttypes.h>//支持可移植类型
int main(void){
    int32_t me32;//me32是一个32位有符号整形变量
    me32=45933945;
    printf("first,assume int32_t is int: ");
    printf("me32= %d\n",me32);
    printf("next,lets not make any assumptions.\n");
    printf("instead, use a \"macro\" from inttypes.h:");
    printf("me32=%" PRId32 "\n",me32);//参数PRId32被定义在inttypes.h中的"d"替换
    //等价于：printf("me32 = %" "d" "\n", me32);==》
    //在C语言中，可以把多个连续的字符串组合成一个字符串，所以这条语句又等价于: printf("me32 = %d\n", me32);
    return 0;
}


