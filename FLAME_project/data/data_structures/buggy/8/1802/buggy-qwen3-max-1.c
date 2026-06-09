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
void wfs(int a,int type) // @@ [The BFS implementation is incorrect: it does not process nodes level by level correctly. It scans all neighbors of the current node in one go without maintaining proper queue order, and the loop structure causes nodes to be added multiple times or skipped. Also, 'del' is incremented globally but used as offset without being reset, leading to wrong traversal length after deletion.]
{
    int i=0,i1=0,stack[100],point=1,finger=0,tep;
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
while(~scanf("%d",&type)) // @@ [This loop reads until EOF, but the problem specifies only one vertex to delete. This causes 'del' to increment once per input, but if multiple inputs exist (which they shouldn't), it breaks. More critically, 'del' starts at 0 and becomes 1 after reading the deletion vertex, but in wfs(), 'tep = del' sets tep=1 for type=2, which is correct for count adjustment, however the BFS logic itself is flawed regardless. The real issue is that this loop runs once (as expected), but the global 'del' is used incorrectly in wfs() due to poor design. However, the primary error is in wfs() logic, not this line. Still, this loop is unnecessarily complex; it should just read once. But the main bug is elsewhere.]
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