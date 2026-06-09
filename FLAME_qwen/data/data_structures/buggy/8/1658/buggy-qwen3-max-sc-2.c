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
    deep(); // @@ [deep() function is empty and does nothing, so DFS traversal is missing]
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
        deep(); // @@ [deep() function is empty and does nothing, so DFS traversal after deletion is missing]
        back();
    wide(0); // @@ [BFS starts from 0 even if 0 was deleted, but problem states deleted vertex is not 0, so this may be okay; however, 'visit' array is reset in back(), but 'avalible' is not used in traversal logic]
    
    
 } 
 void deep()
 {
     
 } // @@ [This function is completely empty—it should implement DFS traversal starting from 0, visiting neighbors in ascending order, but it does nothing]
 void wide(int temp)
 {
 
     
     int i=0;
    if(visit==0) // @@ [Incorrect condition: 'visit' is an array, comparing it to 0 is always false (non-null pointer). Should be 'if(visit[temp]==0)']
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
         wide(dui[start++]);
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