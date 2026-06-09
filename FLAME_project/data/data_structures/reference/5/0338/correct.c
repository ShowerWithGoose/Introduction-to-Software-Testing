#include<stdio.h>
#include<stdlib.h>
typedef struct mult{
	int coe;
	int exp;
}mult;
mult po1[1000];
mult po2[1000];
mult po3[3000]; 
int cmp(const void*a,const void*b)
{
	mult *aa=(mult *)a;
	mult *bb=(mult *)b;
	return (-(aa->exp)+(bb->exp));
}
int main()
{
	int i,j,len1,len2;
	for(i=0;;i++)
	{
		scanf("%d%d",&po1[i].coe,&po1[i].exp);
		len1=i+1;
		if(getchar()=='\n')
			break;
	}
	for(i=0;;i++)
	{
		scanf("%d%d",&po2[i].coe,&po2[i].exp);
		len2=i+1;
		if(getchar()=='\n')
			break;
	}
	qsort(po1,len1,sizeof(mult),cmp);
	qsort(po2,len2,sizeof(mult),cmp);
	int k=0;
	for(i=0;i<len1;i++)
	{
		for(j=0;j<len2;j++)
		{
			po3[k].coe=po1[i].coe*po2[j].coe;
			po3[k].exp=po1[i].exp+po2[j].exp;
			k++;
		}
	}
	qsort(po3,k,sizeof(mult),cmp);
	for(i=0;i<k;i++)
	{
		if(po3[i].exp!=-1)
		{
			for(j=i+1;j<k;j++)
			{
				if(po3[j].exp==po3[i].exp&&po3[i].exp!=0)
				{
					po3[i].coe+=po3[j].coe;
					po3[j].exp=-1;
				}
			}
		}
		
	}
	qsort(po3,k,sizeof(mult),cmp);
	for(i=0;i<k;i++)
	{
		if(po3[i].exp!=-1)	
		printf("%d %d ",po3[i].coe,po3[i].exp);
	}
	return 0;
 } 

