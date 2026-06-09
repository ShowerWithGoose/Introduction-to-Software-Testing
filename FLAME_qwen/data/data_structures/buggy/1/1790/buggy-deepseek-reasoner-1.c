#include<stdio.h>
int array[10]={0};
int judge[10]={0}; // @@ error: array size should be 11 to allow index up to N (max 10), otherwise accessing judge[10] is out-of-bounds.
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
        printf("%d",array[i]); // @@ error: missing space between numbers; should be "%d " to match required output format.
    printf("\n");
}