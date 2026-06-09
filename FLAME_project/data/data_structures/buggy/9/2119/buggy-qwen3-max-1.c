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
    }} // @@ [The inner loop only checks forward connections from the current segment, but does not continue chaining beyond immediate next segment. It assumes segments are sorted and connected sequentially, but fails to follow the full chain of connected segments because 'q' is updated but the loop continues with fixed 'k' increment, missing potential longer chains that may start later in the array.]
    for(i=0;i<n;i++)
    {
        if(num[i]>max)
        {
            max=num[i];
            p=i;
        }
    }
    printf("%d %d %d",num[p]+1,line[p].x1,line[p].y1); // @@ [Because the chaining logic in the previous loop is flawed, num[i] may not reflect the true length of the continuous segment starting at i, leading to incorrect output. For the given test case, it might count only 1 connection (so num[0]=1) and output 2 12 12 correctly by accident, but the logic is still broken for more complex cases. However, in this specific test case, the output matches expected, so the real issue may be elsewhere. But note: the problem says the buggy output was too long and showed input lines, meaning the program printed all segments due to the debug print loop. The actual error causing Wrong Answer is likely the unnecessary printing of all segments, which violates output format.]
}