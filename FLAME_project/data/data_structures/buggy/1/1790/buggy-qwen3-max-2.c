#include<stdio.h>
int array[10]={0};
int judge[10]={0};
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
        printf("%d",array[i]); // @@ [Missing space between numbers; output should have space-separated integers]
    printf("\n");
}