#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include<stdbool.h>
int flag1[100];
int flag2[100];
void print1(int chart[][100],int n,int p,int flag1[])
{
    int i;
    for(i=1;i<n;i++){
        if(chart[p][i]==1&&flag1[i]==1){
                flag1[i]=0;
            printf(" %d",i);
            print1(chart,n,i,flag1);
        }
    }
}
void print2(int chart[][100],int n,int p,int flag1[],int flag2[])
{
    int i;
    for(i=1;i<n;i++){
        flag2[i]=0;
        if(chart[p][i]==1&&flag1[i]==1){
                flag2[i]=1;
                flag1[i]=0;
            printf(" %d",i);
        }
    }
    for(i=0;i<n;i++){
        if(flag2[i]==1){
            print2(chart,n,i,flag1,flag2);
        }
    }
}




int main()
{
    int de;
    int chart[100][100];
    int n,b,i,j,cnt=0,cnt1=0;
    int t1,t2;
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            chart[i][j]=0;
        }
    }
    for(i=0;i<100;i++){
        flag1[i]=1;
        flag2[i]=0;
    }
    scanf("%d %d",&n,&b);
    for(i=0;i<b;i++){
        scanf("%d %d",&t1,&t2);
        chart[t1][t2]=1;
        chart[t2][t1]=1;
    }
     scanf("%d",&de);
    printf("0");
    print1(chart,n,0,flag1);
    printf("\n");
    for(i=0;i<100;i++){
        flag1[i]=1;
    }
    printf("0");
   while(cnt<n-1){
    for(i=1;i<n;i++){
        if(cnt1==0){
            if(chart[0][i]==1&&flag1[i]==1){
                printf(" %d",i);
                flag1[i]=0;
                flag2[cnt]=i;
                cnt++;
            }
        }
        if(cnt1!=0){
            if(chart[flag2[cnt1-1]][i]==1&&flag1[i]==1){
                printf(" %d",i);
                flag1[i]=0;
                flag2[cnt]=i;
                cnt++;
            }
        }
    }
    cnt1++;
   }
   printf("\n");
   printf("0");
   for(i=0;i<n;i++){
    chart[de][i]=0;
    chart[i][de]=0;
   }
       for(i=0;i<100;i++){
        flag1[i]=1;
    }
       print1(chart,n,0,flag1);
    printf("\n");
           for(i=0;i<100;i++){
        flag1[i]=1;
    }
    cnt=0;
    cnt1=0;
    printf("0");
       while(cnt<n-2){
    for(i=1;i<n;i++){
        if(cnt1==0){
            if(chart[0][i]==1&&flag1[i]==1){
                printf(" %d",i);
                flag1[i]=0;
                flag2[cnt]=i;
                cnt++;
            }
        }
        if(cnt1!=0){
            if(chart[flag2[cnt1-1]][i]==1&&flag1[i]==1){
                printf(" %d",i);
                flag1[i]=0;
                flag2[cnt]=i;
                cnt++;
            }
        }
    }
    cnt1++;
   }


   return 0;
}



