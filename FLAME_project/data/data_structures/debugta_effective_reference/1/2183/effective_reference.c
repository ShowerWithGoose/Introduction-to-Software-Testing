#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 10000
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

int fac[11], list[11];
int i, n, mark;

void print()
{
    int k=0;
    for(k=0;k<n-1;k++)
        printf("%d ", list[k]);
    printf("%d\n", list[k]);
}

void order()
{
    int i=0, j=0;
    for(i=n-1;i>0;i--)
    {
        if(list[i-1]<list[i])
            break;
    }
    int pk=i-1;
    int pj=i;
    for(i=pk+1;i<n;i++)
    {
        if(list[i]>list[pk]&&list[i]<list[pj])
            pj=i;
    }
    mark=list[pk];
    list[pk]=list[pj];
    list[pj]=mark;
    for(j=pk+1,i=n-1;i>j;i--,j++)
    {
        mark=list[i];
        list[i]=list[j];
        list[j]=mark;
    }
}

int main()
{
    scanf("%d", &n);
	fac[0]=1;
	for(i=1;i<11;i++)
        fac[i]=fac[i-1]*i;
    for(i=0;i<n;i++)
        list[i]=i+1;
    print();
    for(i=1;i<fac[n];i++)
    {
        order();
        print();
    }
	return 0;
}



