#include <stdio.h>
#include <stdlib.h>
#include <simpio.h>
#include "genlib.h"
#include "random.h"
#include <string.h>
#include <time.h>
#include "strlib.h"
#include <unistd.h>

#define max 200

struct Student{
    int  num;
    char name[20];
};
struct Student stus[max];
static int Arecord[50];

void Hint(void){
    printf("欢迎使用抽奖程序！\n");
        printf("\n");
        printf("抽奖含有两种模式，供用户自行选择,分别是：\n");
        printf("\n");
        printf("模式1：多组抽奖，将抽奖者固定，进行三轮抽奖。\n"
               "第一轮从参与者中抽出三名三等奖获得者;\n"
               "第二轮从参与者中抽出二名二等奖获得者;\n"
               "第三轮从参与者中抽出一名一等奖获得者;\n");
        printf("注意：每位参与者只有一次中奖机会\n"
               "例如，当第一轮抽奖中奖后，系统将自动从后两轮抽奖者中将该中奖者的参与资格取消\n"
               "（此模式建议适用于参与抽奖人数较多时）\n");
        printf("\n");
        printf("模式2：单组抽奖，参与者排队进行抽奖\n");
        printf("每位参与者排队进行抽奖，每人一次机会\n\n\n");
}

void Rread(int num)
{
    int i;
    FILE *fp;
    for(i=0;i<num;i++)
    {
        printf("请输入第%d个学生的信息:\n",i+1);
        printf("学号和姓名：");
        scanf("%d %s",&stus[i].num,&stus[i].name);
     }
     fp=fopen("/home/feng/j.txt","w");
     for(i=0;i<num;i++){
            fprintf(fp,"%d %s\n",
             stus[i].num,stus[i].name);
      }
      fclose(fp);
      fp=fopen("/home/feng/j.txt","r");
      if(fp==0){
             printf("文件打开失败！\n");
             return;
       }
      for(i=0;i<num;i++){
            fscanf(fp,"%d %s",&stus[i].num,stus[i].name);
      }
      printf("\n");
      printf("参与抽奖学生的信息：\n");
       for(i=0;i<num;i++){
            printf("学号:%d 姓名:%s\n",stus[i].num,stus[i].name);
        }
      printf("\n");
      fclose(fp);
}

void chou(int i){
    printf("名字:%s 学号:%d\n",stus[i].name,stus[i].num);
}

void record(int a,int b,int c,int d,int e,int f){
    printf("\n");
    printf("---------------\n");
    printf("历史中奖名单：\n");
    printf("一等奖的获得者是：%s\n",stus[a].name);
    printf("二等奖的获得者是：%s,%s\n",stus[b].name,stus[c].name);
    printf("三等奖的获得者是：%s,%s,%s\n",stus[d].name,stus[e].name,stus[f].name);
    printf("---------------\n");
    printf("\n");
}

void draw(void){
        int a,n,b,o,w,i;

        srand((int)time(NULL));

        printf("请输入参与本次抽奖的总人数：");

        int tatal=GetInteger();
        printf("\n");
        Rread(tatal);

        printf("请按回车开始第一轮抽奖：\n");
        string t=GetLine();
        string l=GetLine();
        printf("--------------------------\n");
        printf("开始抽一等奖.\n");
        printf("--------------------------\n");
        printf("\n");
        int p=rand()%tatal;
        system("clear");
        for(i=0;i<=tatal;i++){
            printf("抽奖中...%s\n",stus[i].name);
            usleep(500000);
            system("clear");
        }
        printf("一等奖的获得者是：\n");
        chou(p);

        printf("\n");
        printf("请按回车开始第二轮抽奖：\n");
        l = GetLine();
        printf("\n");
        printf("--------------------------\n");
        printf("开始抽二等奖。\n");
        printf("--------------------------\n");
        printf("\n");
        system("clear");
        for(i=0;i<=tatal;i++){
            printf("抽奖中...%s\n",stus[i].name);
            usleep(500000);
            system("clear");
        }
        printf("二等奖的获得者是： \n");
        while(TRUE){
            a=rand()%tatal;
            if(a!=p){
                chou(a);
            }
            if(a!=p) break;
        }
        while(TRUE){
            n=rand()%tatal;
            if(n!=p&&n!=a){
                chou(n);
            }
            if(n!=p&&n!=a) break;
        }
        printf("\n");

        printf("-----------------\n");
        printf("请按回车开始第三轮抽奖：\n");
        l = GetLine();
        printf("\n");
        printf("--------------------------\n");
        printf("开始抽三等奖。\n");
        printf("--------------------------\n");
        printf("\n");
        system("clear");
        for(i=0;i<=tatal;i++){
            printf("抽奖中...%s\n",stus[i].name);
            usleep(500000);
            system("clear");
        }
        printf("三等奖的获得者是：\n");
        while(TRUE){
            b=rand()%tatal;
            if(b!=p&&b!=a&&b!=n){
                chou(b);
            }
            if(b!=p&&b!=a&&b!=n) break;
        }
        while(TRUE){
            o=rand()%tatal;
            if(o!=p&&o!=a&&a!=n&&o!=b){
                chou(o);
            }
            if(o!=p&&o!=a&&o!=n&&o!=b) break;
        }
        while(TRUE){
            w=rand()%tatal;
            if(w!=p&&w!=a&&w!=n&&w!=b&&w!=o){
                chou(w);
            }
            if(w!=p&&w!=a&&w!=n&&w!=b&&w!=o) break;
        }
        record(p,a,n,b,o,w);
        printf("是否删除数据？按“#”删除，按“*”继续：\n");
        string m=GetLine();
        if(StringEqual(m,"#"))Delet();
}

void Delet(void){
    FILE *fp;
    fp = open("/home/feng/j.txt","r");
    if(fp < 0)
    {
        printf("删除失败！\n");
    }
    else
    {
        printf("删除成功！\n");
        ftruncate(fp,0);
    }
    printf("\n");
}

int RandomInteger(int low, int high){
    int k;
    double d;

    d = (double)rand()/((double)RAND_MAX+1);
    k = (int)(d*(high-low+1));
    return (low+k);
}

void project2(void)
{
    int i=0;
    printf("请输入参与本次抽奖的总人数：");
    int tatal=GetInteger();
    Rread(tatal);

    srand((int)time(NULL));
    int n;
    string l,y;

    string sr[3];
    sr[0]="First prize";
    sr[1]="Second prize";
    sr[2]="Third prize";
    sr[3]="Thank you for your coming";

    for(n=0;n<=tatal-1;n++){
        int k = RandomInteger(1,15);
        Arecord[n]=k;
        printf("正在抽奖人：%s\n",stus[n].name);
        if(n==tatal-1){
            printf("已经是最后一位抽奖者\n");
        }else{
            printf("下一位抽奖人：%s\n",stus[n+1].name);
        }
        printf("请按回车开始抽奖\n");
        if(n==0)y=GetLine();
        l = GetLine();
        system("clear");
        for(i=0;i<4;i++){
            printf("抽奖中...%s\n",sr[i]);
            usleep(500000);
            system("clear");
        }
        printf("%s,",stus[n].name);
        Ddraw(k);
     }
    Hdraw(tatal);
    printf("是否删除数据？按“#”删除，按“*”继续：\n");
    string m=GetLine();
    if(StringEqual(m,"#"))Delet();
}

void Ddraw(int k){
    switch (k) {
    case 7:
        printf("很抱歉您没有中奖...");
        break;
    case 1:
        printf("恭喜您中了一等奖!");
        break;
    case 2:
        printf("恭喜您中了二等奖!");
        break;
    case 3:
        printf("恭喜您中了二等奖!");
        break;
    case 4:
        printf("恭喜您中了三等奖!");
        break;
    case 5:
        printf("恭喜您中了三等奖!");
        break;
    case 6:
        printf("恭喜您中了三等奖!");
        break;
    default:
        printf("很抱歉您没有中奖...");
        break;
    }
    printf("\n");
    printf("-----------------\n");
}

void Choice(void){
        printf("请选择模式:\n");
        printf("输入1进行模式1抽奖;\n");
        printf("输入2进行模式2抽奖;\n");

        int n;
        n = GetInteger();

        switch (n) {
            case 1:
                draw();
                break;
            case 2:
                project2();
                break;
        }
}

void Hdraw(int i){
    int n;

    string l;

    printf("是否查看历史中奖纪录？输入“y”查看，输入“n”退出：\n");
    l=GetLine();

    if (StringEqual(l,"y")){
        for(n=0;n<i;n++){
        printf("%s,",stus[n].name);
        Ddraw(Arecord[n]);
        }
    }
}

int main(void){
    Hint();
    Choice();
    string l;
    while(TRUE){
        printf("按“#”继续抽奖，按“*”退出程序：\n");
        l = GetLine();
        if(StringEqual(l,"*"))break;
        Choice();
    }
}
