#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void DFS(int x,int n);//深度优先
void BFS(int x,int n);//广度优先
void zero();//归零访问次数
void print(int m,int n);//遍历并输出
void print1(int m,int n,int z);//遍历并输出
int a[110][110],flag=0,visit[110]={0};
int queue[110];
int main()
{
    int m,n;//m为顶点个数，n为边的个数
    scanf("%d%d",&m,&n);
    int n1,n2;
    for(int i=0;i<n;i++){
        scanf("%d%d",&n1,&n2);
        a[n1][n2]=1;
        a[n2][n1]=1;
    }
    int z;
    scanf("%d",&z);
    print(m,n);
    print1(m,n,z);
    return 0;
}
void DFS(int x,int n)
{
    if(x==0){
        printf("%d ",x);
    }
    if(x!=0){
        printf("%d ",x);
    }
    visit[x]=1;
    for(int i=0;i<n;i++){
        if(a[x][i]==1&&visit[i]==0)
            DFS(i,n);
    }
}
void BFS(int x,int n)
{
    int front=1,rear=1;
    queue[front]=x;
    while(front<=rear){
        front++;
        if(visit[queue[front-1]]==1)continue;
        if(flag==0){
            printf("%d ",queue[front-1]);flag++;
        }
        else printf("%d ",queue[front-1]);
        visit[queue[front-1]]=1;
        for(int i=1;i<=n;i++){
            if(a[queue[front-1]][i]==1&&visit[i]==0)
                queue[++rear]=i;
        }
    }
}
void print(int m,int n)
{
    DFS(0,n);
    printf("\n");
    zero();
    BFS(0,m);
    printf("\n");
    zero();
}
void zero()
{
    for(int i=0;i<110;i++){
        visit[i]=0;

    }
}
void print1(int m,int n,int z)
{
    visit[z]=1;
    DFS(0,n);
    printf("\n");
    zero();
    visit[z]=1;
    BFS(0,m);
    printf("\n");
}

