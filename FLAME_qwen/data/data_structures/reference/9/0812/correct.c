#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include <ctype.h>

#define MAXLEN 101
struct point
{
  int x1;
  int y1;
  int x2;
  int y2;
};
struct point line[MAXLEN];
int flag[101]={0};

int cmp(const void *_p,const void *_q)
{
    struct point p=*(struct point *)_p;
    struct point q=*(struct point *)_q;
    if(p.x1>q.x1||(p.x1==q.x1&&p.y1>q.y1))
        return 1;
    return -1;
}

int main()
{
    int n,i,j,k,cnt=0,max=0,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }

    qsort(line,n,sizeof(struct point),cmp);

    for(i=0;i<n;i++)
    {
        if(flag[i]==1)
            continue;
        k=i;
        cnt=0;
        for(j=i+1;j<n;j++)
        {
            if(flag[j]==1)
                continue;
            if(line[j].x1==line[k].x2&&line[j].y1==line[k].y2)
            {
                cnt++;
                k=j;
                flag[j]=1;
            }
        }
        if(cnt>max)
        {
            max=cnt;
            num=i;
        }
    }
    printf("%d %d %d\n",max+1,line[num].x1,line[num].y1);

    return 0;
}



