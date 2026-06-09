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
                pas++;
                i=j; // @@ Modifying loop variable i breaks the outer loop control, causing unpredictable behavior and likely infinite loop or incorrect counting.
                j=0; // @@ Resetting j to 0 combined with i=j may cause the inner loop to repeat indefinitely or skip segments.
            }
            else if(j==n-1)
            {
                len[num]=pas;
                i=num; // @@ Assigning i (loop counter) to a separate index variable leads to out-of-bounds access and incorrect loop iteration.
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
            if(lines[i].x1==lines[j].x1&&lines[i].y1==lines[j].y1&&i!=j) // @@ Wrong condition: should check lines[i].x1 == lines[j].x2 && lines[i].y1 == lines[j].y2 for reverse connection. Current condition does not represent a shared endpoint.
            {
                len[num]++;
                i=j; // @@ Same error as before: modifying loop variable i.
                j=0; // @@ Same error: resetting inner loop variable.
            }
            else if(j==n-1)
            {
                i=num; // @@ Same error: assigning loop variable i to num.
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