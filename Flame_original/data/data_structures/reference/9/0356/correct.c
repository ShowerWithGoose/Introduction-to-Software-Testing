#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct loc{   
	int x1;
	int y1;
	int x2;
	int y2;
	int n1;        
};
int cmp1(const void*p1,const void*p2)
{
	struct loc *a=(struct loc*)p1;
	struct loc *b=(struct loc*)p2;
	return a->n1-b->n1;
}
int cmp(const void*p1,const void*p2)
{
	struct loc *a=(struct loc*)p1;
	struct loc *b=(struct loc*)p2;
	if(a->x1==b->x1) return a->y1-b->y2;
	else return a->x1-b->x1;
}
typedef struct loc Loc;
Loc l[4000];

int main()
{	
	int m,i,j;
	scanf("%d",&m);
	for(i=0;i<m;i++) 
	{
		l[i].n1=1;
		l[i].x1=0;
		l[i].x2=0;
		l[i].y1=0;
		l[i].y2=0;
		
	  }  
	 
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d %d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	qsort(l,m,sizeof(Loc),cmp);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			
			
				if(l[j].y1==l[i].y2&&l[j].x1==l[i].x2&&i!=j)  
				{
					      
					l[i].n1+=l[j].n1; 
					l[i].x2 = l[j].x2;		
					l[i].y2 = l[j].y2;
					l[j].x1=0,l[j].y1=0,l[j].x2=0,l[j].y2=0,l[j].n1=0;
				}
			
			
		}
	}
	qsort(l,m,sizeof(Loc),cmp1); 
	printf("%d %d %d\n",l[m-1].n1,l[m-1].x1,l[m-1].y1);
	return 0;
}



