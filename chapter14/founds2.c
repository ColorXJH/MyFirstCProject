//
// Created by ColorXJH on 2023-03-20.
// 传递指向结构的指针，传递成员
#include <stdio.h>
#define FOUNDLEN 50
struct funds{
    char bank[FOUNDLEN];
    double bankFound;
    char save[FOUNDLEN];
    double saveFound;
};
double sum(const struct funds *);
double sum2(double x,double y);
double sum3(const struct funds test);
struct funds sum4(struct funds test);
int main(void){
    struct funds stan={
            "Your_Bank",
            40212.23,
            "My_Bank",
            56423.56
    };
    printf("stan has a total \n"
           "of $%.2f \n"
           "or $%.2f\n"
           "or $%.2f\n", sum(&stan), sum2(stan.saveFound,stan.bankFound), sum3(stan));
    stan=sum4(stan);
    printf("new value is %.2f\n",stan.bankFound);
    return 0;
}


double sum(const struct funds * test){//参数是一个指向结构的指针(地址副本)
    return (test->bankFound+test->saveFound);
}

double sum2(double x,double y){//参数是结构成员（副本）
    return x+y;
}

double sum3(const struct funds test){//参数是结构本身(副本)
    return test.bankFound+test.saveFound;
}

struct funds sum4(struct funds test){//参数是结构本身(副本)，返回值也是结构
    test.bankFound=1212.445;
    return test;


}