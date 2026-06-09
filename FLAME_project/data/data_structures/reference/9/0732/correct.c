#include<stdio.h>
#include <stdlib.h>
struct Line{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
    int length;
}line[1000];
int cnt[1000];
int n;
int FindNext(int p)
{
    for(int i=p;i<=n;i++)
    {
        if(line[i].x1==line[p].x2&&line[i].y1==line[p].y2)
        {
            return i;
        }
    }
    return -1;
}
int cmp(const void * p1,const void * p2)
{
    struct Line * a=(struct Line * )p1;
    struct Line * b=(struct Line * )p2;
    return (a->x1)-(b->x1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
        line[i].num=i;
    }
    qsort(&line[1],n,sizeof (struct Line),cmp);
//    for(int i=1;i<=n;i++)
//    {
//        printf("%d %d %d %d\n",line[i].x1,line[i].y1,line[i].x2,line[i].y2);
//    }
    for(int k=1;k<=n;k++)
    {
        for(int i=k;i<=n;)
        {
            if(FindNext(i)>0)
            {
                cnt[k]++;
                i=FindNext(i);
            }
            else
                break;
        }
    }
    int max=0;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]>max){
            max=cnt[i];
            flag=i;
        }

    }
    printf("%d %d %d",max+1,line[flag].x1,line[flag].y1);
    return 0;
}

