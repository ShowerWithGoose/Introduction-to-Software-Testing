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
          gbl1(p[n][i],n1); // @@ [The adjacency list is not guaranteed to be sorted after deletion, and the loop iterates over fixed 100 entries regardless of actual neighbors, possibly including invalid or unsorted neighbors. Also, recursive DFS does not ensure ascending order traversal because it doesn't sort neighbors before recursing.]

}
void gbl2(int n,int n1)
{
    int list[100];
    int front=0;
    int top=0;
    //printf("%d ",n);
    visited[n]=1;
    list[0]=n;
    while(top-front>=0) // @@ [Condition should be 'front <= top' or similar; current condition may cause out-of-bounds access when queue is empty but front > top. Also, BFS does not process neighbors in ascending order because it uses raw adjacency list without ensuring sorted access during traversal.]
    {
      printf("%d ",list[front]);
      for(int i=0;i<100;i++)
        if(visited[p[front][i]]==0&&p[list[front]][i]!=-1) // @@ [Uses p[front][i] instead of p[list[front]][i] in condition check, leading to incorrect neighbor access. Should use list[front] as current node.]
          {
              top++;
              list[top]=p[front][i]; // @@ [Same issue: should use p[list[front]][i], not p[front][i].]
              visited[p[front][i]]=1; // @@ [Same issue again.]
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
// @@ [After deletion, the adjacency lists are not re-sorted. Since the problem requires visiting adjacent vertices in ascending order, the removal of vertex d3 may leave unsorted or sparse -1 entries that break the ordering assumption in traversal functions.]
gbl1(0,n1);
printf("\n");
for(int i=0;i<100;i++)
    visited[i]=0;
    gbl2(0,n1);
for(int i=0;i<100;i++)
    visited[i]=0;
}