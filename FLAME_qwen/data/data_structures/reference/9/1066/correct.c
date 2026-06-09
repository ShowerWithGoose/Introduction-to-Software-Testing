#include<stdio.h>

struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    int time;
}evel[102];
void cacutime(int);
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d%d",&evel[i].x1,&evel[i].y1,&evel[i].x2,&evel[i].y2);
    int num=0,pos=0;
    for(int i=1;i<=n;i++)
    {
        cacutime(i);
        if(num<evel[i].time)
        {
            num=evel[i].time;
            pos=i;
        }
    }
    printf("%d %d %d\n",evel[pos].time,evel[pos].x1,evel[pos].y1);
    system("pause");
    return 0;
}

void cacutime(int m)
{
    int flag=0,re=1;
    int x=evel[m].x2,y=evel[m].y2;
    do{
        flag=0;
        for(int i=1;i<=n;i++)
            if(evel[i].x1==x&&evel[i].y1==y)
            {
                flag=1;
                re++;
                x=evel[i].x2;
                y=evel[i].y2;
            }
    }while (1==flag);
    evel[m].time=re;
    return;
}


