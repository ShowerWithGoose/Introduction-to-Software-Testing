#include <stdio.h>
#include <string.h>
struct Line {
    int x1;
    int y1;
    int x2;
    int y2;
};
void sort(struct Line line[],int s)
{
    int m,n;
    struct Line tmp;
    for(m=0;m<s;m++)
        for(n=m;n<s;n++)
        {
            if(line[m].x1>line[n].x1)
            {
                tmp=line[m];
                line[m]=line[n];
                line[n]=tmp;
            }
        }
}
int main()
{   struct Line line[100];
    int n,i,j=0,p=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    sort(line,n);
    for(i=0;i<n;i++)
    {printf("%d %d %d %d\n",line[i].x1,line[i].y1,line[i].x2,line[i].y2);}
    int num[100]={0},q,k,max=0;
    for(i=0;i<n;i++)
    {  q=i;
        for(k=i+1;k<n;k++){
        if(line[q].x2==line[k].x1&&line[q].y2==line[k].y1)
        {   q=k;
           num[i]+=1;
        }
    }}
    for(i=0;i<n;i++)
    {
        if(num[i]>max)
        {
            max=num[i];
            p=i;
        }
    }
    printf("%d %d %d",num[p]+1,line[p].x1,line[p].y1); // @@ [The logic fails to correctly chain segments that are not adjacent in the sorted array. The inner loop only checks forward from i+1 and assumes segments are chained in order, but a continuous line may require following connections that jump over unconnected segments. Also, the sorting is only by x1, not considering y1, which may misorder segments with same x1 but different y1, violating problem assumptions.]
    return 0;
}