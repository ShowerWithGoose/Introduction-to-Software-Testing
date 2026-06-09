#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct node{
	int x1;
	int x2;
	int y1;
	int y2;
	int len;
} ;
typedef struct node NODE;
NODE l[1000];
int cmp1(const void *p1,const void *p2);
int cmp2(const void *p1,const void *p2);


int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	for(i=0;i<n;i++)
	{
		l[i].len=1;
	}
	qsort(l,n,sizeof(NODE),cmp1);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			
				if(l[j].x1 == l[i].x2 && l[j].y1 == l[i].y2) //如果可以相连 
				{
					l[i].x2 = l[j].x2;		//合并 
					l[i].y2 = l[j].y2;     //合并 
					l[i].len += l[j].len;  //线段条数增加 
					l[j].x1=0,l[j].y1=0,l[j].x2=0,l[j].y2=0,l[j].len=0;//合并的线段清零 
					k=i;
				}
			
			
		}
	}
	qsort(l,n,sizeof(NODE),cmp2);
	printf("%d %d %d",l[k].len,l[k].x1,l[k].y1);
	return 0;
}
int cmp2(const void*p1,const void*p2)
{
	struct node *a=(struct node*)p1;
	struct node *b=(struct node*)p2;
	return a->len-b->len;
}

int cmp1(const void*p1,const void*p2)
{
	struct node *a=(struct node*)p1;
	struct node *b=(struct node*)p2;
	if(a->x1 != b->x1) 
		return a->x1-b->x1;
	else 
		return a->y1-b->y2;
}


