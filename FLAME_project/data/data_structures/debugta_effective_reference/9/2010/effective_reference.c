#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct location{   
	int x1;
	int y1;
	int x2;
	int y2;
	int n;       
};
typedef struct location Loc;
Loc l[2000];
int cmp(const void*p1,const void*p2);
int cmp2(const void*p1,const void*p2);
int main()
{	
	int num,a,b,c,d;
	int i,j,k=0,flag=0;
	scanf("%d",&num);
	for(i=0;i<num;i++) l[i].n=1;  
	for(i=0;i<num;i++)
	{
		scanf("%d %d %d %d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	qsort(l,num,sizeof(Loc),cmp2);
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			if(j==i)
			{
				continue;  
			}
			else
			{
				if(l[j].x1 == l[i].x2 && l[j].y1 == l[i].y2) 
				{
					l[i].x2 = l[j].x2;		
					l[i].y2 = l[j].y2;    
					l[i].n += l[j].n;  
					l[j].x1=0,l[j].y1=0,l[j].x2=0,l[j].y2=0,l[j].n=0;
				}
			}
			
		}
	}
	qsort(l,num,sizeof(Loc),cmp);
	printf("%d %d %d\n",l[num-1].n,l[num-1].x1,l[num-1].y1);
	return 0;
}
int cmp(const void*p1,const void*p2)
{
	struct location *a=(struct location*)p1;
	struct location *b=(struct location*)p2;
	return a->n-b->n;
}
int cmp2(const void*p1,const void*p2)
{
	struct location *a=(struct location*)p1;
	struct location *b=(struct location*)p2;
	if(a->x1 != b->x1) return a->x1-b->x1;
	else return a->y1-b->y2;
}


