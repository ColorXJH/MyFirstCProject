//
// Created by ColorXJH on 2023/1/4.
// ����printf()������
#include <stdio.h>
#include <stdlib.h>
#define uint32 unsigned int
void FuncOutputBin(uint32 value);
int main(void){
    //10110010110100000101111000000000
    unsigned int un=3000000000;//intΪ32λ��shortΪ16λ��ϵͳ
    //10110010110100000101111000000000
    //�޷���ֵ 3000000000���з���ֵ?129496296,��ϵͳ�ڴ��е��ڲ���ʾ��ȫ��ͬ
    int ums=-1294967296;
    short end=200;
    long big=65537;
    long long veryBig=12345678908642;
    printf("un=%u and not %d\n",un,un);
    //�ڸ��������ݲ���ʱ��C��������short���͵�ֵ�Զ�ת����int���͵�ֵ
    //ΪʲôҪ����ת����h���η���ʲô�ã�
    //1:int���ͱ���Ϊ�Ǽ����������������ʱ���Ч�����͡���ˣ���short��int���͵Ĵ�С��ͬ�ļ�����У���int���͵Ĳ��������ٶȸ���
    printf("end=%hd and %d\n",end,end);
    //2:ʹ��h���η�������ʾ�ϴ��������ضϳ� short ����ֵ�����
    //65537�Զ����Ƹ�ʽд��һ��32λ����00000000000000010000000000000001��ʹ��%hd��printf()ֻ��鿴��16λ��������ʾ��ֵ��1
    printf("big=%ld and not %hd\n",big,big);
    printf("veryBig=%lld and not %ld\n",veryBig,veryBig);
    FuncOutputBin(un);
    FuncOutputBin(ums);
    return 0;
}
void FuncOutputBin(uint32 value)
{
    char string[33];   //�β�����uint32���Ϊ32λ����������ﶨ���˴�СΪ33���ַ���������
    itoa(value, string, 2);
    printf("�⺯���õ��Ķ�����Ϊ��%s\r\n",string);
}
