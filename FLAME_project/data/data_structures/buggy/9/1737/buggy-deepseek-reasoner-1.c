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
    {   num=0; // @@ The count should start at 1 to include the starting segment itself. Starting at 0 leads to off-by-one: for a chain of k segments, num becomes k-1, and single-segment chains are missed.
        for(p=&a[i]; p->link!= NULL; p=p->link)
        {
            num++; // @@ This increments for each link (transition) between segments. Combined with the zero initial value, it counts the number of links, which is one less than the number of segments.
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