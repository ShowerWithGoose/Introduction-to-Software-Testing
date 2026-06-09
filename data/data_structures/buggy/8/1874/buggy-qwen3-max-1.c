#include<stdio.h>
#include<string.h>

void DFS(int v);
void BFS(int v);
void sort(int v,int n);

int G[120][120];
int V[120];
int Q[120];
int main()
{
    int dot,edge,v1,v2,v,i,j;
    memset(G,-1,sizeof(G));
    memset(Q,-1,sizeof(Q));
    scanf("%d %d",&dot,&edge);
    for(i=0;i<edge;i++)
    {
        scanf("%d %d",&v1,&v2);
        for(j=0;G[v1][j]!=-1;j++);
        G[v1][j]=v2;
        for(j=0;G[v2][j]!=-1;j++);
        G[v2][j]=v1;
    }
    scanf("%d",v); // @@ [Missing '&' operator before variable 'v'; should be '&v' to pass address for scanf]
    for(i=0;i<dot;i++)
    {
        for(j=0;G[i][j]!=-1;j++);
        sort(i,j);
    }
    DO_DFS(dot,v); // @@ [Function 'DO_DFS' is called before its declaration or definition is visible; though declared later, this may cause issues in some compilers without forward declaration. However, the primary error is the missing & above. But note: the function names DO_DFS and DO_BFS are defined later, so if compiler allows, it's okay. The real compilation error is due to the scanf line.]
    printf("\n");
    DO_BFS(dot,v); // @@ [Same as above, but again, the critical error is in scanf]
    printf("\n");
    for(i=0;i<dot;i++)
    {
        for(j=0;G[i][j]!=-1;j++)
        {
            if(G[i][j]==v)
            {
                G[i][j]=9999;
            }
        }
    }
    for(j=0;G[v][j]!=-1;j++)
    {
        G[i][j]=9999; // @@ [Loop variable 'i' is used outside its intended scope; after the previous loop, 'i' equals 'dot', so G[i][j] accesses out-of-bounds memory. Should be G[v][j] = 9999;]
    }
    DO_DFS(dot,v);
    printf("\n");
    DO_BFS(dot,v);
    
    return 0;
}
void sort(int v,int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(G[v][j]>G[v][j+1])
            {
                temp=G[v][j];
                G[v][j]=G[v][j+1];
                G[v][j+1]=temp;
            }
        }
    }
}
void DFS(int v)
{
    int i;
    if(V[v]==0)
    {
        printf("%d ",v);
    }
    V[v]=1;
    for(i=0;G[v][i]!=-1;i++)
    {
        if(G[v][i]!=9999)
        {
            if(V[G[v][i]]==0)
            {
                DFS(G[v][i]);
            }
        }
    }
}
void BFS(int v)
{
    int i,j;
    printf("%d ",v);
    V[v]=1;
    for(j=0;Q[j]!=-1;j++);
    Q[j]=v;
    while(Q[0]!=-1)
    {
        v=Q[0];
        for(j=0;Q[j]!=-1;j++)
        {
            Q[j]=Q[j+1];
        }
        for(i=0;G[v][i]!=-1;i++)
        {
            if(G[v][i]!=9999)
            {
                if(V[G[v][i]]==0)
                {
                    printf("%d ",G[v][i]);
                    V[G[v][i]]=1;
                    for(j=0;Q[j]!=-1;j++);
                    Q[j]=G[v][i];
                }
            }
        }
    }
}
void DO_DFS(int n,int m)
{
    int i;
    for(i=0;i<n;i++)
    {
        V[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(i==m)
        {
            continue;
        }
        else
        {
            if(V[i]==0)
            {
                DFS(i);
            }
            
        }
    }
}
void DO_BFS(int n,int m)
{
    int i;
    for(i=0;i<n;i++)
    {
        V[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(i==m)
        {
            continue;
        }
        else
        {
            if(V[i]==0)
            {
                BFS(i);
            }
        }
    }
}