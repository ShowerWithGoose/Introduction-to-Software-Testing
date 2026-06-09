#include<stdio.h>
#include<stdlib.h>
int p[100][100];
int visited[100]={0};
void gbl1(int n,int n1)
{
    printf("%d ",n);
    visited[n]=1;
     for(int i=0;i<100;i++)
        if(visited[p[n][i]]==0&&p[n][i]!=-1)
          gbl1(p[n][i],n1); // @@ [The adjacency list is not guaranteed to be sorted in ascending order during DFS recursion because the loop iterates over fixed 100 slots, and unsorted or sparse entries may cause visiting neighbors in incorrect order. Also, p[n][i] might be -1 for many i, but condition checks it; however, the bigger issue is that the graph representation does not ensure ascending traversal order due to how neighbors are stored and accessed.]

}
void gbl2(int n,int n1)
{
    int list[100];
    int front=0;
    int top=0;
    //printf("%d ",n);
    visited[n]=1;
    list[0]=n;
    while(top-front>=0) // @@ [This condition should be 'front <= top' or 'front <= top && front < 100', but as written, when front > top, top - front becomes negative, so loop stops correctly. However, the real error is that 'front' is incremented unconditionally even when no new nodes are added, and the BFS accesses p[front][i] where 'front' is an index into the queue, not the vertex label. It should use list[front] as the current vertex, not 'front' itself.]
    {
      printf("%d ",list[front]);
      for(int i=0;i<100;i++)
        if(visited[p[front][i]]==0&&p[front][i]!=-1) // @@ [Here, 'front' is the queue index, not the vertex. Should be p[list[front]][i] instead of p[front][i]. This causes accessing wrong adjacency lists, leading to incorrect BFS traversal.]
          {
              top++;
              list[top]=p[front][i]; // @@ [Same error: should be p[list[front]][i]]
              visited[p[front][i]]=1; // @@ [Same error: should be p[list[front]][i]]
          }
          front++;
    }
}

int main()
{
    int n1,n2,d1,d2,d3;
    scanf("%d %d",&n1,&n2);
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<100;j++)
        {
            p[i][j]=-1;
        }
    }
int a=0;
//printf("%d %d",n1,n2);
    for(int i=0;i<n2;i++)
    {
        scanf("%d %d",&d1,&d2);
        //printf("%d %d\n",d1,d2);
        a=0;
       while(p[d1][a]!=-1)
       {
           a++;
       }
       p[d1][a]=d2;
        a=0;
       while(p[d2][a]!=-1)
       {
           a++;
       }
       p[d2][a]=d1;

    }
    /*for(int i=0;i<n1;i++)
        {for(int j=0;p[i][j]!=-1;j++)
    {
        printf("%d:%d ",i,p[i][j]);
    }
    printf("\n");
    }*/
    int temp;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;p[i][j]!=-1;j++)
        {
            for(int k=0;p[i][k+1]!=-1;k++)
            {
             if(p[i][k]>p[i][k+1])
            {
                temp=p[i][k];
                p[i][k]=p[i][k+1];
                p[i][k+1]=temp;
            }
            }
        }
    }
   /*for(int i=0;i<n1;i++)
        {for(int j=0;p[i][j]!=-1;j++)
    {
        printf("%d ",p[i][j]);
    }
    printf("\n");
    }*/
    scanf("%d",&d3);
gbl1(0,n1);
printf("\n");
for(int i=0;i<100;i++)
    visited[i]=0;
    gbl2(0,n1);
for(int i=0;i<100;i++)
    visited[i]=0;
    printf("\n");
for(int i=0;i<n1;i++)
{
    for(int j=0;j<100;j++)
    {
        if(p[i][j]==d3)
            p[i][j]=-1;
    }
}
gbl1(0,n1);
printf("\n");
for(int i=0;i<100;i++)
    visited[i]=0;
    gbl2(0,n1);
for(int i=0;i<100;i++)
    visited[i]=0;
}