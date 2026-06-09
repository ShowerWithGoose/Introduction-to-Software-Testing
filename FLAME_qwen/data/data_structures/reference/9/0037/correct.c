#include<stdio.h>
#include<string.h>

struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    int sum;
};

int paixu1(const void* a, const void* b)
{
    struct line* aa=(struct line*)a;
    struct line* bb=(struct line*)b;
    return (aa->x1 > bb->x1 ? 1:-1);
}
int paixu2(const void* a, const void* b)
{
    struct line* aa=(struct line*)a;
    struct line* bb=(struct line*)b;
    return (aa->sum > bb->sum ? -1:1);
}
int main()
{
    int n;
    scanf("%d",&n);
    struct line lines[101];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&lines[i].x1);
        scanf("%d",&lines[i].y1);
        scanf("%d",&lines[i].x2);
        scanf("%d",&lines[i].y2);
        lines[i].sum=1;
    }
    qsort(lines,n,sizeof(lines[0]),paixu1);
    for(int i=0;i<n;i++)
    {
        for(int k=0;k<n-1;k++)
        {
            for(int j=0;j<n;j++)
            {
                if((lines[i].x2==lines[j].x1)&&(lines[i].y2==lines[j].y1))
            {
                lines[i].x2=lines[j].x2;
                lines[i].y2=lines[j].y2;
                lines[i].sum=lines[i].sum+lines[j].sum;
                break;
            }
            else continue;
            }
        }
    }
    qsort(lines,n,sizeof(lines[0]),paixu2);
    printf("%d ",lines[0].sum);
    printf("%d ",lines[0].x1);
    printf("%d",lines[0].y1);
}



