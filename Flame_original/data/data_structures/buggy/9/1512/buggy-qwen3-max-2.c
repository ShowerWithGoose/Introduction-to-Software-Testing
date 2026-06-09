#include<stdio.h>
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
};

int main()
{
    struct line lines[105];
    int n,num=0;
    int len[105]={0};
    int pas=1;
    int longest,fina_x1,fina_y1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(lines[i].x2==lines[j].x1&&lines[i].y2==lines[j].y1)
            {
                pas++; // @@ [This logic incorrectly modifies loop variable 'i' inside nested loops, causing unpredictable iteration and potential infinite loops or skipped segments. Also, 'len' array is not properly indexed to store segment counts per starting point.]
                i=j; // @@ [Modifying loop control variable 'i' inside inner loop breaks the outer loop's iteration logic.]
                j=0;
            }
            else if(j==n-1)
            {
                len[num]=pas; // @@ ['num' may exceed array bounds because it's incremented without checking against 'n'. Also, 'i=num' overwrites current outer loop index with unrelated value, corrupting traversal.]
                i=num; // @@ [Overwriting 'i' here disrupts the intended sequential processing of segments in the outer loop.]
                num++;
                pas=1;
            }
        }
    }
//向后延伸，将段数存在len里
num=0;
for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(lines[i].x1==lines[j].x1&&lines[i].y1==lines[j].y1&&i!=j) // @@ [This condition checks for identical starting points, which violates problem constraints (no three segments share an endpoint) and doesn't correctly handle backward chaining. Should check if lines[j].x2 == lines[i].x1 instead.]
            {
                len[num]++; // @@ ['len[num]' is being modified but 'num' is reused from previous loop without reset alignment to current 'i'; indexing is inconsistent.]
                i=j; // @@ [Again, modifying loop variable 'i' inside inner loop breaks iteration logic.]
                j=0;
            }
            else if(j==n-1)
            {
                i=num; // @@ [Same issue: overwriting loop variable 'i' with 'num' corrupts outer loop progression.]
                num++;
            }
        }
    }
//向前延伸，将段数加上来
    longest=len[0];
    fina_x1=lines[0].x1;
    fina_y1=lines[0].y1;
    for(int i=0;i<n;i++)
    {
        if(len[i]>longest)
        {
            longest=len[i];
            fina_x1=lines[i].x1;
            fina_y1=lines[i].y1;
        }
    }
    //寻找最长
    printf("%d %d %d\n",longest,fina_x1,fina_y1);
    return 0;
}