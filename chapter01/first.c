//
// Created by ColorXJH on 2022/12/15.
//
#include <stdio.h> //包含另一个文件，这个包是C编译器软件包的标准部分，提供键盘输入和屏幕输出支持
//调用之前先定义
int test(void){
    printf("xixixi\n");
    return 0;
}
int main(void){//函数 int 返回值 main()函数名  void 不带参数，也可以省略
    int num;
    num=1;
    printf("i am a simple");
    printf("computer\n");
    printf("my favorite num is %d because is first",num);
    getchar();//让程序等待击键，按下一个按键后才会返回关闭
    test();
    return 0;
}

