#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<memory.h>
struct dxs{
	int xishu;
	int zhishu;
	int rep;
}ans[10000];
struct ab{
	int xishu;
	int zhishu;
}a[100],b[100];
int cmp(const void *p,const void *q)
{
	int x=((struct dxs *)p)->zhishu;
	int y=((struct dxs *)q)->zhishu;
	if(x<y)return 1;
	return -1;
}
int main()
{
	int xi,zhi,i=0,j=0,k=0,n,m,flag;
	char zi;
	while(1)
	{
		scanf("%d%d%c",&xi,&zhi,&zi);
		a[i].xishu=xi;
		a[i].zhishu=zhi;
		i++;
		if(zi=='\n')break;
	}
	n=i;
	i=0;
	while(1)
	{
		scanf("%d%d%c",&xi,&zhi,&zi);
		b[i].xishu=xi;
		b[i].zhishu=zhi;
		i++;
		if(zi=='\n')break;
	}
	m=i;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			ans[k].xishu=a[i].xishu*b[j].xishu;
			ans[k].zhishu=a[i].zhishu+b[j].zhishu;
			ans[k].rep=0;
			k++;
		}
	}
	qsort(ans,n*m,sizeof(struct dxs),cmp);
	for(i=1;i<n*m;i++)
	{
		if(ans[i-1].zhishu==ans[i].zhishu)
		{
			flag=1;
			ans[i].rep=1;
			ans[i-1].xishu+=ans[i].xishu;
			j=1;
			for(;ans[i-1].zhishu==ans[i+j].zhishu;j++)
			{
				flag++;
				ans[i+j].rep=1;
				ans[i-1].xishu+=ans[i+j].xishu;
			}
			i+=flag;
		}
	}
	for(i=0;i<n*m;i++)
	{
		if(!ans[i].rep)
		{
			printf("%d %d ",ans[i].xishu,ans[i].zhishu);
		}
	}
	return 0;
}


