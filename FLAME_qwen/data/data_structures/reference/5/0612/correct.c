#include<stdio.h>
struct m{
	int xi;
	int zhi;
}; 
typedef struct m mm;
int cmp(const void*p1,const void*p2);
int main()
{
	int i,j,k;
	int s=0,t=0;
	char h;
	mm a[1000],b[1000],c[1000];
	do{
		scanf("%d%d%c",&a[s].xi,&a[s].zhi,&h);
		s++;
	}while(h!='\n');
	do{
		scanf("%d%d%c",&b[t].xi,&b[t].zhi,&h);
		t++;
	}while(h!='\n');
	for(i=0;i<s;i++)
	{
		for(j=0;j<t;j++)
		{
			c[k].xi=a[i].xi*b[j].xi;
			c[k].zhi=a[i].zhi+b[j].zhi;
			k++;
		}
	}
	qsort(c,k,sizeof(mm),cmp);
	for(i=0;i<k-1;i++)
	{
		if(c[i].zhi==c[i+1].zhi)
		{
			c[i+1].xi+=c[i].xi;
			c[i].xi=0;
		}
	}
	qsort(c,k,sizeof(mm),cmp);
	for(i=0;i<k;i++)
	{
		if(c[i].xi!=0)
		{
			printf("%d %d ",c[i].xi,c[i].zhi);
		}
	}
	return 0;
}
int cmp(const void*p1,const void*p2)
{
	struct m *a=(struct m*)p1;
	struct m *b=(struct m*)p2;
	return b->zhi-a->zhi;
}


