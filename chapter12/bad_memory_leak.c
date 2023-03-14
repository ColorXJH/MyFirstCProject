//
// Created by ColorXJH on 2023-03-14.
// 内存泄露
#include <stdio.h>
#include <stdlib.h>
//创建临时数组副本的函数
void gobble(double arr[],int n);
int main(void){
    double glad[2000];
    for (int i = 0; i <100 ; ++i) {
        gobble(glad,2000);
    }
    return 0;
}
//第一次调用gobble时，创建了temp指针，并调用malloc()分配了16000字节的内存
//假设free(temp)被注释掉了，则当函数结束时，作为自动变量的指针temp也会消失但是他指向的16000字节依然存在，由于指针被销毁，
//所以无法访问这块内存，也不能被重复使用，当第二次调用的时候，又创建了temp指针和另一块16000字节内存
//结束时又释放了指针变量，但是内存依然没有被释放，如此循环往复就会耗尽内存
//这类问题被称为内存泄露
void gobble(double arr[],int n){
    double *temp=(double*) malloc(n*sizeof (double ));
    free(temp);
}