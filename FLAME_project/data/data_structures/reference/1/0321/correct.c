#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
int a[10]={1,2,3,4,5,6,7,8,9,10};
void output(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void swap(int i,int j)
{
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void rev(int i,int n)
{
    int p=i+1,q=n-1;
    while(p<q)
    {
        swap(p,q);
        p++,q--;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int num=1;//算出一共有多少种排列方法
    for(int i=1;i<=n;i++)
    {
        num*=i;
    }
    output(n);
    for(int c=1;c<num;c++)
    {
        int i=n-2;
        while(a[i]>=a[i+1])
            i--;
        int j=n-1;
        while(a[j]<=a[i])
            j--;
        swap(i,j);
        rev(i,n);
        output(n);
    }
    return 0;
}


