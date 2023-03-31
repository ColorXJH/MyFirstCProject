//
// Created by ColorXJH on 2023-03-31.
// names的头文件
//常量
#include <string.h>
#define SLEN 32
#ifndef NAMES_H_
#define NAMES_H_

//结构声明
struct names_st{
    char first[SLEN];
    char last[SLEN];
};
//类型定义
typedef struct names_st names;
//函数原型
void get_names(names *);
void show_names(const names *);
char *s_gets(char *st,int n);
#endif
//防止多重包含头文件
#ifndef MYFIRSTCPROJECT_NAMES_H
#define MYFIRSTCPROJECT_NAMES_H

#endif //MYFIRSTCPROJECT_NAMES_H
//通常，以上信息是编译器在创建可执行代码时所需要的信息，而不是可执行代码，可执行代码通常在源文件中，而不是在头文件中