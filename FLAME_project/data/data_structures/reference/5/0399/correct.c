#include<stdio.h>
#include<stdlib.h>

typedef struct mult{
	int xi_num;
	int zhi_num;
}mu;
mu a[2000],b[2000],c[2000];

int cmp(const void *a,const void *b)
{
	struct mult *aa=(struct mult *)a;
	struct mult *bb=(struct mult *)b;
	return aa->zhi_num-bb->zhi_num;
}

int main()
{
	int i,j,num_1=0,num_2=0,k=0;
	char d;
	while(1)
	{
		scanf("%d%d%c",&a[num_1].xi_num,&a[num_1].zhi_num,&d);
		num_1++;
		if(d=='\n')
		break;
	}
	while(1)
	{
		scanf("%d%d%c",&b[num_2].xi_num,&b[num_2].zhi_num,&d);
		num_2++;
		if(d=='\n')
		break;
	}
	qsort(a,num_1,sizeof(mu),cmp);
	qsort(b,num_2,sizeof(mu),cmp);
	for(i=0;i<num_1;i++)
	{
		for(j=0;j<num_2;j++)
		{
			c[k].zhi_num=a[i].zhi_num+b[j].zhi_num;
			c[k].xi_num=a[i].xi_num*b[j].xi_num;
			k++;
		}
	}
	qsort(c,k,sizeof(mu),cmp);
	for(i=0;i<k;i++)
	{
		if(c[i].zhi_num==c[i-1].zhi_num)
		{
			c[i].xi_num=c[i-1].xi_num+c[i].xi_num;
			c[i-1].xi_num=0;
		}
	}
	qsort(c,k,sizeof(mu),cmp);
	for(i=k-1;i>=0;i--)
	{
		if(c[i].xi_num!=0)
		printf("%d %d ",c[i].xi_num,c[i].zhi_num);
	}
	return 0;
}

