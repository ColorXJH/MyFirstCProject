//
// Created by 金辉夏 on 2023/2/22.
// 指针运算中的优先级
#include <stdio.h>
int data[2]={100,200};
int mData[2]={300,400};
int main(void){
    int *p1, *p2, *p3;
    p1=p2=data;
    p3=mData;
    printf("*p1=%d *p2=%d *p3=%d\n",*p1,*p2,*p3);//100,100,300
    printf("*p1++=%d,*++p2=%d,(*p3)++=%d\n",*p1++,*++p2,(*p3)++);//100,200,300
    printf("*p1=%d,*p2=%d,*p3=%d\n",*p1,*p2,*p3);//200,200,301
    //指向const的指针不能用于改变值，如下：
    double arrays[]={23.33,23.44,33.44};
    const double *pd=arrays;    //把指针pd的指向的类型声明为const,这表明不能使用pd来更改它所指向的值
    //不可以，因为定义了const
    //*pd=29.11;
    //pd[2]=22.22;
    //&pd[0]=pd=arrays=*arrays[0]
    //指针变量 pd 的值指向arrays数组第一个元素的地址，指针pd的地址是内存中的另一个区域
    printf("%f==%f===%p===%f===%p==%p==%p==%p==%p==%p\n",*pd,pd[2],&pd[0],*&pd[0],pd,arrays,&arrays[0],&pd,pd,&arrays[0]);
    arrays[2]=22.75;//可以，因为未被定义const
    //让pd指向别处：
    pd++;//让pd指向arrays[1],没问题
    return 0;
}


