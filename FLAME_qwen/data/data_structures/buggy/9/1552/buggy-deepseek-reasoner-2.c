#include <stdio.h>
struct xianduan{
    int x1;int y1;
    int x2;int y2;
};
struct xianduan line[101]; 
int main()
{
    int n;
    int j;
    int max=0;////最大线段数
    int lianxu[101];
    int xbegin=0,ybegin=0;    
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        lianxu[i]=1;/////该线段及以上连续的线段 
    }
    for(i=0;i<n;i++)
    {
       scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);        
    }

    for(i=1;i<n;i++) // @@ This loop only checks previous segments in input order, missing connections that involve later segments. It cannot build a chain that requires merging non-sequential indices.
    {
      for(j=i-1;j>=0;j--) // @@ Only iterates backward from i-1 to 0, so if a segment connects to a later segment (j>i), it will not be found.
      {                
        if(lianxu[i]==0) continue;
        if((line[i].x1==line[j].x1)&&(line[i].y1==line[j].y1))
        {
            line[i].x1=line[j].x2; // @@ Modifies line[i] coordinates, but does not update line[j] (which is now considered merged). Also, this assumes the merge direction is always from j to i, but after merging, the chain's endpoints may not satisfy x1 < x2.
            line[i].y1=line[j].y2;
            lianxu[i]=lianxu[i]+lianxu[j];
            lianxu[j]=0;            
        }
        else if((line[i].x1==line[j].x2)&&line[i].y1==line[j].y2)
        {
            line[i].x1=line[j].x1; // @@ Similar issue: swapping endpoints without ensuring the final x1<x2.
            line[i].y1=line[j].y1;
            lianxu[i]=lianxu[i]+lianxu[j];
            lianxu[j]=0;            
        }
        else if((line[i].x2==line[j].x1)&&line[i].y2==line[j].y1)
        {
            line[i].x2=line[j].x2;
            line[i].y2=line[j].y2;
            lianxu[i]=lianxu[i]+lianxu[j];
            lianxu[j]=0;
        }
        else if((line[i].x2==line[j].x2)&&line[i].y2==line[j].y2)
        {
            line[i].x2=line[j].x1;
            line[i].y2=line[j].y1;
            lianxu[i]=lianxu[i]+lianxu[j];
            lianxu[j]=0;
        }                
      }    
    }
    int start=0;    
    for(i=0;i<n;i++)
    {
        if(lianxu[i]>max)
        {
            max=lianxu[i];
            start=i;
        }
    }
    if(line[start].x1<line[start].x2) // @@ After merging, the coordinates of line[start] may not correctly represent the true endpoints of the entire chain because the merging only updated line[start] but did not ensure that the chain's endpoints are correctly ordered (x1 < x2 may be violated).
    {
        xbegin=line[start].x1;
        ybegin=line[start].y1;
    }
    else if(line[start].x2<line[start].x1)
    {
        xbegin=line[start].x2;
        ybegin=line[start].y2;        
    }

    printf("%d %d %d",max,xbegin,ybegin);
    return 0;
}