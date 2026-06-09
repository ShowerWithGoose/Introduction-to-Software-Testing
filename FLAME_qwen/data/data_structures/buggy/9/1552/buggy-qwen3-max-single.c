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

    for(i=1;i<n;i++)
    {
      for(j=i-1;j>=0;j--)
      {                
        if(lianxu[i]==0) continue;
        if((line[i].x1==line[j].x1)&&(line[i].y1==line[j].y1))
        {
            line[i].x1=line[j].x2;
            line[i].y1=line[j].y2;
            lianxu[i]=lianxu[i]+lianxu[j];
            lianxu[j]=0;            
        }
        else if((line[i].x1==line[j].x2)&&line[i].y1==line[j].y2)
        {
            line[i].x1=line[j].x1;
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
    if(line[start].x1<line[start].x2)
    {
        xbegin=line[start].x1;
        ybegin=line[start].y1;
    }
    else if(line[start].x2<line[start].x1)
    {
        xbegin=line[start].x2;
        ybegin=line[start].y2;        
    }
    else
    {
        xbegin=line[start].x1;
        ybegin=line[start].y1;
    } // @@ [The original code does not handle the case where x1 == x2, which can occur after merging segments. According to problem constraints, original segments have x1 < x2, but after merging (e.g., connecting at endpoints), the updated segment might end up with equal x-coordinates if logic incorrectly modifies endpoints. However, more critically, the merging logic itself is flawed: it modifies the current segment's endpoints during traversal, which breaks future comparisons and violates the invariant that x1 < x2. This leads to incorrect continuity tracking and potentially x1 == x2, causing undefined behavior in start point selection.]

    printf("%d %d %d",max,xbegin,ybegin);
    return 0;
}