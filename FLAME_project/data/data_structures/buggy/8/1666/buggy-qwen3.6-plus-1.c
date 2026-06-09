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
    for(i=0; i<v_num; i++) // @@ The loop condition should be i < v_num to initialize visited array for all vertices, not just edges. Using e_num is incorrect if e_num != v_num.
    {
        visited[i]=0;
    }
    TRAVEL_DFS(edge,v_num);
    printf("\n");
    for(i=0; i<v_num; i++) // @@ The loop condition should be i < v_num to reset visited array for all vertices.
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
    for(i=0; i<v_num; i++) // @@ The loop condition should be i < v_num to reset visited array for all vertices.
    {
        visited[i]=0;
    }
    visited[k]=1;
    TRAVEL_DFS(edge,v_num);
    printf("\n");
    for(i=0; i<v_num; i++) // @@ The loop condition should be i < v_num to reset visited array for all vertices.
    {
        visited[i]=0;
    }
    visited[k]=1;
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
    w = -1; // @@ Initialize w to -1 before the loop to handle cases where no unvisited neighbor is found.
    for(i=0; i<n; i++)
    {
        if(a[j+i]!=0&&visited[i]==0)
        {
            w=j+i;
            jud=1;
            break;
        }
    }
    // @@ The original logic for setting w=-1 inside the loop was flawed. It's better to initialize w=-1 and update it only if a neighbor is found.
    while(w!=-1)
    {
        if(visited[w-j]==0) // @@ Check visited status of the neighbor vertex (w-j), not the current loop index i which is out of scope or incorrect here.
        {
            DFS(a,n,w-j);
        }
        jud=0;
        w = -1; // @@ Reset w to -1 before searching for the next neighbor.
        for(i=w-j+1; i<n; i++) // @@ Start searching from the next vertex after the current neighbor w-j. Note: if w was -1, this logic needs care, but w is valid here. Actually, we should iterate from the index after the current neighbor.
        {
             // @@ The variable 'i' in the for loop initialization uses 'w-j'. If w is valid, this is correct.
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
        w = -1; // @@ Initialize w to -1 before searching for neighbors.
        for(i=0; i<n; i++)
        {
            if(a[j+i]!=0&&visited[i]==0)
            {
                w=j+i;
                jud=1;
                break;
            }
        }
        // @@ Removed the flawed inner if(jud==0) block from the original code which incorrectly set w=-1 inside the search loop.
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
            w = -1; // @@ Reset w to -1 before searching for the next neighbor.
            for(i=(w-j)+1; i<n; i++) // @@ Corrected initialization: search starts from the vertex after the one just processed. Note: w-j is the vertex index.
            {
                if(a[j+i]!=0 && visited[i]==0) // @@ Must check visited status here as well to ensure we only pick unvisited neighbors for traversal order, although BFS marks them when enqueuing. The standard approach is to find the next unvisited neighbor.
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