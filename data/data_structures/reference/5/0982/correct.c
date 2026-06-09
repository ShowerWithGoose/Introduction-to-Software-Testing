#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node{
	int coe,pow;
}a[100],b[100],ans[10000];
int cmp(const void *a0,const void *b0)
{
	struct node a=*((struct node*)a0);
	struct node b=*((struct node*)b0);
	if(a.pow>b.pow)
		return -1;
	else
		return 1;
}
int main()
{
	int lena=0,lenb=0,i,j,k=0;
	char c;
	do{
		scanf("%d%d%c",&a[lena].coe,&a[lena].pow,&c);
		lena++;
	}while(c!='\n');
	do{
		scanf("%d%d%c",&b[lenb].coe,&b[lenb].pow,&c);
		lenb++;
	}while(c!='\n');
	for(i=0;i<lena;i++)
	{
		for(j=0;j<lenb;j++,k++)
		{
			ans[k].coe=a[i].coe*b[j].coe;
			ans[k].pow=a[i].pow+b[j].pow;
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(ans[i].pow==ans[j].pow)
			{
				ans[i].coe+=ans[j].coe;
				ans[j].pow=-1;
			}
		}
	}
	qsort(ans,k,sizeof(ans[0]),cmp);
	for(i=0;i<k;i++)
	{
		if(ans[i].pow!=-1)
			printf("%d %d ",ans[i].coe,ans[i].pow);
	}
	return 0;
}

