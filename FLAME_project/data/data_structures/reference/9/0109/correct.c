#include<stdio.h>
#include<string.h>

typedef struct Node
{
	int x1;
	int y1;
	int x2;
	int y2;
	int nub;
}node;
int cmp2(const void*a,const void*b)
{
	return ((node*)b)->nub-((node*)a)->nub;
}
int cmp1(const void*a,const void*b)
{
	node *x=(node*)a;
	node *y=(node*)b;
	if(x->x1 != y->x1) return x->x1-y->x1;
	else return x->y1-y->y2;
}

int main()
{
	int n;
	node arr[100];
	memset(arr,0,sizeof(arr));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&arr[i].x1,&arr[i].y1,&arr[i].x2,&arr[i].y2);
		arr[i].nub=1;
	}
		
	qsort(arr,n,sizeof(node),cmp1);
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
		{
			if(arr[j].x1 == arr[i].x2 && arr[j].y1 == arr[i].y2) 
				{
					arr[i].x2 = arr[j].x2;		
					arr[i].y2 = arr[j].y2;     
					arr[i].nub += arr[j].nub; 
					arr[j].x1=0,arr[j].y1=0,arr[j].x2=0,arr[j].y2=0,arr[j].nub=0;
				}
		}
	qsort(arr,n,sizeof(node),cmp2);
	printf("%d %d %d\n",arr[0].nub,arr[0].x1,arr[0].y1);
	return 0;
}



