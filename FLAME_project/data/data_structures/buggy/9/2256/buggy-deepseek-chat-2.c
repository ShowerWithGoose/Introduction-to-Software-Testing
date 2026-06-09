#include<stdio.h>
#include<stdlib.h>
struct p
        {
            int x1,y1,x2,y2,count;
            struct p *next;
        };
int cmp(const void *p1,const void *p2);
int main()
{
        int n,i,j,max,maxgroup;
        scanf("%d",&n);
        struct p *list,*c;
        list=(struct p*)malloc(n*sizeof(struct p));
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&list[i].x1,&list[i].y1,&list[i].x2,&list[i].y2);

            list[i].next=NULL;
        }
        qsort(list,n,sizeof(struct p),cmp);
        for(i=0;i<n-1;i++)
            {
                if(list[i].x1==list[i+1].x1&&list[i].y1==list[i+1].y1)
                {
                    if(list[i].x2>list[i+1].x2||(list[i].x2==list[i+1].x2&&list[i].y2>list[i+1].y2))
                    {
                        list[i].x1=list[i+1].x2;list[i].y1=list[i+1].y2;
                    }
                    else
                    {
                        list[i].x1=list[i].x2;list[i].y1=list[i].y2;
                        list[i].x2=list[i+1].x2;list[i].y2=list[i+1].y2;
                    }
                    list[i+1].x1=-1;
                    list[i+1].x2=-1;
                    list[i+1].y1=-1;
                    list[i+1].y2=-1;
                    list[i+1].count=0;
                    list[i].count=2;
                    i++;
                }
            } // @@ This block incorrectly merges segments that share the same starting point, which is not required by the problem. The problem only asks to connect segments that share an endpoint (endpoint of one equals start of another), not to merge overlapping or collinear segments. This merging corrupts the data and leads to wrong results.

         for(i=n-1;i>0;i--)
            {

            for(j=0;j<n;j++)
                {
                    if(list[i].x2==list[j].x1&&list[i].y2==list[j].y1)
                    {
                        list[i].next=&list[j];
                        break;
                    }
                }
            } // @@ This loop only connects segments where the second endpoint of list[i] matches the first endpoint of list[j], but it does not consider the reverse connection (first endpoint of list[i] matching second endpoint of list[j]). Also, it only iterates i from n-1 down to 1, missing the case where i=0 might be connected. Moreover, it does not handle the case where segments are already merged or marked invalid, leading to incorrect linking.
        for(i=0;i<n;i++)
        {
            c=&list[i];list[i].count=1;
            while(c->next!=NULL)
            {
                list[i].count++;c=c->next;
            }
        }
        max=1;maxgroup=0;
        for(i=0;i<n;i++)
        {
            if(list[i].count>max)
            {
                max=list[i].count;maxgroup=i;
            }
        }
        printf("%d %d %d",max,list[maxgroup].x1,list[maxgroup].y1);
    //  printf("\n\n");
     //   for(i=0;i<n;i++)
      //  {
       //     printf("%d %d %d %d:: %d\n",list[i].x1,list[i].y1,list[i].x2,list[i].y2,list[i].count);
        //}
        free(list);
return 0;
}
int cmp(const void *p1,const void *p2)
{
    if(((struct p*)p1)->x1<((struct p*)p2)->x1){return -1;}
    if(((struct p*)p1)->x1==((struct p*)p2)->x1&&((struct p*)p1)->y1<((struct p*)p2)->y1){return -1;}
    return 1;
}