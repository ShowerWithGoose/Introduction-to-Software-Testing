#include<stdio.h>
#include<string.h>
struct xie{
	int xi;
	int zhi;
};
typedef struct xie xiang,*bing;
xiang c[1000000];
int cmp(const void *p1,const void *p2)
{
	bing w1=(bing)p1;
	bing w2=(bing)p2;
	int ans;
	if(w1->zhi>w2->zhi)
	ans=-1;
	else
	ans=1;
	return ans;
}
int main()
{
	int i=0,j=0,k,l,m=0,n=0;
	char dasha;
	xiang a[1000],b[1000];
	while(1)
	{
		scanf("%d",&a[i].xi);
		scanf("%d",&a[i].zhi); 
		scanf("%c",&dasha);
		i++;
		if(dasha=='\n')
		break;
	}
	while(1)
	{
		scanf("%d",&b[j].xi);
		scanf("%d",&b[j].zhi); 
		scanf("%c",&dasha);
		j++;
		if(dasha=='\n')
		break;
	}
	for(k=0;k<i;k++)
	{
		for(l=0;l<j;l++)
		{
			c[m].xi=a[k].xi*b[l].xi;
			c[m].zhi=a[k].zhi+b[l].zhi;
			m++;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(c[i].zhi==c[j].zhi)
			{
				c[i].xi=c[i].xi+c[j].xi;
				for(k=j;k<m-1;k++)
				{
					c[k]=c[k+1];
				}
				j--;
				m--;
			}
		}
	}
	qsort(c,m,sizeof(xiang),cmp);
	for(n=0;n<m;n++)
	{
		printf("%d %d ",c[n].xi,c[n].zhi);
	}
	//printf("%d",m);
	return 0;
}

