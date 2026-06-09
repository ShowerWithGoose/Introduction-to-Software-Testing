#include<stdio.h>
#include<string.h>
struct node{
    int x,y;
    int next;
    int tag;
}p[1000];
int n,i,j,now,f,count,t,x,y;
int main()
{
    scanf("%d",&n);
    now=0;
    while(n--)
    {
        f=0;
        scanf("%d%d",&x,&y);
        for(i=0;i<now;i++)
        {
            if(p[i].x==x&&p[i].y==y)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            p[i].x=x;
            p[i].y=y;
            now++;
        }
        scanf("%d%d",&x,&y);
        f=0;
        for(j=0;j<=now;j++)
        {
            if(p[j].x==x&&p[j].y==y)
            {
                f=1;
                p[i].next=j;
                break;
            }
        }
        if(f==0)
        {
            p[now].x=x;
            p[now].y=y;
            p[i].next=now;
            p[now].next=-1;
            now++;
        }
    }
    count=0;
  
    printf("\n");
    for(i=0;i<now;i++)
    {

        j=i;
        t=0;
        while(p[j].next!=-1)
        {
            t++;
            p[j].tag=1;
            j=p[j].next;
            
        }
        

        if(t>count)
        {
            count=t;
            x=p[i].x;
            y=p[i].y;
        }

    }
    printf("%d %d %d",count,x,y);
    return 0;
}
