#include<stdio.h>
void arrange(int *shuchu,int *ziranshu,int N,int dep);
int N,dep;
int main()
{
    scanf("%d",&N);
    int shuchu[20]={0},ziranshu[20]={0};
    arrange(shuchu,ziranshu,N,1);
    return 0;
}

void arrange(int *shuchu,int *ziranshu,int N,int dep)
{
    int i=0;
    if(dep==N+1)
    {
        for(i=1;i<=N;i++)
        {
            printf("%d ",shuchu[i]);
        }
        printf("\n");
    }
    for(i=1;i<=N;i++)
    {
        if(ziranshu[i]==0)
        {
            ziranshu[i]=1;
            shuchu[dep]=i;
            arrange(shuchu,ziranshu,N,dep+1);
            ziranshu[i]=0;
        }
    }
}

