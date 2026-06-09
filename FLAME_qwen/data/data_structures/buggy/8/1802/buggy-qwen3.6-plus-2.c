#include <stdio.h> // @@ Missing #include <string.h> which is required for the memset function
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
    int i=0,i1=0,stack[100],point=1,finger=0,tep; // @@ Variable 'tep' is uninitialized when type==1, causing undefined behavior or compilation warning/error
    stack[0]=a;
    if(type==2)
    tep=del;
    while(finger<vet-tep)
    {
    while(i<vet)
    {
        if(graph[stack[finger]][i]==1&&visit[i]==0&&type==1)
        {
        stack[point]=i;
        point++;
        }
        else if(graph_del[stack[finger]][i]==1&&visit[i]==0&&type==2)
        {
        stack[point]=i;
        point++;
        }
        i++;
    }
    visit[stack[finger]]=1;
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
while(~scanf("%d",&type)) // @@ Loop reads until EOF, but only one deletion vertex is expected; should be a single scanf call
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
memset(visit,0,100);printf("\n"); // @@ memset size 100 only clears first 25 integers, should be sizeof(visit)
wfs(0,1);
memset(visit,0,100);printf("\n"); // @@ memset size 100 only clears first 25 integers, should be sizeof(visit)
dfs(0,2);
memset(visit,0,100);printf("\n"); // @@ memset size 100 only clears first 25 integers, should be sizeof(visit)
wfs(0,2);



}