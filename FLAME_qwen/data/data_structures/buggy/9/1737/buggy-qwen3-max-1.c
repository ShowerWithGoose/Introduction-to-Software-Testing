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
        
    } // @@ [The loop reads more than 'n' segments; it should read exactly 'n' segments, not until EOF. This causes undefined behavior if extra input exists or if input ends early.]
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
            {
                a[i].link=&a[j]; 
                a[i].flag=1;//a[i]有指向了 
                if(a[j].flag==0)
                a[j].link=NULL; // @@ [This incorrectly resets a[j].link to NULL even if a[j] was already linked from another segment, breaking potential chains.]
                 
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
        } // @@ [The count 'num' only counts the number of links traversed, which equals the number of connected segments minus one. So a chain of k segments yields num = k-1, leading to undercount.]
    }
    printf("%d %d %d",max,list.x1,list.y1); // @@ ['list' may be uninitialized if no chain is found (max remains 0), causing undefined behavior when printing its fields. Also, 'max' is off by one due to counting error above.]
    return 0;
    
    
}