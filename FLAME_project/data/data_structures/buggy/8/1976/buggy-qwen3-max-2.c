#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Graph[200][200],visit[200]={0},queue[200];
int point_num,eno_num;
void travelDFS(int v)
{
    int i;
    printf("%d ",v);
    visit[v]=1;
    for(i=0;i<point_num;i++)
    {
        if(Graph[v][i]==1&&visit[i]!=1)
            travelDFS(i);
    }
}
void travelBFS(int v)
{
    int front=0,back=1,tmp;
    queue[front]=v;
    while(front<=back)
    {
        tmp=queue[front++];
        if(visit[tmp]!=1)
        {
            printf("%d ",tmp);
            visit[tmp]=1;
            for(int i=0;i<point_num;i++)
            {
                if(Graph[v][i]==1&&visit[i]!=1) // @@ [In BFS traversal, when enqueueing neighbors of 'tmp', the code incorrectly uses 'v' (the original start vertex) instead of 'tmp' (the current vertex being processed). This causes wrong adjacency checks and leads to incorrect traversal order or missing vertices.]
                {
                    queue[back++]=i;
                }
            }
        }
        else
            continue;
    }
}
int main()
{
    int p,q,del;
    scanf("%d %d",&point_num,&eno_num);
    for(int i=0;i<eno_num;i++)
    {
        scanf("%d %d",&p,&q);
        Graph[p][q]=1;
        Graph[q][p]=1;
    }


    travelDFS(0);
    printf("\n");
    for(int i=0;i<200;i++)
        visit[i]=0;

    travelBFS(0);
    printf("\n");
    scanf("%d",&del);
    for(int i=0;i<200;i++)
        visit[i]=0;
    visit[del]=1;

    travelDFS(0);
    printf("\n");
    for(int i=0;i<200;i++)
    {
        visit[i]=0;
        queue[i]=0;
    }

    visit[del]=1;
    travelBFS(0);
    printf("\n");
    return 0;
}