#include<stdio.h>
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    double k;
};
int b[110]={0};
int i,n;
int num=1;
int max=1;
int x,y;
void f(struct line a[],int b[],int p)
{
    int j;
    for(j=0;j<n;j++)
    {
        if(b[j]==0)
        {
            if(a[p].x2==a[j].x1&&a[p].y2==a[j].y1)
            {
                if(a[p].k!=a[j].k) // @@ The condition checking if slopes are different is incorrect. The problem asks for the number of segments in a continuous line, regardless of whether the slope changes. This condition prevents counting segments that are collinear or have the same slope as part of the chain if they are connected, or more accurately, it incorrectly filters valid connections. Actually, looking closer, if slopes are equal, it skips incrementing num? No, it only increments if slopes are NOT equal. This logic is fundamentally flawed for counting segment length. It should always increment num when a connection is found.
                {
                    num++;
                }
                b[j]=1;
                f(a,b,j);
                b[j]=0;
            }
        }
    }
    if(num>max)
    {
        max=num;
        x=a[i].x1; // @@ The variable 'i' here refers to the global loop variable from main, which might have changed or not represent the current starting segment correctly if 'f' is called recursively or if 'i' is modified. However, the bigger issue is that 'num' is not incremented for the first segment in the chain properly in all cases, and the slope check is wrong. But specifically, this assignment uses 'i' which is the start node index from the outer loop in main. This part is technically okay if 'i' hasn't changed, but 'i' is global. Inside 'f', 'i' is not local. If 'f' modifies 'i' (it doesn't seem to), it would be bad. But the main error is the slope check above.
        y=a[i].y1;
    }
}
int main()
{
    scanf("%d",&n);
    struct line a[110];
    for(i=0;i<n;i++)
    {    
        scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        double x1=a[i].x1;
        double x2=a[i].x2;
        double y1=a[i].y1;
        double y2=a[i].y2;
        a[i].k=(y2-y1)/(x2-x1);
    }
    for(i=0;i<n;i++)
    {
        b[i]=1;
        f(a,b,i);
        b[i]=0;
        num=1;
    }
    printf("%d %d %d",max,x,y);
    return 0; 
}