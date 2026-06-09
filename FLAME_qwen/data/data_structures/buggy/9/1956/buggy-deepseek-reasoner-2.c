#include<stdio.h>

struct lines{
    int x1;
    int y1;
    int x2;
    int y2;
    int l;
};
struct lines li[105];

int main()
{
    int i,j,k,max=0,n,xx1,yy1,xx2,yy2,pd=0; // @@ i is not initialized, leads to undefined behavior when used as loop bound.
    
    scanf("%d",&n);
    
    while(n--)
    {
        scanf("%d%d%d%d",&xx1,&yy1,&xx2,&yy2);
        pd=0;
        for(j=0;j<=i;j++) // @@ i is uninitialized; loop may not execute correctly or may cause out-of-bounds access.
        {
                if(li[j].x1==xx1&&li[j].y1==yy1)
                {
                    li[j].x1=xx2;li[j].y1=yy2;li[j].l++;pd=1;k=j;break;
                }
                
                else if(li[j].x1==xx2&&li[j].y1==yy2)
                {
                    li[j].x1=xx1;li[j].y1=yy1;li[j].l++;pd=1;k=j;break;
                }
                
                else if(li[j].x2==xx1&&li[j].y2==yy1)
                {
                    li[j].x2=xx2;li[j].y2=yy2;li[j].l++;pd=1;k=j;break;
                }
                
                else if(li[j].x2==xx2&&li[j].y2==yy2)
                {
                    li[j].x2=xx1;li[j].y2=yy1;li[j].l++;pd=1;k=j;break;
                }        
        }
        
        if(pd==0)
        {
            i++; // @@ i is still uninitialized; incrementing a garbage value leads to undefined array indexing.
            li[i].x1=xx1;li[i].y1=yy1;li[i].x2=xx2;li[i].y2=yy2;li[i].l=1;
        }
        
        else
        {
            for(j=0;j<=i;j++) // @@ i may be incorrect; also the loop logic below is flawed.
            {
                if(j==k)
                    j++; // @@ Manual modification of loop counter inside the loop causes an extra increment, skipping indices.
                else
                {
                    if(li[j].x1==li[k].x1&&li[j].y1==li[k].y1)
                    {
                        li[j].x1=li[k].x2;li[j].y1=li[k].y2;li[j].l+=li[k].l;li[k].l=0;li[k].x1=0;li[k].x2=0;li[k].y1=0;li[k].y2=0;break;
                    }
                    
                    else if(li[j].x1==li[k].x2&&li[j].y1==li[k].y2)
                    {
                        li[j].x1=li[k].x1;li[j].y1=li[k].y1;li[j].l+=li[k].l;li[k].l=0;li[k].x1=0;li[k].x2=0;li[k].y1=0;li[k].y2=0;break;
                    }
                    
                    else if(li[j].x2==li[k].x1&&li[j].y2==li[k].y1)
                    {
                        li[j].x2=li[k].x2;li[j].y2=li[k].y2;li[j].l+=li[k].l;li[k].l=0;li[k].x1=0;li[k].x2=0;li[k].y1=0;li[k].y2=0;break;
                    }
                    
                    else if(li[j].x2==li[k].x2&&li[j].y2==li[k].y2)
                    {
                        li[j].x2=li[k].x1;li[j].y2=li[k].y1;li[j].l+=li[k].l;li[k].l=0;li[k].x1=0;li[k].x2=0;li[k].y1=0;li[k].y2=0;break;
                    }
                }
                    
            }
        }
    }

    for(j=0;j<=i;j++) // @@ i may still be incorrect; also includes zeroed-out entries.
    {
        if(li[j].l>max)
        {
            max=li[j].l;
            k=j;
        }
    }

    printf("%d ",li[k].l);
    if(li[k].x1>=li[k].x2)
    printf("%d %d",li[k].x2,li[k].y2);
    else if(li[k].x1<li[k].x2)
    printf("%d %d",li[k].x1,li[k].y1);
}