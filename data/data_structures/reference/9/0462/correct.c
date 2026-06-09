#include<stdio.h>
#include<stdlib.h>

struct node{
    int x1,x2;
    int y1,y2;
    int cnt;
}line[105],ans;

int cmp(const void *a, const void *b)
{
    struct node c = *(struct node *)a;
    struct node d = *(struct node *)b;
    if(c.x1<d.x1)
        return -1;
    else if(c.x1>d.x1)
        return 1;
    return 0;
}

int main()
{
    int n,i,j;
    int flag[105]={0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        line[i].cnt=1;
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    qsort(line,n,sizeof(line[0]),cmp);
    for(i=0;i<n;i++)
    {
        if(flag[i]==0)
        {
            flag[i]=1;
            for(j=i;j<n;j++)
            {
                if(line[j].x1==line[i].x2&&line[j].y1==line[i].y2)
                {
                    line[i].x2=line[j].x2;
                    line[i].y2=line[j].y2;
                    flag[j]=1;
                    line[j].cnt=0;
                    line[i].cnt++;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(line[i].cnt>ans.cnt)
        {
            ans=line[i];
        }
    }
    printf("%d %d %d",ans.cnt,ans.x1,ans.y1);

    return 0;
}

