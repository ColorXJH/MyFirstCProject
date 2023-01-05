//
// Created by ColorXJH on 2023/1/5.
// 以两种方式显示float类型得值
#include <stdio.h>
int main(void){
    float abouts=32000.0;
    double abet=2.14e9;
    long double dip=5.32e-5;
    printf("%f can be written %e\n",abouts,abouts);
    //以下要求编译器支持C99相关特性
    printf("and it's %a in hexadecimal,powers of 2 notation\n",abouts);
    printf("%f can be written %e\n",abet,abet);
    printf("%Lf can be written %Le\n",dip,dip);
    //浮点数的上溢
    float toobig = 3.4E38 * 100.0f;
    printf("%e\n",toobig);//1.#INF00e+000
    return 0;
}

