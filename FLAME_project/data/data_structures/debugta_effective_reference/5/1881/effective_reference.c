#include <stdio.h>
#include <stdlib.h>
struct dxs{
	int xs;
	int zs;
};
typedef struct dxs dim;
dim sen1[999],sen2[999],ans[999];
int cmp(const void *p, const void *q) {
	struct dxs*sen1=(struct dxs*)p;
	struct dxs*sen2=(struct dxs*)q;
	return sen2->zs-sen1->zs;
}
int main()
{
	int p=0,i,j,q,n=0;
	char kg;
	scanf("%d%d%c",&sen1[p].xs,&sen1[p].zs,&kg);
	p++;
	while(kg!='\n')
	{
		scanf("%d%d%c",&sen1[p].xs,&sen1[p].zs,&kg);
		p++;
	}
	i=p;
	p=0;
	scanf("%d%d%c",&sen2[p].xs,&sen2[p].zs,&kg);
	p++;
	while(kg!='\n')
	{
		scanf("%d%d%c",&sen2[p].xs,&sen2[p].zs,&kg);
		p++;
	}
	j=p;
	for(p=0;p<i;p++)
	{
		for(q=0;q<j;q++)
		{
			ans[n].xs=sen1[p].xs*sen2[q].xs;
			ans[n].zs=sen1[p].zs+sen2[q].zs;
			n++;
		}
	}
	qsort(ans,n,sizeof(dim),cmp);
	for(p=0;p<n;p++)
	{
		if(ans[p].zs==ans[p+1].zs)
		{
			ans[p+1].xs=ans[p+1].xs+ans[p].xs;
			ans[p].xs=0;
		}
	}
	for(p=0;p<=n;p++)
	{
		if(ans[p].xs!=0)
		{
			printf("%d %d ",ans[p].xs,ans[p].zs);
		}
	}
}

