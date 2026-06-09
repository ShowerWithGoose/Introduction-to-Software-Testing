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
                pas++; // @@ [This logic incorrectly modifies loop control variable 'i' inside nested loops, causing unpredictable iteration and skipping of segments. Also, 'len' array is not properly indexed to store counts per starting segment.]
                i=j; // @@ [Modifying loop variable 'i' inside inner loop breaks the outer loop's iteration logic, leading to incorrect traversal and missed connections.]
                j=0; // @@ [Resetting 'j' to 0 after modifying 'i' causes redundant and incorrect reprocessing, and does not correctly simulate path extension from a fixed start point.]
            }
            else if(j==n-1)
            {
                len[num]=pas; // @@ ['num' is used as an index but is not aligned with the actual segment being processed; this stores count in wrong position and overwrites previous results unpredictably.]
                i=num; // @@ [Overwriting 'i' with 'num' corrupts the outer loop index, causing segments to be skipped or reprocessed incorrectly.]
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
            if(lines[i].x1==lines[j].x1&&lines[i].y1==lines[j].y1&&i!=j) // @@ [This condition checks for identical starting points, but the problem requires chaining via shared endpoints (end of one = start of another). This logic is fundamentally flawed for forward extension. Also, it should check if some segment ends at lines[i].x1, lines[i].y1, not starts there.]
            {
                len[num]++; // @@ [Again, 'num' is misused as index; this does not correspond to the correct segment chain.]
                i=j; // @@ [Modifying loop variable 'i' breaks iteration logic.]
                j=0; // @@ [Resetting 'j' leads to infinite loops or incorrect reprocessing.]
            }
            else if(j==n-1)
            {
                i=num; // @@ [Corrupts loop index 'i', leading to undefined behavior in loop progression.]
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