#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1000
int pt[max][max];
int vis[max];
void init();
void dfs(int start);
void bfs(int start);
int queue[max];
int front,rear,cou;
void initq();
int tempty();
void enqueue(int temp);
int dequeue();
int n,m;
int main()
{
    scanf("%d %d",&n,&m);
    int s,t;
    init();
    for(int i=0;i<m;i++){
        scanf("%d%d",&s,&t);
        pt[s][t]=1;
        pt[t][s]=1;
    }
    int will_del_node;
    scanf("%d",&will_del_node);
    
    dfs(0);
    printf("\n");memset(vis,0,sizeof(vis));
    bfs(0);
    printf("\n");
    for(int i=0;i<n;i++){
        pt[will_del_node][i]=0;
        pt[i][will_del_node]=0;
    }
    memset(vis,0,sizeof(vis));
    dfs(0);
    printf("\n");
    bfs(0);
    return 0;
}

void init()
{
    memset(pt,0,sizeof(pt));
}

void dfs(int start)
{
    printf("%d ",start);
    vis[start]=1;
    for(int i=0;i<n;i++){
        if(pt[start][i]&&!vis[i])
            dfs(i);
    }
}

void bfs(int start)
{
int tail=1;
    memset(vis,0,sizeof(vis));
    initq();
    enqueue(start);
    while(!tempty()){
        int temp=dequeue();
        if(!vis[temp])	continue;
        else
        {
        	vis[temp]==1;
        printf("%d ",temp);
        for(int i=0;i<n;i++){
            if(!vis[i]&&pt[i][temp]==1){
                enqueue(i);
            }
        }	
		}
        
    }
}

void initq()
{
    for(int i=0;i<max;i++){
        queue[i]=-1;
    }
    front=0;
   rear=max-1;
    cou=0;
}

int tempty()
{
    return cou==0;
}

void enqueue(int temp)
{
    vis[temp]=1;
    rear=(rear+1)%max;
    queue[rear]=temp;
    cou++;
}

int dequeue()
{
    int temp;
    temp=queue[front];
    cou--;
    front=(front+1)%max;
    return temp;
}




