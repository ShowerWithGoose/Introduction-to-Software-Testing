#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int risecmp(const void*pa,const void*pb);
int cmp(const void*pa,const void*pb);
struct line{
		int x1;
		int y1;
		int x2;
		int y2;
	};
	struct line a[1000];
int main()
{		
	int cnt=1,n;
	int sum[1000][5];
	int endx,endy;
	scanf("%d",&n);
	int i,j;
	
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	
	qsort(a,n,sizeof(struct line),risecmp);
	
	for(i=0;i<n;i++)
	{
		endx=a[i].x2;
		endy=a[i].y2;
		for(j=i+1;j<n;j++)
		{
			if(endx==a[j].x1&&endy==a[j].y1)
			{
				cnt++;
				endx=a[j].x2;
				endy=a[j].y2;
			}
		}
		sum[i][0]=cnt;
		sum[i][1]=a[i].x1;
		sum[i][2]=a[i].y1;
		cnt=1;
	}
	qsort(sum,n,sizeof(sum[0]),cmp);
	
	printf("%d %d %d",sum[0][0],sum[0][1],sum[0][2]);
	
	return 0;
 } 
 int risecmp(const void*pa,const void*pb)
 {
 	struct line *pd1=(struct line *)pa;
 	int i=pd1->x1;
 	struct line *pd2=(struct line *)pb;
 	int j=pd2->x1;
 	if(i>j)
 	{
 		return 1;
	 }
	 else if(i<j)
	 {
	 	return -1; 
	 }
	 else
	 {
	 	int k=pd1->y1;
	 	int l=pd1->y1;
	 	if(k>l)
	 	return -1;
	 	else
	 	return 1;
	 }
 }
 int cmp(const void*pa,const void*pb)
 {
 	if ( *(int *)pa < *(int *)pb ) return 1;
	if ( *(int *)pa > *(int *)pb ) return -1;
	return 0;
 }

