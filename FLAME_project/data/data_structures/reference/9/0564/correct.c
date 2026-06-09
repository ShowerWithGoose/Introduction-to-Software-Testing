#include<stdio.h>
#include<stdlib.h>
struct line {
   int x1;
   int y1;
   int x2;
   int y2;
   struct line *next;
}a[105];
int high(struct line *p1,struct line *p2)
{
    if(p1->x1<p2->x1) return -1;
    else return 1;
}
int main()
{
    int n,i,j,k,ans,max=0,ai;
    struct line *head,*p,*q;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    qsort(a,i,sizeof(struct line),high);

    for(j=0;j<n-1;j++)
    {
        ans=1;
        k=j+1;
        head=p=&a[j];
        q=&a[k];
        while(k<n)
        {
            if(p->x2==q->x1&&p->y2==q->y1)
            {
                p->next=q;
                p=p->next;
                if(k<n-1) q=&a[k+1];
                ans++;
            }
            else
            {
                k++;
                q=&a[k];
            }
        }
        if(ans>max)
        {
            max=ans;
            ai=j;
        }
    }
    printf("%d %d %d\n",max,a[ai].x1,a[ai].y1);
    return 0;
}

