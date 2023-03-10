//
// Created by ColorXJH on 2023-03-10.
// 使用局部静态变量
#include <stdio.h>
void trystat(void);
int out=5;
int main(void){
    printf("out ---%p\n",&out);
    extern int out;
    printf("out ---%p\n",&out);
    for (int i = 1; i < 4; ++i) {
        printf("here comes location %d\n",i);
        trystat();
    }
    return 0;
}
void trystat(void){//每次调用都会初始化fade,但是stay只在编译trystat()函数的时候被初始化一次，如果未显示初始化静态变量，则为0
    int fade=1;
    static int stay=1;
    printf("fade =%d and stay =%d\n",fade++,stay++);
}
//第1条声明确实是trystat()函数的一部分，每次调用该函数时都会执行这
//条声明。这是运行时行为。第2条声明实际上并不是trystat()函数的一部分。
//如果逐步调试该程序会发现，程序似乎跳过了这条声明。这是因为静态变量
//和外部变量在程序被载入内存时已执行完毕。把这条声明放在trystat()函数
//中是为了告诉编译器只有trystat()函数才能看到该变量。这条声明并未在运
//行时执行


