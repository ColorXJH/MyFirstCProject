//
// Created by ColorXJH on 2023-03-22.
// 使用位操作显示二进制
#include <stdio.h>
#include <limits.h>//提供char_bit的定义，char_bit表示每字节的位数
struct {
    unsigned int field1 :1;
    unsigned int :2;//field1和field2之间，有一个2位空隙
    unsigned int field2 :2;
    unsigned int :0;//强制field3存储在下一个unsigned int中
    unsigned int field3 :1;
}stuff;
char * itobs(int n,char *ps);
void show_bstr(const char *str);
int invert_end(int num,int bits);
int main(void){
    //求整个位的内存大小，占用了连哥哥int位置大小，使用一个宽度为0的未命名字段迫使下一个字段与下一个整数对齐
    printf("this stuff bit is %d bytes\n",sizeof(stuff));
    //预留存储int类型的的字符数组的大小，+1代表最后的空字符'\0',不然无法成为字符串
    char bin_str[CHAR_BIT*sizeof (int)+1];
    int number;
    puts("enter integer and see them in binary.");
    puts("Non_numeric input terminates program.");
    while (scanf("%d",&number)==1){
        itobs(number,bin_str);
        //可以直接输出，不必格式化
        //printf("%d is and binary number is %s\n",number,itobs(number,bin_str));
        printf("%d is ",number);
        show_bstr(bin_str);
        putchar('\n');
        number=invert_end(number,4);//反转后四位
        printf("Inverting the last 4 bits gives\n");
        show_bstr(itobs(number, bin_str));
        putchar('\n');
    }
    puts("bye!");
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
void show_bstr(const char *str){
    int i=0;
    while (str[i]){
        putchar(str[i]);
        //先递增，然后取模
        if(++i%4==0&&str[i]){
            //方便观察，每隔四个字符空格一个字符
            putchar(' ');
        }
    }
}
//切换数字的后n位 num：原始数据，bits：多少位
int invert_end(int num,int bits){
    int mask=0;
    int bitval=1;
    while (bits-->0){
        mask|=bitval;//mask=mask|bitval; 求mask掩码1的数目
        bitval<<=1;//bitval=bitval<<1; 该值左移一位，对于二进制来说就是1从第0位唯一到了第1位，以此类推，下次mask掩码的位将再次增加一个1
    }
    //循环结束mask就是有bits位1的一个二进制数
    //此时用原始数据num按位异或该mask掩码，就会让num的后bits位反转
    return num^mask;
}