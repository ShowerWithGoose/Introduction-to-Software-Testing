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
                pas++; // @@ [This logic incorrectly modifies loop variable 'i' inside nested loop, causing unpredictable iteration and skipping of segments]
                i=j;   // @@ [Modifying outer loop index 'i' inside inner loop leads to undefined traversal behavior and missed connections]
                j=0;   // @@ [Resetting 'j' to 0 after modifying 'i' causes inconsistent state and potential infinite loops or incorrect counting]
            }
            else if(j==n-1)
            {
                len[num]=pas; // @@ [Incorrectly assigns segment count to 'len[num]' without verifying if current chain is complete or valid]
                i=num;        // @@ [Overwrites outer loop index 'i' with 'num', breaking the intended iteration over original segments]
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
            if(lines[i].x1==lines[j].x1&&lines[i].y1==lines[j].y1&&i!=j) // @@ [This condition checks for identical starting points, but problem requires chaining via shared endpoints (end of one = start of another), not duplicate starts]
            {
                len[num]++; // @@ [Incrementing len[num] without proper initialization or context leads to garbage values being used]
                i=j;        // @@ [Again, modifying loop variable 'i' inside inner loop breaks iteration logic]
                j=0;        // @@ [Resetting 'j' arbitrarily disrupts the double loop structure]
            }
            else if(j==n-1)
            {
                i=num;      // @@ [Overwriting 'i' with 'num' corrupts the outer loop progression]
                num++;
            }
        }
    }
//向前延伸，将段数加上来
    longest=len[0]; // @@ [Assumes len[0] is valid, but 'len' array may contain uninitialized or incorrect values due to flawed prior logic]
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