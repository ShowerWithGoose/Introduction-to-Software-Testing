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
            array[p]=i; // @@ The array index should be p, but the problem requires permutations starting from index 1, and the output loop in put() starts from 0, causing misalignment. Additionally, array size is 10, but N can be up to 10, so index 10 is out of bounds when p=9 and n=10.
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
        printf("%d",array[i]); // @@ Missing space between numbers; expected output has spaces separating integers.
    printf("\n");
}