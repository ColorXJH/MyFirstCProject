//
// Created by ColorXJH on 2023/1/10.
// 不匹配的浮点类型转换
#include <stdio.h>
int main(void){
    float n1=3.0;//默认类型转换double->float
    double n2=3.0;
    long n3=2000000000;
    long n4=1234567890;
    //%e转换说明让printf()函数认为待打印的值是double类型（本系统中double为8字节）,但是long为4个字节
    //当printf()查看n3（本系统中是4字节的值）时，除了查看n3的4字节外，还会查看查看n3相邻的4字节，共8字节单元
    //它将8字节单元中的位组合解释成浮点数（如，把一部分位组合解释成指数）
    //------------
    //float类型的值作为printf()参数时会被
    //转换成double类型。在本系统中，float是4字节，但是为了printf()能正确地显
    //示该值，n1被扩成8字节。
    printf("%.le---%.le---%.le---%.le\n",n1,n2,n3,n4);
    printf("%ld---%ld\n",n3,n4);
    //用%ld转换说明打印浮点数会失败
    printf("%ld---%ld---%ld---%ld\n",n1,n2,n3,n4);
    return 0;
}

