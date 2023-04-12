//
// Created by ColorXJH on 2023-04-10.
// 使用抽象数据类型ADT风格的链表
#include <stdio.h>
#include <stdlib.h>//提供exit()原型
#include <string.h>
#include "list.c"//定义List   Item
char *s_gets(char str[],int lim);
void showMovies(Item item);
int main(void){
    List movies;
    Item temp;
    //初始化
    InitializeList(&movies);
    if(ListIsFull(&movies)){
        fprintf(stderr,"No memory available! Bye!\n");
        exit(1);
    }
    //获取用户输入并存储
    puts("enter first movie title:");
    while (s_gets(temp.title,TSIZE)!=NULL&&temp.title[0]!='\0'){
        puts("enter your rating <0-10>:");
        scanf("%d",&temp.rating);
        while (getchar()!='\n')
            continue;
        if(AddItem(temp,&movies)==false){
            fprintf(stderr,"problem allocating memory\n");
            break;
        }
        if(ListIsFull(&movies)){
            puts("the list is now full.");
            break;
        }
        puts("enter the next movie title(empty line to stop):");
    }
    //显示
    if(ListIsEmpty(&movies)){
        printf("no data entered.");
    } else{
        printf("here is the movie list:\n");
        Traverse(&movies,showMovies);
    }
    printf("you entered %d movies.\n", ListItemCount(&movies));
    //清理
    EmptyTheList(&movies);
    printf("bye!\n");
    return 0;
}

void showMovies(Item item){
    printf("Movie: %s Rating: %d\n",item.title,item.rating);
}
char *s_gets(char str[],int lim){
    char * ret_val;
    char * find;
    ret_val= fgets(str,lim,stdin);
    if(ret_val){
        find= strchr(str,'\n');
        if(find)
            *find='\0';
        else
            while (getchar()!='\n')
                continue;
    }
    return ret_val;
}



