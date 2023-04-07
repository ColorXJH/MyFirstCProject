//
// Created by ColorXJH on 2023-04-07.
// 使用结构链表  head 用于锚定链表的第一项，prev用于确定链表当前项的前一项，current用于确定当前项
// 这三个指针的地址没变，他们的值一直在变，除了head，因为head锚定第一项，current每次重新分配就会分配新的值作为结构地址
// prev指针的值也是，每次都会锚定当前的current的地址，作为后面新建内存的前一项地址
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45
struct film{
    char title[TSIZE];
    int rating;
    struct film *next;
};
char *s_gets(char str[],int lim);
int main(voi){
    struct film *head=NULL;
    struct film *prev,*current;
    char input[TSIZE];
    puts("enter first movie title:");
    while(s_gets(input,TSIZE)!=NULL&&input[0]!='\0'){
        //创建新结构指针，并分配内存
        current=(struct film *) malloc(sizeof (struct film));
        //存储结构地址:
        //如果头为空，链表中的第一个结构地址应该存储在head指针变量中
        if(head==NULL)
            head=current;
        //随后每个结构的地址应该存储在其前一个结构的next成员中
        else
            prev->next=current;//prev指向上一次分配的结构
        //新结构下一个指针置空
        current->next=NULL;
        //新结构数据填充
        strcpy(current->title,input);
        puts("enter your rating <0-10>:");
        scanf("%d",&current->rating);
        while (getchar()!='\n')
            continue;
        puts("enter next movie title (empty line to stop):");
        //设置prev指向当前结构，因为在用户输入下一部电影且程序为新结构分配空间后，当前结构将变成新结构的上一个结构
        //所以程序在循环末尾这样设置该指针
        prev=current;
    }
    //显示电影列表
    if(head==NULL)
        printf("no data entered");
    else
        printf("here is the movies list:\n");
    //显示链表从设置一个指向第一个结构得指针开始
    current=head;
    //遍历链表时，为什么不直接使用head指针？而是重新创建一个current指针，因为如果使用head就会改变head中的值，程序就找不到链表的开始处
    while (current!=NULL){
        printf("Movie: %s Rating: %d\n",current->title,current->rating);
        //重新设置current指针指向链表的下一个结构，直到最后一项current被设置为NULL
        current=current->next;
    }
    //完成任务，释放已分配得内存
    current=head;
    /*while (current!=NULL){
        current=head;
        if(current!=NULL){
            head=current->next;
        }
        free(current);
    }*/
    while (head!=NULL){
        current=head;
        head=current->next;
        free(current);
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

//反思：程序中没有检查malloc()是否成功请求内存，可以看返回值是否为NULL
//程序中也没有删除链表中的项目，可以根据链表中的值判断，如果是找个值，则去掉，链接前后两项（前一项的next为该项的next=>pre.next=current.next）
//当然还要哦按段删除的是首尾这种情况

//要修改程序，首先应该强调最初的设计，并简化其他细节，上面的程序没有做到这点，它把概念模型和代码细节混在了一起，
//例如程序概念模型需要在链表中添加项，但是却把这些细节（malloc(),current->next）放在最显眼的位置，没有突出接口，
//如果程序能以某种方式强调给链表添加项，并隐藏具体的细节（如调用内存管理函数和设置指针）会更好，把用户接口和代码细节分开的程序，
//更容易理解和学习