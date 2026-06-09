#include<stdio.h>
#include<string.h>

struct line{
    int x1;
    int y1;
    int x2;
    int y2;
};

int main()
{
    struct line num[100];
    struct line t;
    int n;
    int x1_max = 0,y1_max = 0,count_max = 1;
    
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d",&num[i].x1,&num[i].y1,&num[i].x2,&num[i].y2);
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(num[i].x1 > num[j].x1)
            {
                t = num[i];
                num[i] = num[j];
                num[j] = t;
            }
        }
    }
    int flag = 0;
    int count = 1;
    for(int i = 0; i < n; i++)
    {
        int x2 = num[i].x2;
        int y2 = num[i].y2;
        count = 1; // @@ [The 'count' variable must be reset to 1 at the start of each outer loop iteration. Without this, the count accumulates across different starting segments, leading to incorrect results.]
        for(int j = i + 1; j < n; j++)
        {
            if(x2 == num[j].x1 && y2 == num[j].y1)
            {
                count++;
                x2 = num[j].x2;
                y2 = num[j].y2;
            }
            
        }
        if(count > count_max)
        {
            count_max = count;
            x1_max = num[i].x1;
            y1_max = num[i].y1;
        }
    }
    printf("%d %d %d\n",count_max,x1_max,y1_max);
    
    return 0;
    
}