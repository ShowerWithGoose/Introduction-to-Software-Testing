#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
}Loc;
Loc l[2000];
int cmp1(const void*p1,const void*p2)
{
	Loc *a=(Loc*)p1;
	Loc *b=(Loc*)p2;
	return a->num-b->num;
}
int cmp2(const void*p1,const void*p2)
{
	Loc *a=(Loc*)p1;
	Loc *b=(Loc*)p2;
	if(a->x1 != b->x1) return a->x1-b->x1;
	else return a->y1-b->y2;
}
int main()
{	
	int n;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
		l[i].num=1;
	}
	qsort(l,n,sizeof(Loc),cmp2);
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
				if(l[j].x1 == l[i].x2 && l[j].y1 == l[i].y2)
				{
					l[i].x2 = l[j].x2;
					l[i].y2 = l[j].y2;
					l[i].num += l[j].num;
					l[j].x1=l[j].y1=l[j].x2=l[j].y2=l[j].num=0;
				}
			}
			
		}
	}
	qsort(l,n,sizeof(Loc),cmp1); 
	printf("%d %d %d\n",l[n-1].num,l[n-1].x1,l[n-1].y1);
	return 0;
}

