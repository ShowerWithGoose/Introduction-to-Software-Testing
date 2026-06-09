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
    // @@ The original logic for setting w=-1 inside the loop was flawed and unreachable or incorrect.
    while(w!=-1)
    {
        // @@ The variable 'i' here is from the previous loop scope or uninitialized in this context if w was set in first loop. 
        // However, the recursive call uses w-j which is the correct vertex index.
        // The check visited[i] is wrong, it should be visited[w-j] or visited[i] if i corresponds to w-j. 
        // In the first iteration of while, i is n (from break). This is a bug.
        // We should check visited for the vertex w-j.
        if(visited[w-j]==0) // @@ Check visited status of the correct vertex (w-j), not 'i' which is likely out of bounds or stale.
        {
            DFS(a,n,w-j);
        }
        jud=0;
        w = -1; // @@ Reset w to -1 before searching for next neighbor.
        for(i=w-j+1; i<n; i++) // @@ Start search from next vertex. Note: if w was -1, w-j is negative. This logic is tricky.
        {
             // If w was -1 initially, this loop shouldn't run or should handle it. 
             // But since we are in while(w!=-1), w is valid index relative to row start.
             // Actually, standard DFS iteration: find next unvisited neighbor after current w.
             // The index of current neighbor is w-j. Next index is w-j+1.
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
        // @@ Removed incorrect inner if(jud==0) w=-1 from inside the for loop as it's handled after.
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
            w = -1; // @@ Reset w before searching for next neighbor.
            for(i=(w==-1 ? 0 : w-j+1); i<n; i++) // @@ Logic correction: if w is -1 (first time), start from 0? No, w is set in previous block. 
            // Wait, if w was set in the initial for loop, w-j is the index. Next is w-j+1.
            // If w was -1, the while loop wouldn't execute.
            // So here w is valid.
            for(i=w-j+1; i<n; i++)
            {
                if(a[j+i]!=0 && visited[i]==0) // @@ Must check visited[i] here as well to ensure we only pick unvisited neighbors for traversal order consistency, although BFS marks them when enqueuing. 
                // The problem requires visiting adjacent vertices in ascending order. 
                // The original code didn't check visited in the second inner loop, which might lead to picking already visited/queued nodes if not careful, but primarily it needs to find the *next* unvisited one.
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