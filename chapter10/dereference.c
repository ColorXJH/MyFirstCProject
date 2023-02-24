//
// Created by ColorXJH on 2023-02-24.
// 多重解应用令人费解的地方
#include <stdio.h>
int main(void){
    int x=20;
    const y=30;
    int *p1=&x;
    const int *p2=&y;
    const int **pp2;
    p1=p2;//不安全，把const指针赋值给非const指针
    p2=p1;//有效，把非const指针赋值给const指针   --一级引用
    pp2=&p1;//不安全，嵌套指针类型赋值
    //把const指针赋给非const指针不安全，因为这样可以使用
    //新的指针改变const指针指向的数据。编译器在编译代码时，可能会给出警
    //告，执行这样的代码是未定义的。但是把非const指针赋给const指针没问
    //题，前提是只进行一级解引用:

    const int **pp21;
    int *pss;
    const int n=12;
    pp21=&pss;//允许，但是会导致const限定符失效，原意是不能通过*pp21修改它所指向的内容
    *pp21=&n;//有效，两者都声明为const,但是这将导致pss指向n
    *pss=10;//有效，但是这将改变n的值，

    //发生了什么？如前所示，标准规定了通过非const指针更改const数据是
    //未定义的。例如，在Terminal中（OS X对底层UNIX系统的访问）使用gcc编
    //译包含以上代码的小程序，导致n最终的值是12，但是在相同系统下使用
    //clang来编译，n最终的值是10。两个编译器都给出指针类型不兼容的警告。
    //当然，可以忽略这些警告，但是最好不要相信该程序运行的结果，这些结果
    //都是未定义的。
    return 0;
}

