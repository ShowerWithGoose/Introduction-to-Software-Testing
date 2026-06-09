#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int graph[1500][1500],visit[1500];
int v,e,delv,s,t,i;
int queue[1500],front,rear,cnt;

void dfs(int n)
{
	int i;
    printf("%d ",n);
    visit[n]=1;
    for(i=0;i<v;i++){
        if(visit[i]==0&&graph[n][i]==1){
            dfs(i);
        }
    }
}

void inq(int n)
{
    rear=(rear+1)%1500;
    queue[rear]=n;
    cnt++;
}

int otq()
{
    int n;
    n=queue[front];
    cnt--;
    front=(front+1)%1500;
    return n;
}

void bfs(int n)
{
	int m,i;
    for(i=0;i<1500;i++){
        queue[i]=-1;
    }
    front=0;
    rear=1499;
    cnt=0;
    inq(n);
	visit[n]=1;
    while(cnt!=0){
        m=otq();
        printf("%d ",m);
        for(i=0;i<v;i++){
            if(visit[i]==0&&graph[m][i]==1){
                inq(i);
                visit[i]=1; 
            }
        }
    }
}

int main()
{
    scanf("%d %d",&v,&e);
    memset(graph,0,sizeof(graph));
    for(i=0;i<e;i++){
        scanf("%d%d",&s,&t);
        graph[s][t]=1;
        graph[t][s]=1;
    }
    scanf("%d",&delv);
    memset(visit,0,sizeof(visit));
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    bfs(0);
    printf("\n");
    for(i=0;i<v;i++){
        graph[delv][i]=0;
        graph[i][delv]=0;
    }
    memset(visit,0,sizeof(visit));
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    bfs(0);
    printf("\n");
    return 0;
}




