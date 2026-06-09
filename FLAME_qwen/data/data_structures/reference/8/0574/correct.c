#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int point,line,graph[500][500]={0},p1,p2,p0;
    int i,j,k;
    scanf("%d%d",&point,&line);
    for(i=0;i<line;i++){
        scanf("%d%d",&p1,&p2);
        graph[p1][p2]=1;
        graph[p2][p1]=1;
    }
    int visit[500];
    DFS(graph,0,visit,point);
    printf("\n");
    BFS(graph,0,visit,point);
    printf("\n");
    scanf("%d",&p0);
    for(i=0;i<point;i++){
        graph[p0][i]=0;
        graph[i][p0]=0;
    }
    DFS(graph,0,visit,point);
    printf("\n");
    BFS(graph,0,visit,point);
    printf("\n");
    return 0;
}
void DFS(int graph[][500],int v,int visit[],int point)
{
    if(v==0){
        for(int j=0;j<point;j++){
            visit[j]=0;
        }
    }
    printf("%d ",v);
    visit[v]=1;
    for(int i=0;i<point;i++){
        if(graph[v][i]==1){
            if(visit[i]==0){
                DFS(graph,i,visit,point);
            }
        }
    }
}
void BFS(int graph[][500],int v,int visit[],int point)
{
    int line[500],head=0,rear=-1;
    for(int j=0;j<point;j++){
        visit[j]=0;
    }
    for(rear++,line[rear]=v;head<=rear;){
        printf("%d ",line[head]);
        visit[line[head]]=1;
        for(int i=0;i<point;i++){
            if(graph[i][line[head]]==1){
                if(visit[i]==0){
                    rear++;
                    line[rear]=i;
                    visit[i]=1;
                }
            }
        }
        head++;
    }
}

