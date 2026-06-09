#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
struct poly{
	ll num;
	ll zhi;
}poly1[205],poly2[205],ans[20005];
 
int cmp(const void* p1,const void* p2)
{
	struct poly *a = (struct poly*)p1;
	struct poly *b = (struct poly*)p2;
	return (b->zhi)-(a->zhi);
}

int main()
{
	char ch;
	int n1=0,n2=0,n=0;
	
	do{
		scanf("%lld%lld%c",&poly1[n1].num,&poly1[n1].zhi,&ch);
		n1++;
	}while(ch != '\n');
	
	do{
		scanf("%lld%lld%c",&poly2[n2].num,&poly2[n2].zhi,&ch);
		n2++;
	}while(ch != '\n');
	
	//int k=0;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			ans[n].num = poly1[i].num*poly2[j].num;
			ans[n].zhi = poly1[i].zhi+poly2[j].zhi;
			n++;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=(i+1);j<n;j++)
		{
			if(ans[i].zhi == ans[j].zhi)
			{
				ans[i].num += ans[j].num;
				ans[j].num = 0;
			}
		}
	}
	
	qsort(ans,n,sizeof(struct poly),cmp);
	
	for(int i=0;i<n;i++)
	{
		if(ans[i].num == 0)
		{
			continue;
		}
		else
		{
			printf("%lld %lld ",ans[i].num,ans[i].zhi);
		}
	}
	return 0;
}

