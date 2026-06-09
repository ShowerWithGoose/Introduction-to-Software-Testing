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
          gbl1(p[n][i],n1); // @@ [The adjacency list is not sorted properly during traversal; the loop iterates over fixed 100 entries instead of only valid neighbors, and does not ensure ascending order access as required.]

}
void gbl2(int n,int n1)
{
    int list[100];
    int front=0;
    int top=0;
    //printf("%d ",n);
    visited[n]=1;
    list[0]=n;
    while(top-front>=0) // @@ [Incorrect queue condition: should be 'front <= top' or similar; current condition may cause out-of-bounds access or infinite loop. Also, BFS prints node when dequeuing but marks visited when enqueuing inconsistently with DFS behavior.]
    {
      printf("%d ",list[front]);
      for(int i=0;i<100;i++)
        if(visited[p[front][i]]==0&&p[front][i]!=-1)
          {
              top++;
              list[top]=p[front][i];
              visited[p[front][i]]=1;
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
            for(int k=0;p[i][k+1]!=-1;k++) // @@ [Bubble sort implementation is flawed: inner loop condition may access p[i][k+1] beyond valid range if last element is -1 but previous isn't handled correctly. Sorting may not complete fully due to early termination.]
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
            p[i][j]=-1; // @@ [Only removes the vertex value from adjacency lists but doesn't shift remaining elements left, leaving gaps (-1 values in middle), which breaks traversal logic that assumes contiguous valid neighbors until first -1.]
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