//
// Created by ColorXJH on 2023/1/10.
// 演示一些标记格式
#include <stdio.h>
int main(void){
    printf("%x%X%#x\n",31,31,31);//1f1F0x1f
    //正值前面生成前导空格，负值前面不产生前导空格
    printf("**%d**% d**% d**\n",42,42,-42);//**42** 42**-42**
    //%5.3d  5代表字段宽度， 3代表最小位数==》**  006(前面两位是空格，后面两个位是0，最后一位6)
    printf("**%5d**%5.3d**%05d**%05.3d**\n",6,6,6,6);//**    6**  006**00006**  006**
    printf("the %s family just may be $%.2f richer\n","xjh",123.44);
    return 0;
}

