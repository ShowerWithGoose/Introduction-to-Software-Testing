#include <stdio.h>
int graph[100][100],graph_del[100][100],visit[100];
int vet,line,i=0,type,temp,temp1,start,del=0;
void dfs(int a,int type)
{
    int i=0,flag=0;
    if(visit[a]!=0)
    return;
    printf("%d ",a);
    visit[a]=1;
    while(i<vet)
    {
        
        if(graph[a][i]==1&&type==1)
        dfs(i,type);
        else if(graph_del[a][i]==1&&type==2)
        dfs(i,type);
        i++;
    }
}
void wfs(int a,int type)
{
    int i=0,i1=0,stack[100],point=1,finger=0,tep;
    tep=del; // @@ [tep is set to global 'del' which is already 1 before the first BFS, causing incorrect bound for the before-deletion traversal]
    stack[0]=a;
    if(type==2)
    tep=del;
    while(finger<vet-tep) // @@ [Bound uses 'tep' which is 1 for the first BFS, so it outputs only vet-1 vertices instead of vet vertices]
    {
    while(i<vet)
    {
        if(graph[stack[finger]][i]==1&&visit[i]==0&&type==1)
        {
        stack[point]=i; // @@ [Should mark visit[i]=1 when enqueuing to prevent duplicates, otherwise a vertex may be pushed multiple times]
        point++;
        }
        else if(graph_del[stack[finger]][i]==1&&visit[i]==0&&type==2)
        {
        stack[point]=i; // @@ [Same issue: missing visited marking on enqueue]
        point++;
        }
        i++;
    }
    visit[stack[finger]]=1; // @@ [Marking visited at this point is too late; should be done when enqueuing to avoid duplicates]
    finger++;i=0;
    }
    while(i<vet-tep)
    {
    printf("%d ",stack[i]);
    i++;
    }
}

int main()
{
scanf("%d %d",&vet,&line);
while(i<line)
{
    scanf("%d %d",&temp,&temp1);
    graph[temp][temp1]=1;
    graph_del[temp][temp1]=1;
    graph[temp1][temp]=1;
    graph_del[temp1][temp]=1;
    i++;
}
while(~scanf("%d",&type))
{
    i=0;del++;
    while(i<vet)
    {
        graph_del[i][type]=0;
        graph_del[type][i]=0;
        i++;
    }
}
dfs(0,1); 
memset(visit,0,100);printf("\n");
wfs(0,1);
memset(visit,0,100);printf("\n");
dfs(0,2);
memset(visit,0,100);printf("\n");
wfs(0,2);



}