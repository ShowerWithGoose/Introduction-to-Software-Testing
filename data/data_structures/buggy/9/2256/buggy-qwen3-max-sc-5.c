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
                        list[i].x1=list[i+1].x2;list[i].y1=list[i+1].y2; // @@ [This incorrectly modifies the starting point (x1, y1) instead of extending the segment by updating (x2, y2). It breaks the segment structure and continuity logic.]
                    }
                    else
                    {
                        list[i].x1=list[i].x2;list[i].y1=list[i].y2; // @@ [This overwrites the start point with its own end point, destroying original start coordinates needed for final output. Also, it doesn't correctly merge segments.]
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
            }

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
            }
        for(i=0;i<n;i++)
        {
            c=&list[i];list[i].count=1; // @@ [The count field was never initialized for most elements before this loop. In particular, elements not involved in the earlier merging loop retain garbage values, but more critically, the prior merging logic corrupts segment data, making chain traversal unreliable.]
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
        printf("%d %d %d",max,list[maxgroup].x1,list[maxgroup].y1); // @@ [Due to earlier corruption of x1/y1 during faulty merging (e.g., lines 28 and 32), the starting point printed may not be the true original start of the continuous segment.]
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