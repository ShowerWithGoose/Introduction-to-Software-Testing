#include<stdio.h>
struct line{
    int x1;int y1;int x2;int y2;int len;
};
struct line lines[105];
void bubbleSort(struct line lines[],int n)
{
    int i,j,flag;
    struct line hold;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(lines[j].x1>lines[j+1].x1)
            {
                hold=lines[j];
                lines[j]=lines[j+1];
                lines[j+1]=hold;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
int main()
{
    int i,j,n,max=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
        lines[i].len++;
    }
    bubbleSort(lines,n);
    for(i=0;i<n;i++)
    {
        if(lines[i].len==0) continue;
        for(j=0;j<i;j++)
        {
            if(lines[j].x2==lines[i].x1 && lines[j].y2==lines[i].y1)
            {
                lines[i].len=0;
                lines[j].len++;
                lines[j].x2=lines[i].x2;
                lines[j].y2=lines[i].y2;
            }
        }
    }
    for(i=0;i<n;i++)
        if(lines[i].len>max) max=lines[i].len;
    for(i=0;i<n;i++)
        if(lines[i].len==max)
    {
        printf("%d %d %d",max,lines[i].x1,lines[i].y1);
        break;
    }
}

