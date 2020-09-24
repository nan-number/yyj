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
    printf("��ӭʹ�ó齱����\n");
        printf("\n");
        printf("�齱��������ģʽ�����û�����ѡ��,�ֱ��ǣ�\n");
        printf("\n");
        printf("ģʽ1������齱�����齱�߹̶����������ֳ齱��\n"
               "��һ�ִӲ������г���������Ƚ������;\n"
               "�ڶ��ִӲ������г���������Ƚ������;\n"
               "�����ִӲ������г��һ��һ�Ƚ������;\n");
        printf("ע�⣺ÿλ������ֻ��һ���н�����\n"
               "���磬����һ�ֳ齱�н���ϵͳ���Զ��Ӻ����ֳ齱���н����н��ߵĲ����ʸ�ȡ��\n"
               "����ģʽ���������ڲ���齱�����϶�ʱ��\n");
        printf("\n");
        printf("ģʽ2������齱���������Ŷӽ��г齱\n");
        printf("ÿλ�������Ŷӽ��г齱��ÿ��һ�λ���\n\n\n");
}

void Rread(int num)
{
    int i;
    FILE *fp;
    for(i=0;i<num;i++)
    {
        printf("�������%d��ѧ������Ϣ:\n",i+1);
        printf("ѧ�ź�������");
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
             printf("�ļ���ʧ�ܣ�\n");
             return;
       }
      for(i=0;i<num;i++){
            fscanf(fp,"%d %s",&stus[i].num,stus[i].name);
      }
      printf("\n");
      printf("����齱ѧ������Ϣ��\n");
       for(i=0;i<num;i++){
            printf("ѧ��:%d ����:%s\n",stus[i].num,stus[i].name);
        }
      printf("\n");
      fclose(fp);
}

void chou(int i){
    printf("����:%s ѧ��:%d\n",stus[i].name,stus[i].num);
}

void record(int a,int b,int c,int d,int e,int f){
    printf("\n");
    printf("---------------\n");
    printf("��ʷ�н�������\n");
    printf("һ�Ƚ��Ļ�����ǣ�%s\n",stus[a].name);
    printf("���Ƚ��Ļ�����ǣ�%s,%s\n",stus[b].name,stus[c].name);
    printf("���Ƚ��Ļ�����ǣ�%s,%s,%s\n",stus[d].name,stus[e].name,stus[f].name);
    printf("---------------\n");
    printf("\n");
}

void draw(void){
        int a,n,b,o,w,i;

        srand((int)time(NULL));

        printf("��������뱾�γ齱����������");

        int tatal=GetInteger();
        printf("\n");
        Rread(tatal);

        printf("�밴�س���ʼ��һ�ֳ齱��\n");
        string t=GetLine();
        string l=GetLine();
        printf("--------------------------\n");
        printf("��ʼ��һ�Ƚ�.\n");
        printf("--------------------------\n");
        printf("\n");
        int p=rand()%tatal;
        system("clear");
        for(i=0;i<=tatal;i++){
            printf("�齱��...%s\n",stus[i].name);
            usleep(500000);
            system("clear");
        }
        printf("һ�Ƚ��Ļ�����ǣ�\n");
        chou(p);

        printf("\n");
        printf("�밴�س���ʼ�ڶ��ֳ齱��\n");
        l = GetLine();
        printf("\n");
        printf("--------------------------\n");
        printf("��ʼ����Ƚ���\n");
        printf("--------------------------\n");
        printf("\n");
        system("clear");
        for(i=0;i<=tatal;i++){
            printf("�齱��...%s\n",stus[i].name);
            usleep(500000);
            system("clear");
        }
        printf("���Ƚ��Ļ�����ǣ� \n");
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
        printf("�밴�س���ʼ�����ֳ齱��\n");
        l = GetLine();
        printf("\n");
        printf("--------------------------\n");
        printf("��ʼ�����Ƚ���\n");
        printf("--------------------------\n");
        printf("\n");
        system("clear");
        for(i=0;i<=tatal;i++){
            printf("�齱��...%s\n",stus[i].name);
            usleep(500000);
            system("clear");
        }
        printf("���Ƚ��Ļ�����ǣ�\n");
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
        printf("�Ƿ�ɾ�����ݣ�����#��ɾ��������*��������\n");
        string m=GetLine();
        if(StringEqual(m,"#"))Delet();
}

void Delet(void){
    FILE *fp;
    fp = open("/home/feng/j.txt","r");
    if(fp < 0)
    {
        printf("ɾ��ʧ�ܣ�\n");
    }
    else
    {
        printf("ɾ���ɹ���\n");
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
    printf("��������뱾�γ齱����������");
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
        printf("���ڳ齱�ˣ�%s\n",stus[n].name);
        if(n==tatal-1){
            printf("�Ѿ������һλ�齱��\n");
        }else{
            printf("��һλ�齱�ˣ�%s\n",stus[n+1].name);
        }
        printf("�밴�س���ʼ�齱\n");
        if(n==0)y=GetLine();
        l = GetLine();
        system("clear");
        for(i=0;i<4;i++){
            printf("�齱��...%s\n",sr[i]);
            usleep(500000);
            system("clear");
        }
        printf("%s,",stus[n].name);
        Ddraw(k);
     }
    Hdraw(tatal);
    printf("�Ƿ�ɾ�����ݣ�����#��ɾ��������*��������\n");
    string m=GetLine();
    if(StringEqual(m,"#"))Delet();
}

void Ddraw(int k){
    switch (k) {
    case 7:
        printf("�ܱ�Ǹ��û���н�...");
        break;
    case 1:
        printf("��ϲ������һ�Ƚ�!");
        break;
    case 2:
        printf("��ϲ�����˶��Ƚ�!");
        break;
    case 3:
        printf("��ϲ�����˶��Ƚ�!");
        break;
    case 4:
        printf("��ϲ���������Ƚ�!");
        break;
    case 5:
        printf("��ϲ���������Ƚ�!");
        break;
    case 6:
        printf("��ϲ���������Ƚ�!");
        break;
    default:
        printf("�ܱ�Ǹ��û���н�...");
        break;
    }
    printf("\n");
    printf("-----------------\n");
}

void Choice(void){
        printf("��ѡ��ģʽ:\n");
        printf("����1����ģʽ1�齱;\n");
        printf("����2����ģʽ2�齱;\n");

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

    printf("�Ƿ�鿴��ʷ�н���¼�����롰y���鿴�����롰n���˳���\n");
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
        printf("����#�������齱������*���˳�����\n");
        l = GetLine();
        if(StringEqual(l,"*"))break;
        Choice();
    }
}
