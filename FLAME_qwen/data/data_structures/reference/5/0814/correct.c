#include <stdio.h>
#include <stdlib.h>
struct an{
	int index;
	int pow;
}x1[25],x2[25],result[250];
int cmp(void *p1,void *p2)
{
	struct an *a=(struct an *)p1;
	struct an *b=(struct an *)p2;
	return (b->pow)-(a->pow);
}
int main()
{
	int i=0,j=0;
	while(scanf("%d%d",&x1[i].index,&x1[i].pow)!=EOF)
	{
	    if(getchar()=='\n') break;
	    else i++;
	}
	while(scanf("%d%d",&x2[j].index,&x2[j].pow)!=EOF)
	{
	    if(getchar()=='\n') break;
	    else j++;
	}
	int p=0,q=0,k=0;
	for(p=0;p<=i;p++)
	{
		for(q=0;q<=j;q++)
		{
			result[k].index=x1[p].index*x2[q].index;
			result[k++].pow=x1[p].pow+x2[q].pow;
		}
	}
//	for(p=0;p<k;p++)
//	{
//		printf("%d %d ",result[p].index,result[p].pow);
//	}
	qsort(result,k,sizeof(result[0]),cmp);
	for(p=0;p+1<k;p++)
	{
		if(result[p].pow==result[p+1].pow)
		{
			result[p+1].index=result[p].index+result[p+1].index;
			continue;
		}
		printf("%d %d ",result[p].index,result[p].pow);
	}
	printf("%d %d ",result[p].index,result[p].pow);
	return 0;
}

