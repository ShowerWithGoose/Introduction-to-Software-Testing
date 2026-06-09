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
          gbl1(p[n][i],n1); // @@ [The adjacency list is not sorted properly during traversal; the loop iterates over all 100 slots instead of only valid neighbors, and does not ensure ascending order access because it relies on stored order but may skip or revisit due to -1 gaps.]

}
void gbl2(int n,int n1)
{
    int list[100];
    int front=0;
    int top=0;
    //printf("%d ",n);
    visited[n]=1;
    list[0]=n;
    while(top-front>=0)
    {
      printf("%d ",list[front]);
      for(int i=0;i<100;i++)
        if(visited[p[front][i]]==0&&p[front][i]!=-1)
          {
              top++;
              list[top]=p[front][i];
              visited[p[front][i]]=1; // @@ [Marking visited when enqueuing can cause incorrect BFS ordering or missed nodes if multiple paths exist; also, iterating over all 100 slots without checking actual neighbor count leads to inefficiency and potential errors.]
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
    printf("\n"); // @@ [This printf prints a newline after BFS before deletion, but according to expected output format, there should be no extra blank line between the two groups (before/after deletion). However, in this test case, the outputs match visually. The real issue lies in traversal logic.]

for(int i=0;i<n1;i++)
{
    for(int j=0;j<100;j++)
    {
        if(p[i][j]==d3)
            p[i][j]=-1; // @@ [This only removes one occurrence of d3 from each row, but doesn't shift remaining elements left, leaving -1 gaps that break the assumption in traversal loops that neighbors are contiguous until first -1. This causes DFS/BFS to potentially skip valid neighbors that appear after a -1 gap.]
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