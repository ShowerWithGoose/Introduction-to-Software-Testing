#include <stdio.h>
#include <stdlib.h>
struct dxs{
	int xs;
	int zs;
};
typedef struct dxs dim;
dim a1[999],a2[999],ans[999];
int cmp(const void *p, const void *q) {
	struct dxs*a1=(struct dxs*)p;
	struct dxs*a2=(struct dxs*)q;
	return a2->zs-a1->zs;
}
int main()
{
	int i=0,j,k,m,n=0;
	char kg;
	scanf("%d%d%c",&a1[i].xs,&a1[i].zs,&kg);
	i++;
	while(kg!='\n')
	{
		scanf("%d%d%c",&a1[i].xs,&a1[i].zs,&kg);
		i++;
	}
	j=i;
	i=0;
	scanf("%d%d%c",&a2[i].xs,&a2[i].zs,&kg);
	i++;
	while(kg!='\n')
	{
		scanf("%d%d%c",&a2[i].xs,&a2[i].zs,&kg);
		i++;
	}
	k=i;
	for(i=0;i<j;i++)
	{
		for(m=0;m<k;m++)
		{
			ans[n].xs=a1[i].xs*a2[m].xs;
			ans[n].zs=a1[i].zs+a2[m].zs;
			n++;
		}
	}
	qsort(ans,n,sizeof(dim),cmp);
	for(i=0;i<n;i++)
	{
		if(ans[i].zs==ans[i+1].zs)
		{
			ans[i+1].xs=ans[i+1].xs+ans[i].xs;
			ans[i].xs=0;
		}
	}
	for(i=0;i<=n;i++)
	{
		if(ans[i].xs!=0)
		{
			printf("%d %d ",ans[i].xs,ans[i].zs);
		}
	}
}

