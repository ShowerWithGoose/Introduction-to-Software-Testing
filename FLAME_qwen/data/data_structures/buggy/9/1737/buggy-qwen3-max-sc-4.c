#include<stdio.h>
#include<string.h>
struct  cor{
        int x1;
        int y1;
        int x2;
        int y2;
        int flag;
        struct cor *link;
        
    };

int main()
{
    
    struct cor a[300];
    int n,m=0;
    scanf("%d",&n);
    
    while(scanf("%d%d%d%d",&a[m].x1,&a[m].y1,&a[m].x2,&a[m].y2)!=EOF)
    {
        
        a[m].flag=0;
        m++;
        
    } // @@ [The loop reads more than 'n' segments because it uses EOF instead of reading exactly 'n' lines. This causes undefined behavior when input has only 'n' lines and no extra EOF, leading to potential out-of-bound access or incorrect segment count.]
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
            {
                a[i].link=&a[j]; 
                a[i].flag=1;//a[i]有指向了 
                if(a[j].flag==0)
                a[j].link=NULL; // @@ [This incorrectly resets a[j]'s link if it hasn't been flagged yet, potentially breaking longer chains. The logic for managing links is flawed because multiple segments might connect to a[j], but this overwrites its link arbitrarily.]
                 
            }
        }
        
    }
    int max=0,num=0;
    struct cor *p;
    struct cor list;
    for(int i=0;i<m;i++)
    {   num=0;
        for(p=&a[i]; p->link!= NULL; p=p->link)
        {
            num++;
            if(num>max)
            {
            max=num;
            list=a[i];
        }
        } // @@ [The loop counts the number of links (edges), not the number of segments in the chain. For a chain of k segments, there are k-1 links, so 'num' undercounts by 1. Also, if a segment has no link (isolated), it's never counted (num remains 0), but it should count as 1 segment.]
    }
    printf("%d %d %d",max,list.x1,list.y1); // @@ ['list' may be uninitialized if all segments are isolated (max remains 0), leading to undefined behavior when printing its coordinates. Also, due to undercounting, the output segment count is incorrect.]
    return 0;
    
    
}