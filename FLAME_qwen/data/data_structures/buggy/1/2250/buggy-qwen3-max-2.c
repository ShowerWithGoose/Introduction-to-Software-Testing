#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
void permutation(int number[],int n);
void print(int number[],int n);
int sum(int n);
int get_A(int number[],int n);
int get_B(int number[],int n,int A);
void swap(int* a,int* b);
void arrange(int A,int n,int number[]);
int main()
{
    int n;
    int number[20];
    scanf("%d",&n);
    for(int i=0;i<=n-1;i++)
    {
        number[i]=i+1;
    }
    permutation(number,n);
    return 0;
}
void permutation(int number[],int n)
{
    int all=sum(n);
    for(int i=1;i<=all;i++)
    {
        print(number,n);
        int A=get_A(number,n);
        int B=get_B(number,n,A);
        swap(number+A,number+B);
        arrange(A,n,number);
    }
}
void print(int number[],int n)//输出数组
{
    for(int i=0;i<=n-1;i++)
    {
        printf("%d ",number[i] );
    }
    printf("\n");
}
int sum(int n)
{
    int all=1;
    for(int i=1;i<=n;i++)
    {
        all=all*i;
    }
    return all;
}
int get_A(int number[],int n)
{
    for(int i=n-1;i>0;i--)
    {
        if(number[i-1]<number[i])
        {
            return i-1;
        }
    }
    return -1; // @@ [Function get_A may reach end of non-void function, leading to undefined behavior when no such index exists (e.g., last permutation). This causes incorrect logic in permutation generation.]
}
int get_B(int number[],int n,int A)
{
    for(int i=n-1;i>0;i--)
    {
        if(number[i]>number[A])
        return i;
    }
    return -1; // @@ [Function get_B may reach end of non-void function if no element greater than number[A] is found, which can happen if A is invalid or logic is flawed. This leads to undefined behavior when used in swap.]
}
void swap(int* a,int* b)
{
    int hold=*a;
    *a=*b;
    *b=hold;
}
void arrange(int A,int n,int number[])
{
    for(int j=0;j<=n-A-1;j++)
    for(int i=A+1;i<n-1-j;i++)
    {
        if(number[i]>number[i+1])
        {
            int hold=number[i];
            number[i]=number[i+1];
            number[i+1]=hold;
        }
    }
}