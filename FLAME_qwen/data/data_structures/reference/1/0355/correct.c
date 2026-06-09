#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int a[11]= {1,2,3,4,5,6,7,8,9,10,11};
int n;
void swap1(int k,int i)
{
    int temp=a[i],j=0;
    for(j=i; j>k; j--)
        a[j]=a[j-1];
    a[k]=temp;
}
void swap2(int k,int i);

void fun(int k);
void fun1()
{
    scanf("%d",&n);
}
int main()
{
    fun1();
    fun(0);
    return 0;
}
void fun(int k)
{
    int i;
    if(k==n)
    {
        for(i=0; i<n; i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    else
    {
        for(i=k; i<n; i++)
        {
            swap1(k,i);
            fun(k+1);
            swap2(k,i);
        }
    }
}
void swap2(int k,int i)
{
    int temp=a[k],j;
    for(j=k; j<i; j++)
        a[j]=a[j+1];
    a[i]=temp;
}



