//
// Created by ColorXJH on 2023-03-22.
// 使用函数指针
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char * s_gets(char* st,int n);
void show(void(*fp)(char*),char*str);
void Dummy(char *str);// 不更改字符串
void transpose(char *str);// 大小写转置
void toLower(char *str);// 把字符串转换为小写
void toUpper(char *str);// 把字符串转换为大写
void eatLine(void);// 读取至行末尾(丢弃行中的剩余字符) (处理两种情况1：u\n 2upper\n 其中\n代表换行符enter)
char showMenu(void);

//--备用方案--开始
//也可以使用typedef定义变量代替函数指针
typedef void(* V_FP_CHAR)(char *);
void show2(V_FP_CHAR pf,char*);
V_FP_CHAR arr[4]={toLower, toLower, transpose, Dummy};//虽然没有函数数组，但是可以有函数指针数组
//然后将showMenu函数的返回值类型改为int,u,l,t,o返回0，1，2，3
//则可以使用while循环，通过数组调用函数: show2(arr[index],copy)

//--备用方案--结束

int main(void){
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfun)(char *);//声明一个函数指针，被指向的函数接受char*类型的参数，无返回值
    puts("enter a string (empty line to quit);");
    while (s_gets(line,LEN)!=NULL&&line[0]!='\0'){
        while ((choice=showMenu())!='n'){
            switch (choice) {//switch语句设置指针
                case 'u':pfun=toUpper;break;
                case 'l':pfun=toLower;break;
                case 't':pfun=transpose;break;
                case 'o':pfun=Dummy;break;
            }
            strcpy(copy,line);//为show函数拷贝一份
            show(pfun,copy);//根据用户的选择，使用选定的函数
        }
        puts("please enter a string (empty line to quit):");
    }
    puts("bye!");
    return 0;
}

char showMenu(void){
    char ans;
    puts("enter menu choice:");
    puts("u) uppercase　　　l) lowercase");
    puts("t) transposed case o) original case");
    puts("n) next string");
    ans=getchar();//获取用户输入
    ans=tolower(ans);//转化为小写
    eatLine();//清理输入行
    while (strchr("ulton",ans)==NULL){//查找字符ans首次出现的位置,并返回一个指向该字符的指针，没有找到返回空指针
        puts("please enter u,l,t,o,n;");
        ans= tolower(getchar());
        eatLine();
    }
    return ans;
}

void eatLine(void){
    while (getchar()!='\n')
        continue;
}

void toUpper(char *str){
    while (*str){
        *str= toupper(*str);
        str++;
    }
}

void toLower(char *str){
    while (*str){
        *str= tolower(*str);
        str++;
    }

}

void transpose(char *str){
    while (*str){
        if(islower(*str))
            *str= toupper(*str);
        else if(isupper(*str))
            *str= tolower(*str);
        str++;
    }
}
void Dummy(char *str){
    //不改变字符串
}
void show(void(*fp)(char*),char*str){
    (*fp)(str);//把用户选择的函数作用域str
    puts(str);//显示结果
}
//获取n字符长度的输入
char * s_gets(char* st,int n){
    char *ret_val;
    char *find;
    ret_val= fgets(st,n,stdin);
    if(ret_val){
        find= strchr(st,'\n');//查找换行符
        if(find)
            *find='\0';//在此处放置一个空字符串
        else
            while (getchar()!='\n')
                continue;//清理输入行中剩余的字符
    }
    return ret_val;
}

