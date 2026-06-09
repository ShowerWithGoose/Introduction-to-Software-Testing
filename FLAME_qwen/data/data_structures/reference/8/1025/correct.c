#include<stdio.h>
int hash1[100]={0},n,ans[100][100]={0};
void dfs(int ans[][100],int n)
{
    int stack[100],hash[100]={0};
    int a,i,j;
    int top=-1;
    stack[++top]=0;
    hash[0]=1;
    while(top!=-1)
        {
            a=stack[top--];
            printf("%d ",a);
            for(i=n-1;i>=0;i--)
                {
                    if(ans[i][a]==1&&hash[i]==0)
                        {stack[++top]=i;
                        hash[i]=1;}
                     if(ans[a][i]==1&&hash[i]==0)
                        {stack[++top]=i;
                        hash[i]=1;}
                }
        }
    printf("\n");
}
void Dfs(int p)
{
    printf("%d ", p);
    hash1[p] = 1;
    int i;
    for ( i = 1; i <= n; i++)
    {
        if (ans[p][i] == 1 && hash1[i] == 0)
        {
            Dfs(i);
        }
    }
}
void bfs(int ans[][100],int n)
{
    int que[100],hash[100]={0};
    int a,i;
    int front=-1,rear=-1;
    que[++front]=0;
    hash[0]=1;
    while(front!=rear)
        {
            a=que[++rear];
            printf("%d ",a);
            for(i=0;i<n;i++)
                {
                    if(ans[i][a]==1&&hash[i]==0)
                        {que[++front]=i;
                        hash[i]=1;}
                    if(ans[a][i]==1&&hash[i]==0)
                        {que[++front]=i;
                        hash[i]=1;}
                }
        }
    printf("\n");
}   
int main()
{
    int m,i,j,a,b;
int ans1[100][100]={0};
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            ans[a][b]=1;
            ans[b][a]=1;
        }
    scanf("%d",&a);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            ans1[i][j]=ans[i][j];
    Dfs(0);
    printf("\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            ans1[i][j]=ans[i][j];
    bfs(ans1,n);
    for(i=0;i<n;i++)
        ans[i][a]=0;
    for(i=0;i<n;i++)
        ans[a][i]=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            ans1[i][j]=ans[i][j];
	for(i=0;i<n;i++)
		hash1[i]=0;
    Dfs(0);
    printf("\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            ans1[i][j]=ans[i][j];
    bfs(ans1,n);
    return 0;
}

