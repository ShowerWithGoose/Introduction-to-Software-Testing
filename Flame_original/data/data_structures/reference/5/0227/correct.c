#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef long long ll;
typedef struct number{
    int ai;//系数
    int bi;//次数
} num;
num numb1[100000];
num numb2[100000];
num end[1000000];
int read();
int main()
{

    int len1,len2;
    int i=1;
    char c;
    int m,n;
    do
    {
        scanf("%d %d%c",&m,&n,&c);
        numb1[i].ai=m;
        numb1[i].bi=n;
        i++;
    }while (c!='\n');
    len1=i;
//给第一组多项式
    i=1;
    do
    {
        scanf("%d %d%c",&m,&n,&c);
        numb2[i].ai=m;
        numb2[i].bi=n;
        i++;
    }while (c!='\n');
    len2=i;
    int k=0;
//给第二组多项式
    for(i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            end[k].ai=numb1[i].ai*numb2[j].ai;
            end[k].bi=numb1[i].bi+numb2[j].bi;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {

        for(int j=i+1;j<k;j++)
        {
            if(end[i].bi==end[j].bi)
            {
                end[i].ai=end[i].ai+end[j].ai;
                end[j].ai=0;
                end[j].bi=0;
            }
        }

    }
    num swi;
    for(i=0;i<k;i++)
    {
        for(int j=0;j<k-i;j++)
        {
            if(end[j].bi<end[j+1].bi)
            {
                swi=end[j+1];
                end[j+1]=end[j];
                end[j]=swi;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(end[i].ai!=0)
            printf("%d %d ",end[i].ai,end[i].bi);

    }
    return 0;
}
int read(){
    int x=0,f=1,c=getchar();
    while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}

