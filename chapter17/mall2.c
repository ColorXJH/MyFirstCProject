//
// Created by ColorXJH on 2023-04-10.
// 使用Queue2接口
#include <stdio.h>
#include <stdlib.h> // 提供 rand() 和 srand() 的原型
#include <time.h> // 提供 time() 的原型
#include "queue2.c"
#define MIN_PER_HR 60
bool newcustomer(double x);//是否有新顾客到来
Item customertime(long when);//设置顾客参数
int main(void){
    Queue line;
    Item temp; //新的顾客数据
    int hours; //模拟的小时数
    int perhour;//每小时平均多少位顾客
    long cycle,cyclelimit;//循环计数器,计数器上限
    long turnaways=0;//因队列满被拒绝的客户
    long customers=0;//加入队列的顾客数
    long served=0;//在模拟期间咨询过Sigmund的顾客数量
    long sum_line=0;//累计的队列总长
    int waut_time=0;//从当前到sigmund空闲所需要的时间
    double  min_per_cust;//顾客到来的平均时间
    long line_wait=0;//队列累计的等待时间

    InitializeQueue(&line);
    srand((unsigned int) time(0));//rand()随机初始化
    puts("case study: Sigmund Lander's　Advice　Booth");
    puts("Enter　the　number　of　simulation　hours:");
    //输入服务时间
    scanf("%d",&hours);
    //每分钟检查一次，循环一次，查看是否有人入队出队
    cyclelimit=MIN_PER_HR*hours;
    puts("Enter　the　average　number　of　customers　per　hour:");
    //输入一小时多少顾客
    scanf("%d",&perhour);
    //计算每个顾客几分钟到来
    min_per_cust=MIN_PER_HR/perhour;
    //循环处理，相当于每分钟定时请求一次，循环最大值为cyclelimit(循环的时间*60)
    for (cycle = 0;  cycle<cyclelimit ; cycle++) {
        //查看一分钟内是否有顾客来
        if(newcustomer(min_per_cust)){
            //如果队列满了，排队人数+1
            if(QueueIsFull(&line))
                turnaways++;
            else{
                //否则顾客人数+1
                customers++;
                //构造出顾客信息
                temp= customertime(cycle);
                //将顾客信息加入队列
                EnQueue(temp,&line);
            }
        }
        //如果等待时间小于等于0(第一个入队的时候前面设置了初始时间为0)，并且队列不为空
        if(waut_time<=0&&!QueueISEmpty(&line)){
            //出队（服务）
            DeQueue(&temp,&line);
            //设置咨询服务时间
            waut_time=temp.processtime;
            //等待时间=初始时间+在对列中等待的时间差=>(cycle-temp.arrive)
            line_wait+=cycle-temp.arrive;
            served++;
        }
        //如果在等待，在服务时间内，则等待时间-1，因为是每一分钟循环一次，相当于每一分钟询问一下是否还在咨询（咨询时间1-3分钟）
        if(waut_time>0){
            waut_time--;
        }
        //统计队列的总长
        sum_line+= QueueItemCount(&line);
    }
    //当服务客户大于0时，开始输出
    if(customers>0){
        printf("customers accepted: %ld\n",customers);
        printf("customers served: %ld\n",served);
        printf("trunaways: %ld\n",turnaways);
        printf("average queue size: %.2f\n",(double )sum_line/cyclelimit);
        printf("average wait time: %.2f\n",(double )line_wait/served);
    }else
        puts("no customers!");
    //清空队列，释放内存
    EmptyTheQueue(&line);
    puts("bye!");
    return 0;
}

//x是顾客到来的平均时间，单位：分钟，如果1分钟内有顾客到来，返回true
//rand()返回0-RAND_MAX之间的数字
bool newcustomer(double x){
    if(rand()*x/RAND_MAX<1)
        return true;
    else
        return false;
}
//when是顾客到来的时间，返回Item，顾客到达的时间设置为when,顾客咨询的时间设置为随机1-3分钟
Item customertime(long when){
    Item cust;
    cust.processtime=rand()%3+1;
    cust.arrive=when;
    return cust;
}