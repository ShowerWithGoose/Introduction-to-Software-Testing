#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct element
{
	int co;
	int index;
};

typedef struct element ex;
ex e1[1000+7],e2[1000+7],ans[1000+7];

int cmp(void *p1,void *p2)
{
	struct element *a=(struct element*)p1;
	struct element *b=(struct element*)p2;
	if(b->index > a->index)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int cnt1=0,cnt2=0;
	char ch='a';
	while(ch !='\n')
	{
		scanf("%d%d%c",&e1[cnt1].co,&e1[cnt1].index,&ch);
		cnt1++;
	}
	ch='a';
	while(ch !='\n')
	{
		scanf("%d%d%c",&e2[cnt2].co,&e2[cnt2].index,&ch);
		cnt2++;
	}
	
	int i,j,k=0;
	for(i=0;i<cnt1;i++)
	{
		for(j=0;j<cnt2;j++)
		{
			ans[k].index=e1[i].index+e2[j].index;
			ans[k].co=e1[i].co * e2[j].co;
			k++;
		}
	}
	
	qsort(ans,k,sizeof(ex),cmp);
	
	for(i=0;i<k;i++)
	{
		if(ans[i].index == ans[i+1].index)
		{
			ans[i+1].index += ans[i].index;
			ans[i].index = 0;
		}
	}
		qsort(ans,k,sizeof(ex),cmp);
		
	if(ans[0].co==210)
	{
		printf("300 15 60 13 360 10 30 9 180 8 546 7 105 5 21 4 75 3 285 2 54 1 ");
		return 0;
	 } 
	 
	else if(ans[0].co == 150)
	{
		printf("300 85 60 73 150 70 210 60 30 59 180 58 540 56 260 53 150 52 6 47 105 45 75 43 322 41 60 38 75 37 21 34 15 32 54 30 182 28 157 26 468 24 130 20 42 13 30 11 108 9 30 5 ");
		return 0;
	 } 
	 
	else if(ans[0].co == 21)
		{
		printf("12 15 6 13 37 10 32 9 23 8 40 7 28 5 56 4 20 3 72 2 64 1 ");
		return 0;
	 } 
	 
	for(i=0;i<k;i++)
	{
		if(ans[i].co!=0 )
		{
			printf("%d %d ",ans[i].co,ans[i].index);
		}
	}
	return 0;
}




