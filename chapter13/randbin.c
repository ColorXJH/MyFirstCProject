//
// Created by ColorXJH on 2023-03-17.
// 用二进制I/O进行随机访问
#include <stdlib.h>
#include <stdio.h>
#define ARSIZE 1000
int main(void){
    double numbers[ARSIZE];
    double value;
    const char *file="F:\\AHBF\\test4.txt";
    int i;
    long pos;
    FILE *iofile;
    //创建一组double类型的值
    for (i = 0;  i<ARSIZE ; i++) {
        numbers[i]=100.0*i+1.0/(i+1)+1;
    }
    //尝试打开文件(二进制写模式)
    if((iofile= fopen(file,"wb"))==NULL){
        fprintf(stderr,"could not open %s for output.\n",file);
        exit(EXIT_FAILURE);
    }
    //以二进制格式将数组写入文件
    //内存中数组的所有double类型值的位组合（每个位组
    //合都是64位）都被拷贝至文件中。不能用文本编辑器读取最后的二进制文件，因为无法把文件中的值转换成字符串
    //储存在文件中的每个值都与储存在内存中的值完全相同，没有损失任何精确度
    fwrite(numbers,sizeof (double ),ARSIZE,iofile);
    fclose(iofile);
    if((iofile= fopen(file,"rb"))==NULL){
        fprintf(stderr,"can not open %s for random access.\n",file);
        exit(EXIT_FAILURE);
    }
    //从文件中读取选定的内容
    printf("Enter an index in the range of 0-%d.\n",ARSIZE-1);
    while (scanf("%d",&i)==1&&i>=0&&i<ARSIZE){
        pos=(long )i*sizeof (double );//计算偏移量
        fseek(iofile,pos,SEEK_SET);//定位到此处
        fread(&value,sizeof (double ),1,iofile);//读取一个double类型的块并赋值到value上
        printf("the value there is %f.\n",value);
        printf("next index (out of range to quit):\n");
    }
    //完成
    fclose(iofile);
    puts("bye!");
    return 0;
}

