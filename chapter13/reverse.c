//
// Created by ColorXJH on 2023-03-16.
// 倒序显示文件的内容
#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '032' //dos文本文件中的文件结尾标记
#define SLEN 81
int main(void){
    char file[SLEN];
    FILE *fp;
    char ch;
    long count,last;
    puts("enter the name of the file to be processed:");
    scanf("%80s",file);
    //以二进制模式打开文件
    if((fp= fopen(file,"rb"))==NULL){
        printf("reserve can not open %s",file);
        exit(EXIT_FAILURE);
    }
    //int fseek(FILE *stream, long offset, int fromwhere);
    //设置的指针的位置是 起始位置 + 偏移量
    fseek(fp,0L,SEEK_END);//定位到文件末尾
    last= ftell(fp);
    for ( count = 1L; count <=last ; count++) {
        fseek(fp,-count,SEEK_END);//回退
        ch= getc(fp);
        if(ch!=CNTL_Z&&ch!='\r'){//MS-DOS文件
            putchar(ch);
        }
    }
    putchar('\n');
    fclose(fp);
    return 0;
}
//UNIX和MS-DOS环境下都可以运行。UNIX
//只有一种文件格式，所以不需要进行特殊的转换。然而MS-DOS要格外注
//意。许多MS-DOS编辑器都用Ctrl+Z标记文本文件的结尾。以文本模式打开
//这样的文件时，C 能识别这个作为文件结尾标记的字符。但是，以二进制模
//式打开相同的文件时，Ctrl+Z字符被看作是文件中的一个字符，而实际的文
//件结尾符在该字符的后面。文件结尾符可能紧跟在Ctrl+Z字符后面，或者文
//件中可能用空字符填充，使该文件的大小是256的倍数。在DOS环境下不会
//打印空字符，程序中就包含了防止打印Ctrl+Z字符的代码

//二进制模式和文本模式的另一个不同之处是：MS-DOS用\r\n组合表示文
//本文件换行。以文本模式打开相同的文件时，C程序把\r\n“看成”\n。但是，
//以二进制模式打开该文件时，程序能看见这两个字符。因此，程序清单13.4
//中还包含了不打印\r的代码。通常，UNIX文本文件既没有Ctrl+Z，也没有
//\r，所以这部分代码不会影响大部分UNIX文本文件

//ftell()函数在文本模式和二进制模式中的工作方式不同。许多系统的文
//本文件格式与UNIX的模型有很大不同，导致从文件开始处统计的字节数成
//为一个毫无意义的值。ANSI C规定，对于文本模式，ftell()返回的值可以作
//为fseek()的第2个参数。对于MS-DOS，ftell()返回的值把\r\n当作一个字节计数。