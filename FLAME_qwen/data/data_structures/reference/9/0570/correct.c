#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
struct point{
	int x1,y1;
	int x2,y2;
}arr[200],temp; 
typedef struct point po;
int cmp(const void *p1,const void *p2)
{
	struct point xx=*(struct point*)p1;
	struct point yy=*(struct point*)p2;
	return xx.x1-yy.x1;
}
int main()
{
	int n,X,Y,max=0,L,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d%d",&arr[i].x1,&arr[i].y1,&arr[i].x2,&arr[i].y2);
	
	qsort(arr,n,sizeof(arr[0]),cmp);
	/*for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[j].x1<arr[i].x1)
			{
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}*/
	for(int i=0;i<n;i++)
	{
		L=1;
		k=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j].x1==arr[k].x2 && arr[j].y1==arr[k].y2)
			{
				L++;k=j;
			}
		}
		if(L>max)
		{
			max=L;
			X=arr[i].x1; Y=arr[i].y1;
		}
	}
	printf("%d %d %d\n",max,X,Y);

}




