#include<stdio.h>
void printa(int ar[]);
void swap(int *a,int *b);
void fullp(int a[],int n);
int last;
int main()
{
    scanf("%d",&last);
    int i=0;
    int a[15]={0};
    for(i=0;i<last;i++)
    {
        a[i]=i+1;
    }
    fullp(a,1);
    return 0;
}
void printa(int ar[])
{
    int i=0;
    for(i=0;i<last;i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");
    return ;
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void fullp(int a[],int n)
{
    int i;
    if(n==last)
    {
        printa(a);
        return ;
    }
    fullp(a,n+1);
    for(i=0;i+n<last;i++)
    {
        swap(&a[n+i],&a[n-1]);
        fullp(a,n+1);
    }
    for(i=last-n-1;i>=0;i--)
    {
        swap(&a[n+i],&a[n-1]);
    }
}

