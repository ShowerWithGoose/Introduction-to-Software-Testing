//
//  main.c
//  多项式相乘
//
//  Created by  on 2022/3/29.
//

#include <stdio.h>
#include <stdlib.h>
struct node{
    int coefficient;
    int power;
    struct node *link;
}*a[101],*b[101],*sum[101],*temp;

int main(int argc, const char * argv[]) {
    int tempcoefficient,temppower;
    int reca=0,recb=0;
    //将两组数据分别录入ab 记录reca&recb(a和b数据组数）
    char c;
    for(int i=0;scanf("%d %d%c",&tempcoefficient,&temppower,&c);i++){
        if(c=='\n'){
            a[i]=(struct node*)malloc(sizeof(struct node));
            (a[i]->coefficient)=tempcoefficient;
            (a[i]->power)=temppower;
            reca=i+1;
            break;
        }
        else{
            a[i]=(struct node*)malloc(sizeof(struct node));
            (a[i]->coefficient)=tempcoefficient;
            (a[i]->power)=temppower;
        }
                
    }
    for(int i=0;b[i]=(struct node*)malloc(sizeof(struct node)),scanf("%d %d%c",&(b[i]->coefficient),&(b[i]->power),&c)!=EOF;i++){
        recb=i+1;
    }
    //接着把a和b逐项相乘的结果存储进去sum then排序
    int k=0;
    for(int i=0;i<reca;i++)
        for(int j=0;j<recb;j++){
            sum[k]=(struct node*)malloc(sizeof(struct node));
            (sum[k]->coefficient)=(a[i]->coefficient)*(b[j]->coefficient);
            (sum[k]->power)=(a[i]->power)+(b[j]->power);
            (sum[k]->link)=sum[k+1];
            k++;
        }
    for(int i=0;i<k;i++)
        for(int j=i;j<k;j++)
            if((sum[i]->power)<=(sum[j]->power)){
                temp=(struct node*)malloc(sizeof(struct node));
                *temp=*sum[i];
                *sum[i]=*sum[j];
                *sum[j]=*temp;
            }
    //接着删除power重叠的项
    for(int i=0;i<k-1;i++)
        if((sum[i+1]->power)==(sum[i]->power)){
            (sum[i]->power)=-1;
            (sum[i+1]->coefficient)+=(sum[i]->coefficient);
        }
    for(int i=0;i<k;i++)
        if((sum[i]->power)!=-1)
            printf("%d %d ",sum[i]->coefficient,sum[i]->power);
    
    return 0;
}

