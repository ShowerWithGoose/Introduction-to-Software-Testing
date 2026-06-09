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
        
    } // @@ [The loop reads more than 'n' segments because it uses EOF instead of reading exactly 'n' lines. This causes undefined behavior when input has only 'n' lines and no extra EOF, leading to potential buffer overflow or incorrect segment count.]
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
            {
                a[i].link=&a[j]; 
                a[i].flag=1;//a[i]有指向了 
                if(a[j].flag==0)
                a[j].link=NULL; // @@ [This incorrectly resets a[j].link to NULL even if a[j] was already linked from another segment, breaking potential chains and causing loss of connectivity.]
                 
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
        } // @@ [The counting logic is off by one: it counts the number of links (edges) but not the starting segment. So a chain of k segments yields num = k-1, leading to undercounting. Also, 'list' may be uninitialized if max remains 0.]
    }
    printf("%d %d %d",max,list.x1,list.y1); // @@ [If no continuous segment exists (max=0), 'list' is uninitialized, causing undefined behavior. Also, due to undercounting, output will be one less than expected.]
    return 0;
    
    
}