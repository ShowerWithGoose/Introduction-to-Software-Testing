#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct lines{
	int x1;
	int y1;
	int x2;
	int y2;
}line[200];
struct w{
	int length;
	int flag; 
}op[200];
int cmp(const void*a,const void*b)
{ 
   struct lines *c=(struct lines *)a;
   struct lines *d=(struct lines *)b;
   if(c->x1>d->x1)return 1;
   else if(c->x1==d->x1)return 0;
   else return -1;
}
int acmp(const void*p1,const void*p2)
{
  struct w *c=(struct w *)p1;
  struct w *d=(struct w *)p2;	
if ( c->length < d->length ) return 1;
if ( c->length > d->length ) return -1;
return 0;

}
int main()
{   int flah=0,p=0,k=0,n,i,j,flag[200]={0},num=0,length[200]={0},f[200]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	qsort(line,n,sizeof(line[0]),cmp);
	int o=n;
	while(o)
	{
	  for(i=n-o;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{  
			if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1&&f[j]==0)
			{   if(num==0)
			    {op[k].flag=i;
			    k++;
				}
				num++;
				f[i]=1;f[j]=1;
				i=j;
		       flah=1;
			}
		}
		if(flah==1)
		{ flah=0;
		break;}
	}
	o--;
	if(num!=0)
	{op[k-1].length=num;}
	num=0;
    }
    qsort(op,k,sizeof(op[0]),acmp);
    printf("%d %d %d",op[0].length+1,line[op[0].flag].x1,line[op[0].flag].y1);
}




