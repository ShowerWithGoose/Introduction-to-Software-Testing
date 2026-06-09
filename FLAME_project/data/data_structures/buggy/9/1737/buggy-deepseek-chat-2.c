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
        
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
            {
                a[i].link=&a[j]; 
                a[i].flag=1;//a[i]有指向了 
                if(a[j].flag==0)
                a[j].link=NULL;
                 
            }
        }
        
    }
    int max=0,num=0;
    struct cor *p;
    struct cor list;
    for(int i=0;i<m;i++)
    {   num=0;
        for(p=&a[i]; p->link!= NULL; p=p->link) // @@ [Error: The loop condition p->link != NULL stops before counting the last segment in the chain. For a chain of k segments, this loop only counts k-1 segments because it exits when p->link is NULL, missing the final segment. Additionally, the inner loop does not increment num for the starting segment a[i] itself, so the count is off by one.]
        {
            num++;
            if(num>max)
            {
            max=num;
            list=a[i];
        }
        }
    }
    printf("%d %d %d",max,list.x1,list.y1);
    return 0;
    
    
}