//
// Created by ColorXJH on 2023-03-21.
// 把结构数组传递给函数
#include <stdio.h>
#define FOUND_LEN 50
#define N 2
struct funds{
    char bank[FOUND_LEN];
    double bank_fund;
    char save[FOUND_LEN];
    double save_fund;
};
double sum(const struct funds money[],int n);
int main(void){
    struct funds jones[N]={
            {
                    "Garlic-Melon Bank",
                    4032.27,
                    "Lucky's Savings and Loan",
                    8543.94
            },
            {
                    "Honest Jack's Bank",
                    3620.88,
                    "Party Time Savings",
                    3802.91
            }
    };
    //sum(&jone[0])与下方等价，因为地址相同，使用数组名是一种间接方法
    printf("the jones have a total of $%.2f.\n", sum(jones));
    return 0;
}

double sum(const struct funds money[],int n){
    double total;
    for (int i = 0; i < n; ++i) {
        total+=money[i].bank_fund+money[i].save_fund;
    }
    return total;
}
