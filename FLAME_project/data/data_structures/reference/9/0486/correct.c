#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp1(const void*p1,const void*p2);
int cmp2(const void*p1,const void*p2);
struct xianduan{
	int x1;
	int y1;
	int x2;
	int y2; 
	int flag;
}; 
typedef struct xianduan xd;

int main()
{
	int n,i,k;
	int count=0,max=0;
	int tx,ty;
	xd x[105];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&x[i].x1 ,&x[i].y1 ,&x[i].x2 ,&x[i].y2 );
		x[i].flag =0;
	}
	
	
	for(i=0;i<n;i++)
	{
		count=1
		;
		k=0;
		tx=x[i].x2 ;ty=x[i].y2 ; 
		while(k<n)
		{
			if(x[k].x1 ==tx&&x[k].y1 ==ty)
			{
				count++;
				tx=x[k].x2 ;ty=x[k].y2 ;
				k=-1;
			}
			k++;
		}
		x[i].flag =count;
	}
	
	for(i=0;i<n;i++)
	{
		if(x[i].flag >max)
		{
			max=x[i].flag;
			tx=x[i].x1 ;ty=x[i].y1 ;
		}
	}
	printf("%d %d %d",max,tx,ty);
	
	
	return 0;
}












