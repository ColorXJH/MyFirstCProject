//
// Created by ColorXJH on 2023-04-06.
// 使用一个结构数组
    //以下设计有如下问题：1：电影的数量不能确定为5，有的人可能是500，一些编译器对于自动存储类别的变量，如movies
    //可用的内存数量设置类一个默认限制，大型数组可能超过限制，可以把数组声明为静态或外部数组，或者设置编译器使用更大的栈来解决找个问题
    //但是数据表示不够灵活是个根本问题，在编译器确定了内存，如果在运行时确定可能会更好，要解决这个问题，要使用动态内存分配来表示数据
        //可以使用malloc()函数分配struct的个数
        //struct film * movies;
        //movies=(struct film*)malloc(n*sizeof(struct film))
        //可以像使用数组名那样使用指针
#include <stdio.h>
#include <string.h>
#define TSIZE 45 //存储片名的数组大小
#define FMAX 5 //影片的最大数量
struct film{
    char title[TSIZE];
    int rating;
};
char *s_gets(char str[],int lim);
int main(void){
    struct film movies[FMAX];
    int i=0;
    int j;
    puts("enter first movie title:");
    while (i<FMAX&& s_gets(movies[i].title,TSIZE)!=NULL&&movies[i].title[0]!='\0'){
        puts("enter your rating<0-10>:");
        scanf("%d",&movies[i++].rating);
        while (getchar()!='\n')
            continue;
        puts("enter next movie title (empty line to stop):");

    }
    if(i==0){
        printf("no data enter\n");
    }else{
        printf("here is the movies:\n");
        for (j = 0;  j<i ; j++) {
            printf("movie:%s rating: %d\n",movies[j].title,movies[j].rating);
        }
    }
    printf("bye!\n");
    return 0;
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


