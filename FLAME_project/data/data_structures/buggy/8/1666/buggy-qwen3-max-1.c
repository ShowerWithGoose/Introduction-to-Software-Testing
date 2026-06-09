#include <stdio.h>
#include <stdlib.h>
void TRAVEL_DFS(int a[],int n);
void DFS(int a[],int n,int v);
void TRAVEL_BFS(int a[],int n);
void BFS(int a[],int n,int v);
int QUE[100]= {};
int front=-1;
int rear=-1;
int visited[100]= {};
int main()
{
    int v_num;
    int e_num;
    scanf("%d%d",&v_num,&e_num);
    int i,j,k;
    int edge[v_num][v_num];
    for(i=0; i<v_num; i++)
    {
        for(j=0; j<v_num; j++)
        {
            edge[i][j]=0;
        }
    }
    for(i=0; i<e_num; i++)
    {
        scanf("%d %d",&j,&k);
        edge[j][k]=1;
        edge[k][j]=1;
    }
    for(i=0; i<e_num; i++) // @@ [Should initialize visited[0..v_num-1], not just up to e_num-1. If e_num < v_num, some vertices remain uninitialized.]
    {
        visited[i]=0;
    }
    TRAVEL_DFS(edge,v_num);
    printf("\n");
    for(i=0; i<e_num; i++) // @@ [Same issue: should reset visited[0..v_num-1], not just 0..e_num-1.]
    {
        visited[i]=0;
    }
    TRAVEL_BFS(edge,v_num);
    scanf("%d",&k);
    for(i=0;i<v_num;i++)
    {
        edge[k][i]=0;
        edge[i][k]=0;
    }
    for(i=0; i<e_num; i++) // @@ [Again, should reset visited[0..v_num-1]; also, setting visited[k]=1 below is redundant if we properly reset all.]
    {
        visited[i]=0;
    }
    visited[k]=1; // @@ [Unnecessary and potentially harmful: vertex k is already disconnected, but marking it visited may interfere if traversal accidentally includes it (though unlikely). More critically, other vertices beyond e_num may still be unreset.]
    TRAVEL_DFS(edge,v_num);
    printf("\n");
    for(i=0; i<e_num; i++) // @@ [Same initialization range error: should be v_num, not e_num.]
    {
        visited[i]=0;
    }
    visited[k]=1; // @@ [Same as above: incorrect handling of visited array size and unnecessary marking.]
    TRAVEL_BFS(edge,v_num);
    return 0;
}
void TRAVEL_DFS(int a[],int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        if(visited[i]==0)
        {
            DFS(a,n,i);
        }
    }
}
void DFS(int a[],int n,int v)
{
    int i,j;
    int jud=0;
    int w;
    printf("%d ",v);
    visited[v]=1;
    j=v*n;
    for(i=0; i<n; i++)
    {
        if(a[j+i]!=0&&visited[i]==0)
        {
            w=j+i;
            jud=1;
            break;
        }
        if(jud==0) // @@ [This condition is inside the loop and executes on every iteration where jud==0, which is wrong. It should only set w=-1 after the loop if no neighbor found.]
        {
            w=-1;
        }
    }
    while(w!=-1)
    {
        if(visited[i]==0) // @@ [Here, 'i' is the loop variable from the previous for-loop; its value is undefined or leftover (likely n), so visited[i] is out-of-bounds or incorrect. Should use 'w - j' as the vertex index.]
        {
            DFS(a,n,w-j);
        }
        jud=0;
        for(i=w-j+1; i<n; i++)
        {
            if(a[j+i]!=0&&visited[i]==0)
            {
                w=j+i;
                jud=1;
                break;
            }
        }
        if(jud==0)
        {
            w=-1;
        }
    }
}
void TRAVEL_BFS(int a[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(visited[i]==0)
        {
            BFS(a,n,i);
        }
    }
}
void BFS(int a[],int n,int v)
{
    int w;
    int i,j=v*n,jud=0;
    printf("%d ",v);
    visited[v]=1;
    rear=(rear+1)%100;
    QUE[rear]=v;
    while(rear!=front)
    {
        front=(front+1)%100;
        v=QUE[front];
        j=v*n;
        for(i=0; i<n; i++)
        {
            if(a[j+i]!=0&&visited[i]==0)
            {
                w=j+i;
                jud=1;
                break;
            }
            if(jud==0) // @@ [Same error as in DFS: this sets w=-1 repeatedly inside the loop instead of after it.]
            {
                w=-1;
            }
        }
        while(w!=-1)
        {

            if(visited[w-j]==0)
            {
                printf("%d ",w-j);
                rear=(rear+1)%100;
                QUE[rear]=w-j;
                visited[w-j]=1;
            }
            jud=0;
            for(i=w-j+1; i<n; i++)
            {
                if(a[j+i]!=0) // @@ [Missing check for visited[i]==0; may enqueue already visited nodes, causing duplicates or infinite loops.]
                {
                    w=j+i;
                    jud=1;
                    break;
                }
            }
            if(jud==0)
            {
                w=-1;
            }

        }


    }

}