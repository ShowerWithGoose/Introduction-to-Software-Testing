#include<stdio.h>
int point ;
int end=0;
     int start=0;
         int dui[130];
int way;
int avalible[200];
int a[105][105];
void deep();
void wide(int temp);
int visit[130];
void back();
void test();
int main()
{
    scanf("%d%d",&point,&way);
    int i=0;
    int r,l;
    while(i<way)
    {
        scanf("%d%d",&r,&l);
        a[r][l]=1;
        a[l][r]=1;
        i++;
    }
//    test();
    deep();
    back();
    wide(0);
    back();
    
    int todelete;
    scanf("%d",&todelete);
    int j;
    avalible[todelete]=1; // @@ The 'avalible' array is set but never checked in traversal functions. The deleted vertex should be skipped during DFS/BFS.
    i=0;
    while(i<point)
    {
        a[i][todelete]=0;
        a[todelete][i] =0;
    //printf("####\n");
        i++;
    }
//    test();
        deep();
        back();
    wide(0);
    
    
 } 
 void deep() // @@ The DFS function is completely empty. It must be implemented to recursively visit unvisited adjacent vertices in ascending order.
 {
     
 }
 void wide(int temp)
 {
 
     
     int i=0;
    if(visit==0) // @@ Incorrect condition: compares array pointer to 0 instead of checking visit status. Should be 'if(visit[temp]==0)'. Also lacks early return if already visited.
     printf("%d ",temp);
     visit[temp]=1;
     while(i<point)
     {
         if(a[temp][i]==1&&visit[i]==0)
         {
             visit[i]=1;
             printf("%d ",i);
             dui[end++]=i;
         }
         i++;
     }
     while(start<end)
     {
         wide(dui[start++]); // @@ Recursive call in BFS is logically flawed and may cause stack overflow or incorrect traversal order. BFS should be implemented iteratively using the queue.
     }
 }
 void back()
 {
     printf("\n");
     start=0;
     end=0;
     int i=0;
     for(i=0;i<120;i++)
     {
         dui[i]=0;
     }
     for(i=0;i<120;i++)
     {
         visit[i]=0;
     }
 }
 void test ()
 {
     int m,n;
     for(m=0;m<point;m++)
     {
         printf("%d:",m);
         for(n=0;n<point;n++)
         {
             printf("%d ",a[m][n]);
         }
         printf("\n");
     }
 }