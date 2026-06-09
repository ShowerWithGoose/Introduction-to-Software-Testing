#include<stdio.h>
#include<string.h>
int n[11],s[11];
void set(int,int);
int N;
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        set(i,1);
    system("pause");
    return 0;
}

void set(int m,int rank)
{
    n[m]=1;
    s[rank]=m;
    int flag=0;
    for(int i=1;i<=N;i++)
    {
        if(0==n[i])
        {
            set(i,rank+1);
            flag=1;
        }
    }
    if(0==flag)
    {
        for(int i=1;i<=N;i++)
            printf("%d ",s[i]);
        printf("\n");
    }
    n[m]=0;
    return ;
}
    


