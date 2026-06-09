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
    deep(); // @@ [The 'deep' function is defined as empty, so DFS traversal does nothing and produces no output.]
    back();
    wide(0);
    back();
    
    int todelete;
    scanf("%d",&todelete);
    int j;
    avalible[todelete]=1;
    i=0;
    while(i<point)
    {
        a[i][todelete]=0;
        a[todelete][i] =0;
    //printf("####\n");
        i++;
    }
//    test();
        deep(); // @@ [Again, 'deep' is empty, so no DFS output after deletion.]
        back();
    wide(0); // @@ [BFS uses global 'start' and 'end', but 'back()' resets them before this call; however, 'visit' array may not be properly reset for vertex 0 if it was marked during prior BFS due to missing reset before second wide(0). Also, 'wide' has logic errors in traversal order and recursion usage.]
    
    
 } 
 void deep()
 {
     
 } // @@ [Empty DFS implementation – should perform recursive DFS starting from 0, visiting neighbors in ascending order.]
 void wide(int temp)
 {
 
     
     int i=0;
    if(visit==0) // @@ [Incorrect condition: 'visit' is an array, so 'visit==0' compares address of array to 0, always false. Should be 'if(visit[temp]==0)'.]
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
         wide(dui[start++]); // @@ [Using recursion for BFS is unconventional and may cause incorrect traversal order or stack overflow; also, 'start' is global and modified during recursion, leading to unpredictable behavior.]
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
         visit[i]=0; // @@ [This resets the entire visit array, which is correct between traversals, but note that after vertex deletion, the deleted vertex should be skipped, not just unvisited. However, since edges to it are removed, this may be acceptable. Main issue is elsewhere.]
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