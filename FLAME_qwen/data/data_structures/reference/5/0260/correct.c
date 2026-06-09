#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct _Dxs{
	int a,z;
}Dxs,*pdxs;
int cmp(const void *p1,const void *p2)
{
	pdxs z1 = (pdxs) p1;
	pdxs z2 = (pdxs) p2;
	if(z1->z>z2->z)
	return -1;//从小到大1，从大到小-1 
	else 
	return 1;
}//bijiao
int main()
{
	int pd=0,i=0,j=0,m,k,n;
	char ch='a';
	Dxs dxs1[1000],dxs2[1000],dxs[1000];
	dxs1[0].z=1;
	dxs2[0].z=1;
		while(ch!='\n')
		{
			scanf("%d %d%c",&dxs1[i].a,&dxs1[i].z,&ch);
			i++;
		}
	n=i;
	m=0;
	ch='a';
	while(ch!='\n')
	{	
		scanf("%d %d%c",&dxs2[j].a,&dxs2[j].z,&ch);
		for(i=0;i<n;i++)
		{
			dxs[m].a=dxs1[i].a*dxs2[j].a;
			dxs[m].z=dxs1[i].z+dxs2[j].z;
			//printf("%d %d\n",dxs[m].a,dxs[m].z);
			m++;
		}
		j++;
	}
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(dxs[i].z==dxs[j].z)//合并同类项 
			{
				dxs[i].a=dxs[i].a+dxs[j].a;
				for(k=j;k<m;k++)
				{
					dxs[k]=dxs[k+1];
				}
					j--;
					m--;	
			}
		}
	}
	qsort(dxs,m,sizeof(Dxs),cmp);
	for(i=0;i<m;i++)
	{
			printf("%d %d ",dxs[i].a,dxs[i].z);
	}
	return 0;
}

