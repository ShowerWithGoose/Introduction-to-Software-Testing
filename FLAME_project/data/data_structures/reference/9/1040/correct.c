#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Line
{
    int x1;
    int y1;
    int x2;
    int y2;
}line[100];

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    struct Line Max,Temp;
    int sum,j,max=0;
    for(i=0;i<n;i++)
    {
        Temp=line[i];
        sum=1;
        for(j=0;j<n;j++)
        {
            if(Temp.x2==line[j].x1&&Temp.y2==line[j].y1)
            {
                sum++;
                Temp=line[j];
                j=-1;
            }
        }
        if(sum>max)
        {
            max=sum;
            Max=line[i];
        }
    }
    printf("%d %d %d\n",max,Max.x1,Max.y1);
    return 0;
}
