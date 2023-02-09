//
// Created by ColorXJH on 2023-02-09.
// 重复输入，直到文件结尾
#include <stdio.h>
int main(void){
    int ch;
    //EOF在stdio.h中已经定义过了
    while((ch=getchar())!=EOF){
        putchar(ch);
    }
    return 0;
    //使用该程序进行键盘输入，要设法输入EOF字符
    //例如，在大多数UNIX和
    //Linux系统中，在一行开始处按下Ctrl+D会传输文件结尾信号。许多微型计算
    //机系统都把一行开始处的Ctrl+Z识别为文件结尾信号，一些系统把任意位置
    //的Ctrl+Z解释成文件结尾信号


    //<符号是UNIX和DOS/Windows的重定向运算符。该运算符使words文件
    //与stdin流相关联，把文件中的内容导入echo_eof程序。echo_eof程序本身并
    //不知道（或不关心）输入的内容是来自文件还是键盘，它只知道这是需要导
    //入的字符流，所以它读取这些内容并把字符逐个打印在屏幕上，直至读到文
    //件结尾。因为C把文件和I/O设备放在一个层面，所以文件就是现在的I/O设
    //备。试试看！
}

