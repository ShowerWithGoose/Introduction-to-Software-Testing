#include<stdio.h>
#include<string.h>
#include<stdlib.h>

short a[101][101];
short b[101];

void dfs(int);
void bfs(int);

int main()
{
    int num,side;
    scanf("%d%d",&num,&side);
    while (side--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        a[m][n]=1;
        a[n][m]=1;
    }
    scanf("%d",&side);
    memset(b,0,sizeof(short)*101);
    dfs(num);
    memset(b,0,sizeof(short)*101);
    bfs(num);
    for(int i=0;i<num;i++)
        a[side][i]=0;
    memset(b,0,sizeof(short)*101);
    b[side]=1;
    dfs(num);
    memset(b,0,sizeof(short)*101);
    b[side]=1;
    bfs(num);
    system("pause");
    return 0;
}

void dsearch(int,int);
void dfs(int n)
{
    
    for(int i=0;i<n;i++)
    {
        if(0==b[i])
            dsearch(i,n);
    }
    printf("\n");
    return ;
}
void dsearch(int k,int n)
{
    printf("%d ",k);
        b[k]=1;
    for(int i=0;i<n;i++)
    {
        if(0==a[k][i])continue;
        if(0==b[i])dsearch(i,n);
    }
    return ;
}


void bfs(int n)
{
    int stuck[101]={0};
    int top=0;
    int bottom=0;
    for(int i=0;i<n;i++)
    {
        if(0==b[i])stuck[top++]=i;
        while (top>bottom)
        {
            printf("%d ",stuck[bottom]);
            b[stuck[bottom]]=1;
            for(int j=0;j<n;j++)
            {
                if(0==a[stuck[bottom]][j])continue;
                if(0==b[j])
                {
                    stuck[top++]=j;
                    b[j]=1;
                }               
            }
            bottom++;
        }
    }
    printf("\n");
    return;
}
