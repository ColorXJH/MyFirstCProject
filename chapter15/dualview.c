//
// Created by ColorXJH on 2023-03-27.
// 位字段和按位运算符
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
//位字段符号常量
//边框线样式
#define SOLID 0
#define DOTTED 1
#define DASHED 2
//三原色
#define BLUE 4
#define GREEN 2
#define RED 1
//混合颜色
#define BLACK 0
#define YELLOW (RED|GREEN)
#define MAGENTA (RED|BLUE)
#define CYAN (GREEN|BLUE)
#define WHITE (RED|GREEN|BLUE)
//按位方法中用到的符号常量  0x 16进制  ，以下也可以用枚举代替这些#define定义的符号常量，如enum{OPAQUE=0x1,FILL_BLUE=0x8,...}
#define OPAQUE 0x1 //1
#define FILL_BLUE 0x8 //00001000  16进制的每一位代表二进制的四位 等价：1<<3 1<<n 代表第n位为1的整数（二进制从0开始）
#define FILL_GREEN 0x4 //100
#define FILL_RED 0x2 //10
#define FILL_MASK 0xE //1110
#define BORDER 0x100 //100000000
#define BORDER_BLUE 0x800  //800=》0*8^0+0*8^1+8*8^2=512=>转换为二进制：100000000000  等价：1<<11
#define BORDER_GREEN 0x400 // 10000000000
#define BORDER_RED 0x200 //1000000000
#define BORDER_MASK 0xE00 //111000000000
#define B_SOLID 0 //0
#define B_DOTTED 0x1000 //1000000000000
#define B_DASHED 0x2000 //10000000000000
#define STYLE_MASK 0x3000 //11000000000000

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
union Views/* 把数据看作结构或unsigned short类型的变量 */
{
    struct box_props st_view;
    unsigned short us_view;
};
char * itobs(int n,char *ps);
void show_settings(const struct  box_props *pb);
void show_settings1(unsigned short );
int main(void){
    //创建views联合，并初始化struct
    union Views box={{true,YELLOW,true,GREEN,DASHED}};
    char bin_str[8*sizeof (unsigned int )+1];
    printf("original box settings:\n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.us_view);
    printf("bits are %s\n",itobs(box.us_view, bin_str));
    box.us_view&=~FILL_MASK;//把表示填充色的位置清零
    box.us_view|=(FILL_BLUE|FILL_GREEN);//重置填充色
    box.us_view^=OPAQUE;//切换是否透明的位
    //box.us_view|=BORDER_RED;//错误位的方法
    box.us_view&=~STYLE_MASK;//把样式位清零
    box.us_view|=B_DOTTED;//把样式设置为点
    printf("\nModified box settings:\n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned  int view:\n");
    show_settings1(box.us_view);
    printf("bits are %s\n", itobs(box.us_view,bin_str));
    return 0;
}

char * itobs(int n,char *ps){
    int i;
    //CHAR_BIT宏表示char中的位（bit）数
    const static int size=CHAR_BIT*sizeof (int);
    //0-31位（共32位），对32位数字，每位都求00000001（01为8进制1，这里使用1，十进制1也可以）掩码的值（即与00000001求按位与运算），这样就取出了每一位的值
    for (i=size-1; i>=0; i--,n>>=1) {
        //取出的每一位值0、1，如果想变成字符'0'或者'1',则需要在位运算后面加上'0'即可完成位与字符的转换
        ps[i]=(01&n)+'0';
    }
    //前31-0 32位排列的是该数字的二进制字符表示形式，从右到左依次排列，符合二进制习惯
    //最后一位index=32位用空字符，表示成为字符串,一共占用33个字节
    ps[size]='\0';
    return ps;
}
//st_view示为一个结构，使用位字段操作
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
//us_view示为一个整数，使用按位操作
//01000010 10101101
void show_settings1(unsigned short us){
    printf("box is %s.\n",(us&OPAQUE)==OPAQUE?"opaque":"transparent");
    printf("the fill color is %s.\n",colors[(us>>1)&07]);
    printf("border %s.\n",(us&BORDER)==BORDER?"shown":"not shown");
    printf("the border style is ");
    switch (us&STYLE_MASK) {
        case B_SOLID:
            printf("solid.\n");break;
        case B_DOTTED:
            printf("dotted'\n");break;
        case B_DASHED:
            printf("dashed.\n");break;
        default:
            printf("unknown type.\n");
    }
    //把边框颜色右移至最右端（0号位～2号位），然后把该
    //值与掩码07组合，关闭除了最右端3位以外所有的位。这样结果也在0～7的
    //范围内，可作为colors数组的索引
    printf("the border color is %s.\n",colors[(us>>9)&07]);
}