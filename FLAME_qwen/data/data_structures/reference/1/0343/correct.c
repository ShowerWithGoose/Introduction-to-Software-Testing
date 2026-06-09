
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int find(int a[],int n);//从右向左搜索第一个小于右侧的数的位置
int cmp(const void*p,const void*q);
int findmin(int a[],int i,int n);//找到i右侧最小的数字下标
int swap(int *a,int i,int j);
int reverse(int *a,int i,int nn);//将i+1以及后面的串翻转
int print(int a[],int n);//打印输出整数数组

int main()
{
    int i=0,j=0;
    int n=0;
    scanf("%d",&n);
    int a[15]={0};
    for(i=0;i<=n-1;i++)
    {
        a[i]=i+1;
        if(i==n-1)
            printf("%d\n",a[i]);
        else
            printf("%d ",a[i]);
    }
    while(1)
    {
        i=find(a,n);
        if(!(i>=0))
            break;
        j=findmin(a,i,n);
        swap(a,i,j);
        if(i+1<n-1)
            reverse(a,i,n);
        print(a,n);
    }
    system("pause");
    return 0;
}

int find(int a[],int n)//从右向左搜索第一个小于右侧的数的位置
{
    int i=n-2;
    for(;i>=0;i--)
    {
        if(a[i]<a[i+1])
            return i;
    }
    return -1;
}
int cmp(const void*p,const void*q)
{
    int *a=(int*)p;
    int *b=(int*)q;
    return *a-*b;
}
int findmin(int a[],int i,int n)//找到i右侧最小的数字下标
{
    int temp=a[i];
    int p=i+1;
    int aa[15];
    int j=0;
    for(;p<=n-1;p++)
    {
        aa[j]=a[p];
        j++;
    }
    qsort(aa,j,sizeof(int),cmp);
    for(p=0;p<=j;p++)
    {
        if(aa[p]>temp)
            break;
    }
    for(i=n-1;i>=0;i--)
    {
        if(a[i]==aa[p])
            return i;
    }
    return -1;
}
int swap(int *a,int i,int j)
{
    int temp=0;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    return 0;
}
int reverse(int *a,int i,int nn)//将i+1以及后面的串翻转
{
    int n=nn-1;//n是最后一位下标
    int front=i+1;
    while(front<n)
    {
        swap(a,front,n);
        front++;
        n--;
    }
    return 0;
}
int print(int a[],int n)//打印输出整数数组
{
    int i=0;
    for(i=0;i<=n-1;i++)
    {
        if(i==n-1)
            printf("%d\n",a[i]);
        else
            printf("%d ",a[i]);
    }
    return 0;
}


