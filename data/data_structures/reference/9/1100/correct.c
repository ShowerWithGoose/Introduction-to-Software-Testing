#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 struct line
{
int x1;
int y1;
int x2;
int y2;
int pick;
}line[100];

int cmp(const void* a, const void* b)
{
    struct line*c = (struct line*)a; 
    struct line*d = (struct line*)b;
    if(c->x1!=d->x1)
	return d->x1 - c->x1;
    else 
	return d->y1 - c->y1;
}

int main()
{

   int n,i,j,num,max;
   int x0,y0;	
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
   	scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    line[i].pick=1;
   }
    qsort(line,n,sizeof(line[0]),cmp);
   /* for(i=0;i<n;i++)
   {
   	printf("%d %d %d %d\n",line[i].x1,line[i].y1,line[i].x2,line[i].y2);
   }*/
   max=-1;
   for(i=0;i<n-1;i++)
   {
    for(j=i;j<n-1;j++)
    {
    	if(line[j+1].x2==line[i].x1&&line[j+1].y2==line[i].y1)
    	{
    		line[j+1].pick+=line[i].pick;
		}
	}
   }
   for(i=0;i<n;i++)
   {
   	if(line[i].pick>max)
   	{
   		max=line[i].pick;
   		num=i;
	}
   }
   printf("%d %d %d",max,line[num].x1,line[num].y1);
   return 0;
}

