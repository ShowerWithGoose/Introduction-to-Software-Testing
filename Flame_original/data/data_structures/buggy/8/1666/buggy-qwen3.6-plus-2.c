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
    for(i=0; i<e_num; i++) // @@ Error: loop bound should be v_num to reset visited array for all vertices, as e_num may be less than v_num.
    {
        visited[i]=0;
    }
    TRAVEL_DFS(edge,v_num); // @@ Compilation Error: 'edge' is a 2D array but function expects a 1D array pointer, causing incompatible pointer type.
    printf("\n");
    for(i=0; i<e_num; i++) // @@ Error: loop bound should be v_num.
    {
        visited[i]=0;
    }
    TRAVEL_BFS(edge,v_num); // @@ Compilation Error: type mismatch between 2D array and 1D array parameter.
    scanf("%d",&k);
    for(i=0;i<v_num;i++)
    {
        edge[k][i]=0;
        edge[i][k]=0;
    }
    for(i=0; i<e_num; i++) // @@ Error: loop bound should be v_num.
    {
        visited[i]=0;
    }
    visited[k]=1;
    TRAVEL_DFS(edge,v_num); // @@ Compilation Error: type mismatch.
    printf("\n");
    for(i=0; i<e_num; i++) // @@ Error: loop bound should be v_num.
    {
        visited[i]=0;
    }
    visited[k]=1;
    TRAVEL_BFS(edge,v_num); // @@ Compilation Error: type mismatch.
    return 0;
}
void TRAVEL_DFS(int a[],int n) // @@ Compilation Error: parameter type should be int a[][100] or int (*a)[n] to correctly receive the 2D array.
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
void DFS(int a[],int n,int v) // @@ Compilation Error: parameter type mismatch for 2D array.
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
        if(jud==0)
        {
            w=-1;
        }
    }
    while(w!=-1)
    {
        if(visited[i]==0) // @@ Logic Error: 'i' equals n here after the loop, causing out-of-bounds access. Should be 'visited[w-j]==0'.
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
void TRAVEL_BFS(int a[],int n) // @@ Compilation Error: parameter type mismatch for 2D array.
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
void BFS(int a[],int n,int v) // @@ Compilation Error: parameter type mismatch for 2D array.
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
            if(jud==0)
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
                if(a[j+i]!=0) // @@ Logic Error: missing '&& visited[i]==0' check, which may lead to processing already visited vertices or incorrect queue behavior.
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