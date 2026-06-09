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
    for(i=0; i<e_num; i++) // @@ [Error: Should initialize visited array up to v_num, not e_num. This leads to uninitialized visited entries for vertices >= e_num, causing undefined behavior in traversal.]
    {
        visited[i]=0;
    }
    TRAVEL_DFS(edge,v_num);
    printf("\n");
    for(i=0; i<e_num; i++) // @@ [Error: Same issue – visited array should be reset for all vertices (0 to v_num-1), not just 0 to e_num-1.]
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
    for(i=0; i<e_num; i++) // @@ [Error: Again, visited initialization range is wrong; must cover all vertices (0 to v_num-1).]
    {
        visited[i]=0;
    }
    visited[k]=1;
    TRAVEL_DFS(edge,v_num);
    printf("\n");
    for(i=0; i<e_num; i++) // @@ [Error: Same incorrect range for resetting visited array.]
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
    for(i=0; i<n; i++)
    {
        if(a[j+i]!=0&&visited[i]==0)
        {
            w=j+i;
            jud=1;
            break;
        }
        if(jud==0) // @@ [Error: This condition is inside the loop and executes on every iteration where jud==0, overwriting w prematurely. It should be outside the loop.]
        {
            w=-1;
        }
    }
    while(w!=-1)
    {
        if(visited[i]==0) // @@ [Error: 'i' is not defined in this scope after the previous for-loop; it may retain an invalid value, leading to undefined behavior.]
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
            if(jud==0) // @@ [Error: Same logic error as in DFS – this assignment happens inside the loop incorrectly.]
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
                if(a[j+i]!=0) // @@ [Error: Missing check for visited[i]==0, which may cause revisiting nodes and incorrect BFS order.]
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