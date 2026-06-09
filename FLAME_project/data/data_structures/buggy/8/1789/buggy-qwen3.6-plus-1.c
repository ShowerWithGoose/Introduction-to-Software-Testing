#include<stdio.h>
#include<stdlib.h>
int p[100][100];
int visited[100]={0};
void gbl1(int n,int n1)
{
    printf("%d ",n);
    visited[n]=1;
     for(int i=0;i<100;i++)
        if(visited[p[n][i]]==0&&p[n][i]!=-1) // @@ The loop iterates up to 100, accessing potentially uninitialized or invalid indices in the adjacency list 'p'. It should iterate only up to 'n1' or until a -1 sentinel is found, but more critically, the condition `visited[p[n][i]]` accesses `visited` with an index that might be out of bounds or invalid if `p[n][i]` is not a valid vertex (though initialized to -1, `visited[-1]` is undefined behavior). However, the main logical error here is that the DFS recursion doesn't stop correctly if the adjacency list isn't perfectly packed or if -1 checks are missed in logic flow. But looking closer at `gbl2`, there is a more significant error. Let's look at `gbl2`.
          gbl1(p[n][i],n1);

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
      for(int i=0;i<100;i++) // @@ Similar to DFS, this loops 100 times. It should only loop through valid neighbors. Accessing `p[front][i]` where `front` is an index from `list` (a vertex ID) is correct for the vertex, but iterating `i` to 100 assumes fixed size. The bigger issue is `p[front][i]`. `front` is the index in the queue/list, but it holds the vertex ID. So `p[list[front]][i]` is what is intended? No, `list[front]` is the vertex. The code uses `p[front][i]`. `front` is an integer index (0, 1, 2...), NOT the vertex ID. The vertex ID is `list[front]`. So it should be `p[list[front]][i]`. This is a critical semantic error.
        if(visited[p[front][i]]==0&&p[front][i]!=-1) // @@ Error: `front` is the queue index, not the vertex ID. The vertex ID is `list[front]`. It should be `p[list[front]][i]`. Using `front` directly as a vertex index is incorrect because `front` increments sequentially (0, 1, 2...) regardless of which vertices are actually in the graph, leading to accessing wrong rows in the adjacency matrix `p`.
          {
              top++;
              list[top]=p[front][i]; // @@ Same error: should be `p[list[front]][i]`.
              visited[p[front][i]]=1; // @@ Same error: should be `p[list[front]][i]`.
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