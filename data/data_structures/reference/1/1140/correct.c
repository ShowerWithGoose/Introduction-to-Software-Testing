#include<stdio.h>
#include<string.h>
#define arr_print for(int i=0;i<N;i++)printf("%d ",all_num[i])
int N,all_num[12];
void swap(int *s,int *e)
{
    int temp;
    temp=*e;
    for(int i=0;i<e-s;i++)
    {
        *(e-i)=*(e-i-1);
    }
    *s=temp;
}
void bswap(int *s,int *e)
{
    int temp;
    temp=*s;
    for(int i=0;i<e-s;i++)
    {
        *(s+i)=*(s+i+1);
    }
    *e=temp;
}
void allrow(int num[],int n)
{
    if(n==1)
        printf("%d",num[0]);
    if(n==2)
    {
        arr_print;
        printf("\n");
        swap(num,num+1);
        arr_print;
        printf("\n");
        bswap(num,num+1);
    }
    if (n>2)
    {
        for(int i=0;i<n;i++)
        {
            swap(num,num+i);
            allrow(num+1,n-1);
            bswap(num,num+i);
        }
    }
}
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        all_num[i-1]=i;
    }
    allrow(all_num,N);
    getchar();
    return 0;
}
