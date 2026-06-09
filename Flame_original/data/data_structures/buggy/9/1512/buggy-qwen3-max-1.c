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
                pas++; // @@ [This approach incorrectly modifies loop variable 'i' inside nested loops, causing unpredictable traversal and skipping of segments. Also, 'len' array is not properly indexed to store segment counts per starting point.]
                i=j; // @@ [Modifying loop control variable 'i' inside the inner loop leads to undefined behavior and breaks the intended iteration logic.]
                j=0;
            }
            else if(j==n-1)
            {
                len[num]=pas; // @@ ['num' does not correspond to the correct starting segment index; it's just a counter, so segment count is stored in wrong position.]
                i=num; // @@ [Incorrectly resetting 'i' to 'num' breaks outer loop logic and causes reprocessing or skipping of segments.]
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
            if(lines[i].x1==lines[j].x1&&lines[i].y1==lines[j].y1&&i!=j) // @@ [This condition checks for identical starting points, but continuous segments should connect end of one to start of another, not same start. Also, forward extension logic is flawed.]
            {
                len[num]++; // @@ ['len[num]' may be out of sync with current segment; also, 'num' is reused incorrectly from previous loop.]
                i=j; // @@ [Again, modifying loop variable 'i' disrupts iteration.]
                j=0;
            }
            else if(j==n-1)
            {
                i=num; // @@ [Same issue: resetting 'i' to 'num' corrupts loop flow.]
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