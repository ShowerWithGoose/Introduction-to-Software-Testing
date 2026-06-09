#include<stdio.h>
#include<stdlib.h>
struct infor{int x1;
             int y1;
             int x2;
             int y2;
             struct infor *next;
             };
int main()
{
    struct infor *a[100]={NULL},*b[100],*temp,*p;
    int n,i,j,max1,max;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        b[i]=(struct infor*)malloc(sizeof(struct infor));
        scanf("%d %d %d %d",&(b[i]->x1),&(b[i]->y1),&(b[i]->x2),&(b[i]->y2));
        b[i]->next=NULL;
    }
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if((b[j]->x1)<(b[j-1]->x1))
            {
                temp=b[j];
                b[j]=b[j-1];
                b[j-1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<100;j++)
        {
            if(a[j]==NULL)
            {
                a[j]=b[i];
                break;
            }
            if(a[j]!=NULL)
            {
                p=a[j];
                while(p!=NULL)
                {
                    if(((p->x2)==(b[i]->x1))&&((p->y2)==(b[i]->y1)))
                    {
                        p->next=b[i];
                        break;
                    }
                    else
                        p=p->next;
                }
                if(p!=NULL)
                    break;
            }
        }
    }
    for(i=0,max1=0,max=1;a[i]!=NULL;i++)
    {
        p=a[i];
        for(j=1;(p->next)!=NULL;j++)
        {
            p=p->next;
        }
        if(j>max)
        {
            max1=i;
            max=j;
        }
    }
    printf("%d %d %d",max,(a[max1]->x1),(a[max1]->y1));
    for(i=0;i<n;i++)
    {
        free(b[i]);
    }
    return 0;
}

