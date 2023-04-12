//
// Created by ColorXJH on 2023-04-11.
// 二叉查找树，树中不允许有重复的项

#ifndef MYFIRSTCPROJECT_TREE_H
#define MYFIRSTCPROJECT_TREE_H
#include <stdbool.h>
//根据具体情况重新定义Item
#define SLEN 20
typedef struct item{
    char petName[SLEN];
    char petKind[SLEN];
}Item;
#define MAXITEMS 10
typedef struct trnode{//一个树结构，保安左右指针和数据项
    Item item;
    struct trnode *left;//指向左分支的指针
    struct trnode *right;//指向右分支的指针
}Trnode;
typedef struct tree{//一个树，包含树结构和节点数目
    Trnode *root;//指向根节点的指针
    int size;//树的项数
}Tree;

//函数原型
//把数初始化为空，before:ptree指向一棵树,after:树被初始化为空
void InitializeTree(Tree *ptree);

//确定树是否为空，before:ptree指向一棵树，after:为空返回true
bool TreeIsEmpty(const Tree *ptree);

//确定树是否满，before:ptree指向一棵树,after:已满返回true
bool TreeIsFull(const Tree *ptree);

//确定树的项数，before:ptree指向一棵树，after:返回树的项数
int TreeItemCount(const Tree *ptree);

//在树中添加一个项， before:pi是待添加的项目，ptree是一个已初始化的树，after:如果可以添加，添加完毕返回true,否则返回false
bool AddItem(const Item *pi,Tree *ptree);

//在树中查找项，before:pi指向一个项，ptree指向一个已经初始化的树，after: 找到返回true,找不到返回false
bool InTree(const Item *pi,const Tree *ptree);

//从树中删除一项，before:pi是待删除项，ptree是一个已经初始化的树，after:删除成功返回true,失败返回false
bool DeleteItem(const Item *pi,Tree *ptree);

//把函数应用于树的每一项， before:ptree指向一棵树，pfun指向一个函数，after:pfun指向的函数为树中的每一项都执行一遍
void Traverse(const Tree *ptree,void(*pfun)(Item item));

//删除树中的所有项 before:ptree指向一个已初始化的树，after:树为空
void DeleteAll(Tree *ptree);
#endif
