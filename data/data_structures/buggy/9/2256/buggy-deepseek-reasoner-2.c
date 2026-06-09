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
                if(list[i].x1==list[i+1].x1&&list[i].y1==list[i+1].y1) // @@ Error: Condition checks same start point, but chain is formed by end of one segment equaling start of next, not by same start.
                {
                    if(list[i].x2>list[i+1].x2||(list[i].x2==list[i+1].x2&&list[i].y2>list[i+1].y2)) // @@ Error: Arbitrary ordering condition not related to chain formation.
                    {
                        list[i].x1=list[i+1].x2;list[i].y1=list[i+1].y2; // @@ Error: Modifies starting point of the first segment, losing the original start coordinate.
                    }
                    else
                    {
                        list[i].x1=list[i].x2;list[i].y1=list[i].y2; // @@ Error: Changes the start point to the old end point, which is incorrect.
                        list[i].x2=list[i+1].x2;list[i].y2=list[i+1].y2; // @@ Error: Alters the end point of the first segment arbitrarily.
                    }
                    list[i+1].x1=-1; // @@ Error: Invalidating coordinates may break later linking and counting.
                    list[i+1].x2=-1; // @@ Error: Invalidating coordinates.
                    list[i+1].y1=-1; // @@ Error: Invalidating coordinates.
                    list[i+1].y2=-1; // @@ Error: Invalidating coordinates.
                    list[i+1].count=0; // @@ Error: Setting count to 0, but this value is later overwritten.
                    list[i].count=2; // @@ Error: Setting count to 2, but this value is also overwritten later.
                    i++; // @@ Error: Skipping the next segment, which may break chain connection if they should be linked differently.
                }
            }

         for(i=n-1;i>0;i--)
            {

            for(j=0;j<n;j++)
                {
                    if(list[i].x2==list[j].x1&&list[i].y2==list[j].y1) // @@ Error: No check that list[j] is a valid segment (e.g., not invalidated with -1 values). This can cause incorrect linking.
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
    return 1; // @@ Error: If both x1 and y1 are equal, the function returns 1 (greater), but it should return 0 to indicate equality. This violates the comparator contract.
}