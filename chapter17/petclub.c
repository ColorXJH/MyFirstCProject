//
// Created by ColorXJH on 2023/4/12.
// 使用二叉查找树
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.c"
char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
void uppercase(char *st);
char * s_gets(char *st,int n);

int main(void){
    Tree pets;
    char choice;
    InitializeTree(&pets);
    while ((choice=menu())!='q'){
        switch (choice) {
            case 'a':
                addpet(&pets);
                break;
            case 'l':
                showpets(&pets);
                break;
            case 'f':
                findpet(&pets);
                break;
            case 'n':
                printf("%d pets in club\n", TreeItemCount(&pets));
                break;
            case 'd':
                droppet(&pets);
                break;
            default:
                puts("switching error");
        }
    }
    DeleteAll(&pets);
    puts("bye!");
    return 0;
}


char menu(void){
    int ch;
    puts("Nerfville　Pet　Club　Membership　Program");
    puts("Enter　the　letter　corresponding　to　your　choice:");
    puts("a)　add　a　pet　　　　　　l)　show　list　of　pets");
    puts("n)　number　of　pets　　　f)　find　pets");
    puts("d)　delete　a　pet　　　　q)　quit");
    while ((ch=getchar())!=EOF){
        while (getchar()!='\n')//处理输入行中剩余的内容
            continue;
        ch= tolower(ch);
        if(strchr("alrfndq",ch)==NULL)
            puts("please enter an a,l,r,f,n,d,or q:");
        else
            break;
    }
    if(ch==EOF){
        ch='q';
    }
    return ch;

}

void addpet(Tree *pt){
    Item temp;
    if(TreeIsFull(pt)){
        puts("no room in the club!");
    } else{
        puts("please enter name of pet:");
        s_gets(temp.petName,SLEN);
        puts("please enter pet kind:");
        s_gets(temp.petKind,SLEN);
        uppercase(temp.petName);
        uppercase(temp.petKind);
        AddItem(&temp,pt);
    }
}
void droppet(Tree *pt){
    Item  temp;
    if(TreeIsEmpty(pt)){
        puts("no entries!");
        return;
    }
    puts("please enter name of pet you wish to delete:");
    s_gets(temp.petName,SLEN);
    puts("please enter pet kind:");
    s_gets(temp.petKind,SLEN);
    uppercase(temp.petName);
    uppercase(temp.petKind);
    printf("%s the %s ",temp.petName,temp.petKind);
    if(DeleteItem(&temp,pt)){
        printf("is dropped from the club.\n");
    }else{
        printf("is not a member.\n");
    }
}
void showpets(const Tree *pt){
    if(TreeIsEmpty(pt)){
        puts("No entries");
    } else{
        Traverse(pt,printitem);
    }
}
void findpet(const Tree *pt){
    Item item;
    if(TreeIsEmpty(pt)){
        puts("no entries!");
        return;
    }
    puts("please enter name of pet you wish to find:");
    s_gets(item.petName,SLEN);
    puts("please enter pet kind:");
    s_gets(item.petKind,SLEN);
    uppercase(item.petName);
    uppercase(item.petKind);
    printf("%s the %s ",item.petName,item.petKind);
    if(InTree(&item,pt)){
        printf("is a member.\n");
    }else{
        printf("is not a member.\n");
    }
}
void printitem(Item item){
    printf("Pet: %-19s Kind: %-19s\n",item.petName,item.petKind);
}
void uppercase(char *st){
    while (*st){
        *st= toupper(*st);
        st++;
    }
}
char * s_gets(char *st,int n){
    char * ret_val;
    char *find;
    ret_val= fgets(st,n,stdin);
    if(ret_val){
        find= strchr(st,'\n');
        if(find)
            *find='\0';
        else
            while (getchar()!='\n')
                continue;
    }
    return  ret_val;
}

