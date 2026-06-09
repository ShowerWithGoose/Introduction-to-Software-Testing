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
    
    while(scanf("%d%d%d%d",&a[m].x1,&a[m].y1,&a[m].x2,&a[m].y2)!=EOF) // @@ The loop condition reads until EOF, but the problem specifies exactly 'n' segments. This causes the program to wait for more input or read garbage if stdin is not closed properly, and potentially processes more than n items if extra data exists. It should use a counter based on n.
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
        for(p=&a[i]; p->link!= NULL; p=p->link)
        {
            num++;
            if(num>max)
            {
            max=num;
            list=a[i];
        }
        }
    }
    printf("%d %d %d",max,list.x1,list.y1); // @@ The variable 'max' stores the number of links (edges) traversed, which is one less than the number of segments in the continuous line. Also, 'list' is uninitialized if no links are found (max remains 0), leading to undefined behavior or incorrect output for single segments. The count should be num + 1 for the segments involved in the chain starting at a[i].
    return 0;
    
    
}