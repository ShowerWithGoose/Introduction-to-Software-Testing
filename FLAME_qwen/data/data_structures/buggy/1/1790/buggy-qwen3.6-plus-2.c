#include<stdio.h>
int array[10]={0};
int judge[10]={0}; // @@ Array size should be at least 11 to accommodate index 10 when N=10, preventing out-of-bounds access.
void f(int n,int p);
void put(int n);
int main()
{
    int i,n;
    scanf("%d",&n);
    f(n,0);
    return 0;
}
void f(int n,int p)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(judge[i]==0)
        {
            judge[i]=1;
            array[p]=i;
            if(p==n-1)
                put(n);
            else
                f(n,p+1);
            judge[i]=0;
            array[p]=0;
        }
    }
} 
void put(int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d",array[i]); // @@ Missing space separator between numbers. Should be printf("%d ", array[i]); to match the required output format.
    printf("\n");
}