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
    for(int i=0;i<n;i++) // @@ The logic for traversing and merging segments is flawed. Modifying the loop variable 'i' inside the loop (i=j) combined with the outer loop increment leads to skipping segments or infinite loops, and fails to correctly chain multiple segments. It also doesn't handle visited states, leading to incorrect counts.
    {
        for(int j=0;j<n;j++)
        {
            if(lines[i].x2==lines[j].x1&&lines[i].y2==lines[j].y1)
            {
                pas++;
                i=j;
                j=0;
            }
            else if(j==n-1)
            {
                len[num]=pas;
                i=num; // @@ Resetting i to num here is incorrect logic for iterating through all starting points. It disrupts the outer loop's intended progression.
                num++;
                pas=1;
            }
        }
    }
//向后延伸，将段数存在len里
num=0;
for(int i=0;i<n;i++) // @@ Similar flawed logic as above. Trying to extend backwards by modifying loop variables is error-prone and incorrect for this problem structure. It assumes a specific order and doesn't properly aggregate lengths from both directions.
    {
        for(int j=0;j<n;j++)
        {
            if(lines[i].x1==lines[j].x1&&lines[i].y1==lines[j].y1&&i!=j)
            {
                len[num]++;
                i=j;
                j=0;
            }
            else if(j==n-1)
            {
                i=num; // @@ Incorrect reset of loop variable.
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