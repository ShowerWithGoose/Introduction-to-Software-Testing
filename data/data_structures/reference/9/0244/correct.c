#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct point{   
	int x1;
	int y1;
	int x2;
	int y2;
	int num;        
};
typedef struct point Poi;
Poi p[2000];
int cmp(const void*p1,const void*p2);
int cmp2(const void*p1,const void*p2);
int cmp(const void*p1,const void*p2)
{
	struct point *a=(struct point*)p1;
	struct point *b=(struct point*)p2;
	return a->num-b->num;
}
int cmp2(const void*p1,const void*p2)
{
	struct point *a=(struct point*)p1;
	struct point *b=(struct point*)p2;
	if(a->x1 != b->x1) return a->x1-b->x1;
	else return a->y1-b->y2;
}

int main()
{	
	int n,a,b,c,d;
	int i,j,k=0,flag=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) p[i].num=1;   
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
	}
	qsort(p,n,sizeof(Poi),cmp2); 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)
			{
				continue; 
			}
			else
			{
				if(p[j].x1 == p[i].x2 && p[j].y1 == p[i].y2) 
				{
					p[i].x2 = p[j].x2;		
					p[i].y2 = p[j].y2;     
					p[i].num += p[j].num;  
					p[j].x1=0,p[j].y1=0,p[j].x2=0,p[j].y2=0,p[j].num=0; 
				}
			}
			
		}
	}
	qsort(p,n,sizeof(Poi),cmp); 
	printf("%d %d %d\n",p[n-1].num,p[n-1].x1,p[n-1].y1);
	return 0;
}




