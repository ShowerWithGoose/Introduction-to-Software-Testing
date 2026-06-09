#include <stdio.h>

void find(int i);

struct lines
{
    int x1;int y1;
    int x2;int y2;
    int linked;   //struct的成员不能这样赋初始值吗？(int linked=0;)
    int count;
}s[101];

int n,max=0,lonest;
int main()
{

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
        s[i].linked=0;s[i].count=1;
    }

    for(int i=0;i<n;i++)
    {
        if(s[i].linked==0)
        {
            s[i].linked=1;//循环前一般都要做什么事情
            find(i);
        }

    }
    for(int i=0;i<n;i++)
    {
        if(s[i].count>max)
        {
            max=s[i].count;
            lonest=i;
        }
    }
    printf("%d %d %d\n",max,s[lonest].x1,s[lonest].y1);
    return 0;
}

void find(int i)
{
    for(int j=0;j<n;j++)
        {
            if(s[j].x1==s[i].x2 && s[j].y1==s[i].y2 && s[j].linked==0)//连尾;居然忘了加s[j].linked==0
            {
                s[i].count++;s[j].linked=1;
                s[i].x2=s[j].x2;s[i].y2=s[j].y2;
                find(i);
            }
            else if(s[j].x2==s[i].x1 && s[j].y2==s[i].y1 && s[j].linked==0)//连头
            {
                s[i].count++;s[j].linked=1;
                s[i].x1=s[j].x1;s[i].y1=s[j].y1;
                find(i);
            }
        }
}

