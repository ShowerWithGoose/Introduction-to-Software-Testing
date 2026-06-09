#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int a[12];

void daozhi(int p,int q)
{
    int hold;
    while(q>p){
        hold=a[p];
        a[p++]=a[q];
        a[q--]=hold;
    }

    return;
}

int f(int n)
{
    int i=n-1;
    while(a[i]>a[i+1])i--;

    if(i==0)return;

    int j=i+1;
    while(a[j]>a[i])j++;
    j--;

    int hold=a[j];
    a[j]=a[i];
    a[i]=hold;

    daozhi(i+1,n);

    for(int k=1;k<=n;k++)printf("%d ",a[k]);
    printf("\n");

    return f(n);
}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        a[i]=i;
    }

    for(int k=1;k<=n;k++)printf("%d ",a[k]);
    printf("\n");

    f(n);

    return 0;
}

