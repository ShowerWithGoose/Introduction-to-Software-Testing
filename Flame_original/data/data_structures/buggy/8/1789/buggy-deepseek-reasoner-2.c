#include<stdio.h>
#include<stdlib.h>
int p[100][100];
int visited[100]={0};
void gbl1(int n,int n1)
{
    printf("%d ",n);
    visited[n]=1;
     for(int i=0;i<100;i++) // @@ C89 does not allow variable declaration inside for loop initializer; must declare 'i' before the loop.
        if(visited[p[n][i]]==0&&p[n][i]!=-1)
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
      for(int i=0;i<100;i++) // @@ C89: variable declaration in for loop not allowed; also logical error: using 'front' instead of 'list[front]' to index p.
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
    for(int i=0;i<n1;i++) // @@ C89: variable declaration in for loop not allowed.
    {
        for(int j=0;j<100;j++) // @@ C89: variable declaration in for loop not allowed.
        {
            p[i][j]=-1;
        }
    }
int a=0; // @@ C89: declaration after statement (previous statements are the for loops) is not allowed; must declare variables at the beginning of the block.
//printf("%d %d",n1,n2);
    for(int i=0;i<n2;i++) // @@ C89: variable declaration in for loop not allowed.
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
    int temp; // @@ C89: declaration after statement (previous for loops) is not allowed.
    for(int i=0;i<n1;i++) // @@ C89: variable declaration in for loop not allowed.
    {
        for(int j=0;p[i][j]!=-1;j++) // @@ C89: variable declaration in for loop not allowed.
        {
            for(int k=0;p[i][k+1]!=-1;k++) // @@ C89: variable declaration in for loop not allowed.
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
for(int i=0;i<100;i++) // @@ C89: variable declaration in for loop not allowed.
    visited[i]=0;
    gbl2(0,n1);
for(int i=0;i<100;i++) // @@ C89: variable declaration in for loop not allowed.
    visited[i]=0;
    printf("\n");
for(int i=0;i<n1;i++) // @@ C89: variable declaration in for loop not allowed.
{
    for(int j=0;j<100;j++) // @@ C89: variable declaration in for loop not allowed.
    {
        if(p[i][j]==d3)
            p[i][j]=-1;
    }
}
gbl1(0,n1);
printf("\n");
for(int i=0;i<100;i++) // @@ C89: variable declaration in for loop not allowed.
    visited[i]=0;
    gbl2(0,n1);
for(int i=0;i<100;i++) // @@ C89: variable declaration in for loop not allowed.
    visited[i]=0;
}