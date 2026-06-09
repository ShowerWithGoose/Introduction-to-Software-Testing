#include<stdio.h>
#include<string.h>
int a[500][500],visited[500]={0},Q[500];
int n,m;
void DFS(int m)
{
    int i;
    printf("%d ",m);
    visited[m]=1;
    for(i=0;i<n;i++)
        if (a[m][i]&&!visited[i]){
            DFS(i);
        }
}
void BFS(int m)
{
    int i,front=0,rear=1,temp;
    Q[front]=m;
    while(front<=rear){
        temp=Q[front++];
        if(visited[temp]==1)
            continue;
        else{
            printf("%d ",temp);
            visited[temp]=1;
            for(i=0;i<n;i++)
                if(a[temp][i]==1&&(visited[i]==0))
                    Q[rear++]=i;
        }
    }
}

int main()
{
    int i,j,p,k;
    scanf("%d %d",&n,&m);
    for(p=0;p<m;p++){
        scanf("%d %d",&i,&j);
        a[i][j]=1;
        a[j][i]=1;
    }
    DFS(0);
    printf("\n");
    memset(visited,0,sizeof(visited));
    BFS(0);
    printf("\n");
    scanf("%d",&k);
    memset(visited,0,sizeof(visited));
    visited[k]=1;
    DFS(0);
    printf("\n");
    memset(visited,0,sizeof(visited));
    memset(Q,0,sizeof(Q));
    visited[k]=1;
    BFS(0);
    printf("\n");
 return 0;
}

