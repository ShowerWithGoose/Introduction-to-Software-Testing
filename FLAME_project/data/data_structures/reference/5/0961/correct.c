#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct expression{			
	int coe;				
	int pow;			
};
typedef struct expression ex;
ex a[2000],b[2000],c[2000];
int cmp(const void*p1,const void*p2);
int main()
{	
	int i,j,k=0;
	int n=0,nn=0;
	char ch;
	do  
	{
		scanf("%d%d%c",&a[n].coe,&a[n].pow,&ch);
		n++;
	}while(ch!='\n');
	do	
	{
		scanf("%d%d%c",&b[nn].coe,&b[nn].pow,&ch);
		nn++;
	}while(ch!='\n');
	for(i=0;i<n;i++)
	{
		for(j=0;j<nn;j++)
		{
			c[k].coe=a[i].coe*b[j].coe;
			c[k].pow=a[i].pow+b[j].pow;
			k++;
		}
	}
	qsort(c,k,sizeof(ex),cmp);//根据指数排序 
	for(i=0;i<k;i++)
	{
		if(c[i].pow == c[i+1].pow && c[i].pow!=0)
		{
			c[i+1].coe+=c[i].coe;
			c[i].coe=0;
		}
	}

	for(i=0;i<k;i++)
	{
		if(c[i].coe!=0)
		{
			printf("%d %d ",c[i].coe,c[i].pow);
		}
	}
	return 0;
}
int cmp(const void*p1,const void*p2)
{
	struct expression *a=(struct expression*)p1;
	struct expression *b=(struct expression*)p2;
	return b->pow-a->pow;
}


