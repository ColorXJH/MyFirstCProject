//
// Created by ColorXJH on 2023-03-27.
// 定义并使用字段
#include <stdio.h>
#include <stdbool.h>//C99定义了bool,true,false
//线的样式
#define  SOLID 0
#define  DOTTED 1
#define  DASHED 2
//三原色
#define BLUE 4
#define GREEN 2
#define RED 1
//混合色
#define BLACK 0
#define YELLOW (RED|GREEN)
#define MAGENTA (RED|BLUE)
#define CYAN (GREEN|BLUE)
#define WHITE (RED|GREEN|BLUE)

const char *colors[8]={"black","red","green","yellow","blue","magenta","cyan","white"};
//结构位表示属性
struct box_props{
    bool opaque :1;//或者unsigned int opaque(c99以前)
    unsigned int fill_color:3;
    unsigned int :4;//填充空位
    //以上一个字节，以下一个字节，如股票不适用填充位，则只有10个字节
    bool show_border:1;
    unsigned int border_color:3;
    unsigned int border_style:2;
    unsigned int :2;
};
void show_settings(const struct box_props *bp);
int main(void){
    //创建并初始化box_props结构
    struct box_props box={true,YELLOW,true,GREEN,DASHED};
    printf("original box settings:\n");
    show_settings(&box);
    box.opaque=false;
    box.fill_color=WHITE;
    box.border_color=MAGENTA;
    box.border_style=SOLID;
    printf("modified box settings:\n");
    show_settings(&box);
    return 0;
}

void show_settings(const struct box_props *bp){
    printf("box is %s.\n",bp->opaque==true?"opaque":"transparent");
    printf("the fill color is %s\n",colors[bp->fill_color]);
    printf("border %s.\n",bp->show_border==true?"shown":"not shown");
    printf("the border color is %s.\n",colors[bp->border_color]);
    printf("the border style is ");
    switch (bp->border_style) {
        case SOLID:
            printf("solid.\n");break;
        case DOTTED:
            printf("dotted'\n");break;
        case DASHED:
            printf("dashed.\n");break;
        default:
            printf("unknown type.\n");
    }
}

