//
// Created by ColorXJH on 2023/1/11.
// 跳过输入中的前两个整数
#include <stdio.h>
void testPrintf(void);
int main(void){
    int n;
    printf("please enter tree integers:\n");
    //把*放在%和转换字符之间时，会使得scanf()跳过相应的输出项
    scanf("%*d %*d %d",&n);
    //在程序需要读取文件中特定列的内容时，这项跳过功能很有用
    printf("the last integer was %d\n",n);
    void testPrintf(void);
    return 0;
}

//printf()用法提示
void testPrintf(void){

}
