#include<stdio.h>
#define max 10
int mark[max]={0};
int output[max];
int n;

void rank(int index, int last, int n)
{
    int i;
    if(last==0)
    {
        for(i=0; i<n; i++)
        {
            printf("%d ", output[i]);
        }
        printf("\n");
        return;
    }
    for(i=1; i<=n; i++)
    {
        if(mark[i]==0)
        {
            mark[i]=1;
            output[index]=i;
            rank(index+1, last-1, n);
            mark[i]=0;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    rank(0, n, n);
    return 0;
}
