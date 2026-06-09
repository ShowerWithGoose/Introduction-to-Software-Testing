#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int a[101][101]={{0}};
int visit[101]={0};
int que[101]={0};
void g0(int n){
    for(int i=0;i<n;i++){
        visit[i]=0;
        que[i]=0;
    }
}
void DFS(int n,int k){
    visit[k]=1;
    printf("%d ",k);   
    for(int i=0;i<n;i++){
        if(visit[i]==0&&a[k][i]==1){
            DFS(n,i);
        }
    }
}
void tDFS(int n){
    for(int i=0;i<n;i++){
        if(visit[i]==0){
            DFS(n,i);
        }
    }
    printf("\n");
}

void tBFS(int n)
{
    int i,head=0,tail=1,tmp;    
    que[head]=0;    
    while(head<=tail)    
    {
        tmp=que[head];
        head++;            
        if(visit[tmp])    continue;
        else
        {
            printf("%d ",tmp);        
            visit[tmp]=1;        
            for(i=0;i<n;i++)
                if (a[tmp][i] && !visit[i])    
                    que[tail++]=i;        
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y]=a[y][x]=1;
    }
    g0(n);
    tDFS(n);
    g0(n);
    tBFS(n);
    int v;
    scanf("%d",&v);
    g0(n);
    visit[v]=1; // @@ [Marking vertex v as visited before traversal prevents it from being visited, but the graph structure still includes edges to v, which may cause inconsistent traversal behavior. The correct approach is to remove all edges connected to v from the adjacency matrix.]
    tDFS(n);
    g0(n);
    visit[v]=1; // @@ [Same issue as above: merely marking v as visited does not remove its edges from the graph, so during BFS, neighbors of v might still consider v as a valid adjacent node (though skipped due to visit[v]==1), but more critically, the traversal may not reflect the actual graph after deletion. The adjacency matrix should be updated to remove edges incident to v.]
    tBFS(n);
    return 0;
}