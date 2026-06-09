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
    for(int i=0;i<m;i++) // @@ In C89/C90 standard, declaring loop variables inside the for-loop initialization is not allowed, causing a compilation error. Declare 'i' before the loop or compile with C99 standard.
    {
        for(int j=0;j<m;j++) // @@ Same as above: variable declaration in for-loop initialization is not supported in older C standards, leading to compilation failure.
        {
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
            {
                a[i].link=&a[j]; 
                a[i].flag=1;//a[i]有指向了 
                if(a[j].flag==0)
                a[j].link=NULL; // @@ The 'link' pointer is not initialized to NULL for all array elements during input. Uninitialized pointers may contain garbage values, causing undefined behavior or strict compiler errors.
                 
            }
        }
        
    }
    int max=0,num=0; // @@ 'max' should be initialized to 1 to handle cases with single segments, and 'num' should start at 1 to correctly count the segments in a chain.
    struct cor *p;
    struct cor list;
    for(int i=0;i<m;i++) // @@ Same C89 compatibility issue with loop variable declaration causing compilation error.
    {   num=0; // @@ 'num' should be initialized to 1 to count the starting segment of the chain, otherwise the length will be undercounted by 1.
        for(p=&a[i]; p->link!= NULL; p=p->link) // @@ 'p->link' may be uninitialized garbage if not set to NULL initially, leading to runtime errors. Also, the loop condition skips counting the last segment properly.
        {
            num++;
            if(num>max)
            {
            max=num;
            list=a[i]; // @@ 'list' may remain uninitialized if 'max' never updates, causing undefined behavior when printing its coordinates.
        }
        }
    }
    printf("%d %d %d",max,list.x1,list.y1);
    return 0;
    
    
}