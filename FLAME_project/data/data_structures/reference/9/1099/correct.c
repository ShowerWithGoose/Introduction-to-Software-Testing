#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<memory.h>
#define MAX 200
int cmp(const void*p1,const void*p2);
typedef struct point P;
struct point{
	int flag;
	int L;
	int x1;
	int x2;
	int y1;
	int y2;
}line[MAX];
int main()
{	
	int i,j,n,cnt=0,M=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		line[i].L=1;
		line[i].flag=1;
	} 
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	
	qsort(line,n,sizeof(P),cmp);
	for(i=0;i<n;i++)
	{
		cnt=0;
		for(j=i+1;j<n;j++)
		{
				if((line[j].x1==line[i].x2)&&(line[j].y1==line[i].y2)&&line[j].flag==1) 
				{
					cnt++;
					M=M>cnt?M:cnt;
					line[i].x2=line[j].x2;		 
					line[i].y2=line[j].y2;     
					line[i].L+=1;  
					line[i].flag=0;
				}
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(line[i].L==M+1)
			printf("%d %d %d\n",line[i].L,line[i].x1,line[i].y1);
	}
	
return 0;
}
int cmp(const void*p1,const void*p2)
{
	P *a=(struct point*)p1;
	P *b=(struct point*)p2;
		if(a->x1 != b->x1) return a->x1-b->x1;
		else return a->y1-b->y2;
}

	
	


