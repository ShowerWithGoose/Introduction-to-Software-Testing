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
    printf("%d %d %d",num[p]+1,line[p].x1,line[p].y1); // @@ [The program does not handle cases where the longest chain does not start at the first segment in sorted order; it only checks forward connections from each starting segment but fails to consider that a longer chain might be formed by connecting segments that appear earlier in the array after sorting. Additionally, the sorting function is incomplete—it only sorts by x1 and ignores y1 when x1 values are equal, which may cause incorrect ordering needed for proper chaining.]
    return 0;
}