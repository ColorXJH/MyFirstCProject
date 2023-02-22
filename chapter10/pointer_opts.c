//
// Created by 金辉夏 on 2023/2/22.
// 指针操作
#include <stdio.h>
int main(void){
    int urn[5]={100,200,300,400,500};
    int *pt1,*pt2,*pt3;
    pt1=urn;//把一个地址赋值给指针
    pt2=&urn[2];//把一个地址赋值给指针
    //解引用指针 以及获得指针的地址
    //pt1表示一个指针，指向urn数组第一个元素的地址，即pt1（&urn[0],urn）是urn[0]的指针,同时pt1指针也有自己的地址，改地址&pt1表示指针pt1的值的内存地址
    //即为改指针的指针（地址），因为地址可以被指针替换，即&pt1是pt1的指针，其值pt1指向urn(&urn[0])，则pt1也是urn[0]的指针（指向urn[0]值所对应的内存地址）
    printf("pointer value,dereference pointer ,pointer address:\n");
    printf("pt1=%p,*pt1=%d,&pt1=%p,&pt1[0]=%p,*&pt1==pt1==&pt1[0]=%p\n",pt1,*pt1,&pt1,&pt1[0],*&pt1);
    //指针加法
    pt3=pt1+4;
    printf("adding a integer to a pointer:\n");
    printf("pt1+4=%p,*(pt1+4)=%d",pt1+4,*(pt1+4));
    //指针递增
    pt1++;
    printf("value after pt1++:\n");
    printf("pt1=%p,*pt1=%d,&pt1=%p\n",pt1,*pt1,&pt1);
    //指针递减
    pt2--;
    printf("value after pt2--:\n");
    printf("pt2=%p,*pt2=%d,&pt2=%p\n",pt2,*pt2,&pt2);
    //恢复为初始值
    --pt1;
    ++pt2;
    printf("pointer reset:\n");
    printf("pt1=%p,pt2=%p\n",pt1,pt2);
    //一个指针减去另一个指针
    printf("pointer 1 substring another :\n");
    //%td转换说明打印地址的差值,相隔两个int而不是两个字节，必须指向相同数组，或者数组后面的第一个地址，c可以保证有效，指向不同数组则会导致错误
    printf("pt2=%p,pt1=%p,pt2-pt1=%td，pt2-pt1=%ld\n",pt2,pt1,pt2-pt1,pt2-pt1);
    //一个指针减去一个整数
    printf("pointer substring an integer:\n");
    printf("pt3=%p,pt3-2=%p\n",pt3,pt3-2);
    printf("-------------\n");
    int xs[3];
    int *x1,*x2;//未初始化，只分配了内存地址未分配指针的值
    printf("ssss-----ssss\n");
    printf("&x1=%p,and &x2=%p\n",&x1,&x2);
    printf("x1=%p\n",x1++);//80  地址增加一个int,4字节
    printf("x1++=%p\n",x1);//84
    //地址未赋值给指针，会报错
    //printf("xs++=%p\n",xs++);
    printf("x1=%p and x2=%p\n",x1,x2);//这里x2还未被初始化

    x2=x1+2;//初始化
    printf("x2=%p\n",x2);//84+8=812=8c(0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f)0-15
    //指针之间无法求和
    //x2=x1+x2;
    printf("xs=%p\n",xs);
    x2=xs+1;
    printf("xs=%p and x2=%p",xs,x2);
    //指针之间无法相乘
    //x2=xs*x1;
    return 0;
}

