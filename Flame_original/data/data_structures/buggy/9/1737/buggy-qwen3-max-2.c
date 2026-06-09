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
        
    } // @@ [The loop reads more than 'n' segments because it uses EOF instead of reading exactly 'n' lines. This causes extra or fewer inputs to be processed, leading to incorrect behavior.]
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
            {
                a[i].link=&a[j]; 
                a[i].flag=1;//a[i]有指向了 
                if(a[j].flag==0)
                a[j].link=NULL; // @@ [This line incorrectly resets a[j].link to NULL even if a[j] might already be part of another chain or could be linked later. It breaks potential longer chains.]
                 
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
        } // @@ [The count 'num' represents the number of links traversed, which equals the number of segments minus one. Thus, the actual segment count is num+1, but the code outputs 'num' as the segment count.]
    }
    printf("%d %d %d",max,list.x1,list.y1); // @@ [Because 'max' stores the number of links (not segments), the output segment count is off by one. Also, 'list' may be uninitialized if no chain exists (e.g., all isolated segments), leading to undefined behavior.]
    return 0;
    
    
}