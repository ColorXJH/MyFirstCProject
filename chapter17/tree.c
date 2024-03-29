//
// Created by ColorXJH on 2023-04-11.
// 二叉树的实现
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
//局部数据类型
//多数接口都要在树中查找特定项，设计一种结构，包含两个指针，一个返回父节点，一个返回当前当前节点
typedef struct pair{
    Trnode *parent;
    Trnode *child;
}Pair;

//局部函数原型
//制作节点信息
static Trnode* MakeNode(const Item *pi);
//两个比较函数
static bool ToLeft(const Item *i1,const Item *i2);
static bool ToRight(const Item *i1,const Item *i2);
//添加节点
static void AddNode(Trnode *new_node,Trnode *root);

static void InOrder(const Trnode *root,void(*pfun)(Item item));
//查找项
static Pair SeekItem(const Item *P1,const Tree *ptree);
//删除节点，由于要修改指针，所以参数是指针的地址（指向Trnode的指针*ptr的地址==》**ptr），即指针的指针
static void DeleteNode(Trnode **ptr);
//删除树的所有节点
static void DeleteAllNodes(Trnode *ptr);

//函数定义
void InitializeTree(Tree *ptree){
    ptree->root=NULL;
    ptree->size=0;
}
//判断树是否为空
bool TreeIsEmpty(const Tree *ptree){
    if(ptree->root==NULL){
        return true;
    } else
        return false;
}
//判断树是否已满
bool TreeIsFull(const Tree *ptree){
    if(ptree->size==MAXITEMS){
        return true;
    } else
        return false;
}
//查询树的节点数
int TreeItemCount(const Tree *ptree){
    return ptree->size;
}
//树添加项
/* 主要分两种情况，
 * 1：树为空，则添加到根节点
 * 2：树不为空，则将节点放到合适的位置
 * */
bool AddItem(const Item *pi,Tree *ptree){
    Trnode *new_node;
    //树中添加项首先要检查树是否已满
    if(TreeIsFull(ptree)){
        fprintf(stderr,"Tree is full!\n");
        return false;
    }
    //其次检查添加的项是否重复
    if(SeekItem(pi,ptree).child!=NULL){
        fprintf(stderr,"attempted to add duplicate item\n");
        return false;
    }
    new_node= MakeNode(pi);//指向新节点
    if(new_node==NULL){
        fprintf(stderr,"could not create new node!\n");
        return false;
    }
    //成功创建了一个新节点。更新树结构的size大小,统计新增了一项
    ptree->size++;
    if(ptree->root==NULL){//树为空，新节点为树的根节点
        ptree->root=new_node;
    }else{//树不为空
        //遍历树，找到合适的位置放置该节点
        AddNode(new_node,ptree->root);//在树中添加新节点
    }
    return true;
}
//树查询项
bool InTree(const Item *pi,const Tree *ptree){
    return (SeekItem(pi,ptree).child==NULL)?false:true;
}
//树删除项
bool DeleteItem(const Item *pi,Tree *ptree){
    Pair look;
    //先在树中查找该项
    look= SeekItem(pi,ptree);
    //没找到该项则提前返回
    if(look.child==NULL){
        return false;
    }
    //找到了该项，但是该项是根节点（look.parent==NULL表明他是一个根节点，因为只有根节点没有parent）
    //关于DeleteNode 删除节点，就是要修改被删除节点父节点的指针，所以该函数传递一个结点指针地址
    if(look.parent==NULL){
        DeleteNode(&ptree->root);//删除根节点
    }else if(look.parent->left==look.child){//待删除的节点是其父节点的左子节点
        DeleteNode(&look.parent->left);
    }else{//待删除的节点是其父节点的右子节点
        DeleteNode(&look.parent->right);
    }
    //维护树的大小
    ptree->size--;
    return true;
}
//树每一项应用函数（遍历）
void Traverse(const Tree *ptree,void(*pfun)(Item item)){
    if(ptree!=NULL){
        InOrder(ptree->root,pfun);
    }
}
//树清空项（和遍历树类似，也要访问每个节点，然后free释放内存）
void DeleteAll(Tree *ptree){
    if(ptree!=NULL){
        DeleteAllNodes(ptree->root);
    }
    //重置Tree类型结构的成员
    ptree->root=NULL;
    ptree->size=0;
}

//局部函数

//创建一个新的节点并赋值，参数为指向新项的指针，注意项（Item），节点(Trnode)，树(Tree)的关系,  树是节点与其子节点的集合
static Trnode* MakeNode(const Item *pi){
    Trnode *new_node;
    new_node=(Trnode*) malloc(sizeof (Trnode));
    if(new_node!=NULL){
        //设置新节点数据，并设置新节点左右指针都为null,表明该节点没有子节点
        new_node->item=*pi;
        new_node->left=NULL;
        new_node->right=NULL;
    }
    return new_node;
}
//两个比较函数
/* 自定义的逻辑用于比较两个树的大小，可能是int的比较，也可能时字符串某种规则的比较，或者其他
 * 本案例选用的时两个字符串的比较
 *      strcmp(x,y)：第一个参数表示的字符串在第二个参数表示的字符串前面返回负数，相同返回0，在后面返回正数
 * */
static bool ToLeft(const Item *i1,const Item *i2){
    int comp1;
    if((comp1= strcmp(i1->petName,i2->petName))<0){//第一个字符串在第二个字符串前面返回负数
        return true;
    } else if(comp1==0&& strcmp(i1->petKind,i2->petKind)<0)//相同接着类比第二个字符串
        return true;
    else
        return false;
}
static bool ToRight(const Item *i1,const Item *i2){
    int comp1;
    if((comp1= strcmp(i1->petName,i2->petName))>0){
        return true;
    }else if(comp1==0&& strcmp(i1->petKind,i2->petKind)>0)
        return true;
    else
        return false;
}
//添加节点
/* 添加节点，如何确定新添加的节点在原来树中的位置？
 * 该函数需要比较新项和根，以确定将新项放在左子树还是右子树
 * 如果新项应该放在左子树中，ToLeft返回true,如果新项应该放在右子树中ToRight返回true
 * 但是左右子树下面可能还有左右子树，当左右子树为空时可以直接放置，但是当他们下面还有新的左右子树的时候，就需要用到递归查询
 * 新项应该和左右子节点分别进行比较，直到查询到一个空子树为止，至此，将新项放到该为止2上
 *      关于如何比较新项于该节点大小，属于自定义方法，有自己的逻辑（ToLeft，ToRight）
 * */
static void AddNode(Trnode *new_node,Trnode *root){
    if(ToLeft(&new_node->item,&root->item)){
        if(root->left==NULL)//空子树
            root->left=new_node;//把节点添加到此处
        else
            AddNode(new_node,root->left);//否则处理该子树
    } else if(ToRight(&new_node->item,&root->item)){
        if(root->right==NULL)
            root->right=new_node;
        else
            AddNode(new_node,root->right);
    } else{//不允许有重复项
        fprintf(stderr,"location error in AddNode()\n");
        exit(1);
    }
}
//遍历树（每个节点都有两个分支，可以使用分而治之的递归思想处理）
static void InOrder(const Trnode *root,void(*pfun)(Item item)){
    if(root!=NULL){
        //处理左子树（递归调用）
        InOrder(root->left,pfun);
        //处理节点中的项
        (*pfun)(root->item);
        //处理右子树（递归调用）
        InOrder(root->right,pfun);
    }
}

//查找项
/* 三个接口都要在树中查找特定项：AddItem():先查找是否重复再添加
 * InTree():查看树中是否有此项，DeleteItem():先查看树中是否有此项然后再删除
 * 因为DeleteItem()需要知道待删除节点的父节点，所有设计拆线呢函数的返回值时，设计一个结构Pair包含两个指针，
 * 一个指向当前节点，一个指向当前节点的父节点
 * */
static Pair SeekItem(const Item *pi,const Tree *ptree){
    //设置Pair结构为根起点。则其父节点为空
    Pair look;
    look.parent=NULL;
    look.child=ptree->root;
    if(look.child==NULL){//如果树是空的提前返回
        return look;
    }
    //从根节点依次往下寻找
    while (look.child!=NULL){
        if(ToLeft(pi,&(look.child->item))){
            look.parent=look.child;
            look.child=look.child->left;
        }else if(ToRight(pi,&(look.child->item))){
            look.parent=look.child;
            look.child=look.child->right;
        } else //如果前两种情况都不满足，则必定是相等的情况
            break;//look.child目标项的节点
    }
    //当退出循环时说明没找到，也就是退出循环的时候look.child为null,look.child=look.child->left/right 设置导致的
    //所以只要跑断look.child是否为null,就能知道是否找到该节点，以及其父节点
    return look;
}
//另一种递归的方法，只是在初始化调用的额时候需要：Pair  look; look.parent=NULL,look.child=root,SeekItem2(x,x,x)
static Pair SeekItem2(const Item *pi,Trnode *root,Pair * look){
    if(ToLeft(pi,&root->item)){
        if(root->left==NULL){
            look->parent=NULL;
            look->child=NULL;
            return *look;
        }
        else{
            look->parent=root;
            SeekItem2(pi,root->right,look);
        }
    } else if(ToRight(pi,&root->item)){
        if(root->right==NULL){
            look->parent=NULL;
            look->child=NULL;
            return *look;
        }else{
            look->parent=root;
            SeekItem2(pi,root->right,look);
        }
    } else{//如果前面两项不是，则必定是相等的情况
        //设置Pair结构为根起点开始。则其父节点为空
        return *look;
    }
}
//删除节点，由于要修改指针（把指针的地址传递给删除任务的函数），
//所以参数是指针的地址（指向Trnode的指针*ptr的地址==》**ptr），即指针的指针
static void DeleteNode(Trnode **ptr){
    //ptr是指向目标节点的父节点指针成员（左右节点）的地址
    //（即：&left代表左右节点本身的地址，但是*left代表该地址上存储的地址值，这个值就是子节点指针的地址，这个子节点上有数据和其他子节点指针，以此类推）
    Trnode *temp;
    //从下面就可以看出
    //ptr代表当前节点指针在父节点中对应的地址值，它存储为父节点的某个子结点（左右子节点）的地址，
    //*ptr则表示这个子节点的地址上面对应的值，这个值就是下一个节点的引用（也就是下一个节点的指针，即下一个节点的地址），指向子节点
    //**otr则是这个子节点地址上面对应的值，也就是Trnode节点本身
    if((*ptr)->left==NULL){ //如果当前节点没有左子节点，注意：（无子节点可以作为该类的一个特例）
        //存储当前节点
        temp=*ptr;
        //当前节点的引用更新为其右子节点，注意：（如果该节点也没有右子节点，则该指针为NULL。这就是无子节点情况的值）
        *ptr=(*ptr)->right;//这句话什么意思呢：就是原来指向ptr的指针地址，现在指向ptr右子节点上去了，ptr本身内存空了出来，被一个临时指针地址引用，方便后面释放内存
        //释放当前节点的内存引用
        free(temp);
    }else if((*ptr)->right==NULL){//如果当前节点没有右子节点
        temp=*ptr;
        //当前节点的引用更新为其左子节点
        *ptr=(*ptr)->left;
        //释放当前节点的内存引用
        free(temp);
    }else{//被删除的节点有两个子节点
        //找到重新链接右子树的位置
        //循环的意思如下：在for循环中通过temp指针从左子树的右半部分向下查找一个空位。找到空位后，把右子树连接于此
        //1:temp=(*ptr)->left 通过temp指针从左子树开始，
        //2:temp->right!=NULL ; temp=temp->right 找这个左子树的右半部分，知道右半部分最末尾
        for (temp=(*ptr)->left; temp->right!=NULL ; temp=temp->right) {
            continue;
        }
        //找到了这个空位，循环结束后temp指向左子树的右半部分的最末尾，现在将原来节点的右子树放在该空位上（这个空位就是最右边节点的下一个右指针空位）
        temp->right=(*ptr)->right;
        //temp保存被删除节点的位置，地址引用
        temp=*ptr;
        //将原来被删除节点的左子树链接到被删除节点的父节点上，因为*ptr代表的就是父节点中子节点指针的地址值，将它对应的地址从原来的子节点，跳转到子节点的左节点上
        *ptr=(*ptr)->left;
        //回收该节点的内存
        free(temp);
    }
}
//删除树的所有节点（递归调用，分而治之）
static void DeleteAllNodes(Trnode *root){
    Trnode *pright;
    if(root!=NULL){
        //保存右子树引用
        pright=root->right;
        //递归调用左子树
        DeleteAllNodes(root->left);
        //释放内存
        free(root);
        //递归调用右子树
        DeleteAllNodes(pright);
    }
}