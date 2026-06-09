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
        for(j=0;j<=i;j++)
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
            i++;
            li[i].x1=xx1;li[i].y1=yy1;li[i].x2=xx2;li[i].y2=yy2;li[i].l=1;
        }
        
        else
        {
            for(j=0;j<=i;j++)
            {
                if(j==k)
                    j++;

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
    if(li[k].x1>=li[k].x2)
    printf("%d %d",li[k].x2,li[k].y2);
    else if(li[k].x1<li[k].x2)
    printf("%d %d",li[k].x1,li[k].y1); // @@ The starting point should be the one with the smallest x-coordinate in the continuous line, but this logic only checks the stored endpoints of the merged segment, which may not be the true starting point after merging. The program fails to correctly track the original starting point of the chain.
}