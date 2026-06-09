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
    
    while(scanf("%d%d%d%d",&a[m].x1,&a[m].y1,&a[m].x2,&a[m].y2)!=EOF)@@ Reads until EOF instead of exactly n segments; may cause issues with extra input.
    {
        
        a[m].flag=0;@@ Also need to initialize link to NULL to avoid undefined behavior when traversing.
        m++;
        
    }
    for(int i=0;i<m;i++)@@ Missing sorting of segments by x1 and y1; order is not guaranteed, which may lead to incorrect starting point for the longest chain.
    {
        for(int j=0;j<m;j++)
        {
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
            {
                a[i].link=&a[j];@@ No break; if multiple matches (unlikely), only last link remains; but more importantly, this linking does not respect chain order because array is unsorted.
                a[i].flag=1;//a[i]有指向了 
                if(a[j].flag==0)
                a[j].link=NULL;@@ Unnecessary and may interfere with subsequent linking; should not set link arbitrarily.
                 
            }
        }
        
    }
    int max=0,num=0;
    struct cor *p;
    struct cor list;
    for(int i=0;i<m;i++)
    {   num=0;@@ Should start num=1 to count the first segment; currently counts only subsequent segments.
        for(p=&a[i]; p->link!= NULL; p=p->link)@@ Danger: link may be uninitialized (garbage), causing undefined behavior; also chain order may not be increasing x due to missing sort.
        {
            num++;
            if(num>max)@@ Should be `if(num+1>max)` to include the first segment in the count.
            {
            max=num;@@ Off-by-one: max should be num+1 to represent total segments in chain.
            list=a[i];@@ Starting point a[i] may not be the true start of the chain because segments are not sorted by x1.
        }
        }
    }
    printf("%d %d %d",max,list.x1,list.y1);
    return 0;
    
    
}