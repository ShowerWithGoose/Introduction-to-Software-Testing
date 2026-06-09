#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct dot{
	 int x1,y1;
	 int x2,y2;
	 int x,y;
	 int index;
}situ[110],bg[110];
int cmp(const void*p1,const void*p2)
{
	 struct dot *a=(struct dot*)p1;
	 struct dot *b=(struct dot*)p2;
	 int m=(a->x1)-(b->x1);
	 return m;
}
int max[110];
int main()
{
	 int n,l,j;
	 scanf("%d",&n);
	 for(int i=0;i<n;i++)
	 {
	  	scanf("%d%d%d%d",&situ[i].x1,&situ[i].y1,&situ[i].x2,&situ[i].y2);
	  	situ[i].index=i;
	 }
	 qsort(situ,n,sizeof(situ[0]),cmp);
	 int anl=0,ans=0;
	 int start;
	 for(l=0;l<n-1;l++)
	 {
	 	bg[l].x=situ[l].x1;
	 	bg[l].y=situ[l].y1;
	 	for(start=l;start<n-1;)
	  	{
	  		int t=1;
		  	for(j=start+1;j<n;j++)
		  	{
			   if(situ[start].x2==situ[j].x1&&situ[start].y2==situ[j].y1)
			   {
			    max[l]++;
			    start=j;
			    t=0;
			    break;
			   }
			}
			if(t)
			break;
		}
		if(max[l]>ans)
		{
			ans=max[l];
			anl=l;
		}
	 }
	 printf("%d %d %d",ans+1,bg[anl].x,bg[anl].y);
	 
	 return 0;
 } 

