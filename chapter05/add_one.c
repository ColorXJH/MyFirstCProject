//
// Created by ColorXJH on 2023/1/16.
// 递增：前缀与后缀
#include <stdio.h>
int main(void){
    int ultra=0,super=0,sm=0,sp=0,a_post=0,pre_b=0;
    while(super<5){
        super++;
        ++ultra;
        //使用哪种形式都没关系。但是，当运算符和运算对象是更复杂表达式的一部分时，用前缀或后缀的效果不同。
        //先赋值后递增
        a_post=sm++;
        //先递增后赋值==》pre_b = sp + 1;
        pre_b=++sp;
        printf("super=%d; and ultra= %d\n",super,ultra);
        printf("post++=%d-----pre++=%d\n",a_post,pre_b);
    }
    return 0;
}

