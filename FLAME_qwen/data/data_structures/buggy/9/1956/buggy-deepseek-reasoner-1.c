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
    int i,j,k,max=0,n,xx1,yy1,xx2,yy2,pd=0;
    
    scanf("%d",&n);
    
    while(n--)
    {
        scanf("%d%d%d%d",&xx1,&yy1,&xx2,&yy2);
        pd=0;
        for(j=0;j<=i;j++)            // @@ error: i is uninitialized; using it in loop condition leads to undefined behavior
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
            i++;                     // @@ error: i incremented before assigning the new segment, causing the first segment to be placed at index 1 instead of 0 (and i starts as garbage)
            li[i].x1=xx1;li[i].y1=yy1;li[i].x2=xx2;li[i].y2=yy2;li[i].l=1;
        }
        
        else
        {
            for(j=0;j<=i;j++)
            {
                if(j==k)
                    j++;            // @@ error: incrementing j inside the loop when j==k can skip elements and potentially go out of bounds, and it does not correctly handle the case where k is the last index
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

    for(j=0;j<=i;j++)
    {
        if(li[j].l>max)
        {
            max=li[j].l;
            k=j;
        }
    }

    printf("%d ",li[k].l);
    if(li[k].x1>=li[k].x2)          // @@ error: after merging, the endpoints may not be correctly ordered; this condition does not reliably identify the starting point (the one with smallest x)
    printf("%d %d",li[k].x2,li[k].y2);
    else if(li[k].x1<li[k].x2)
    printf("%d %d",li[k].x1,li[k].y1);
}