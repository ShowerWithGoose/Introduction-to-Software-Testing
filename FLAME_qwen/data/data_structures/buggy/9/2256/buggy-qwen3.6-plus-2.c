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
        struct p *list,*c; // @@ In C89/C90 standards, variable declarations must be at the beginning of a block. Placing it after an executable statement like scanf may cause a compilation error in strict environments.
        list=(struct p*)malloc(n*sizeof(struct p));
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&list[i].x1,&list[i].y1,&list[i].x2,&list[i].y2);

            list[i].next=NULL;
        }
        qsort(list,n,sizeof(struct p),cmp);
        for(i=0;i<n-1;i++)
            {
                if(list[i].x1==list[i+1].x1&&list[i].y1==list[i+1].y1) // @@ Logical error: checks if segments share a starting point instead of checking if one segment's endpoint matches another's starting point (x2 == next.x1). Also, only comparing adjacent elements after sorting misses valid non-adjacent connections.
                {
                    if(list[i].x2>list[i+1].x2||(list[i].x2==list[i+1].x2&&list[i].y2>list[i+1].y2))
                    {
                        list[i].x1=list[i+1].x2;list[i].y1=list[i+1].y2; // @@ Logical error: overwrites the original starting coordinates of the segment. The problem requires outputting the starting point of the continuous line, which must be preserved.
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
                    list[i].count=2; // @@ Logical error: 'count' is not initialized to 1 for all segments initially. Relying on uninitialized memory or incorrect counting logic leads to wrong results.
                    i++;
                }
            }

         for(i=n-1;i>0;i--) // @@ Logical error: loop condition i>0 skips index 0, potentially missing connections for the first segment in the array.
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
    return 1; // @@ Logical error: comparison function should return 0 when elements are equal. Returning only -1 or 1 can cause undefined behavior or incorrect sorting in qsort.
}