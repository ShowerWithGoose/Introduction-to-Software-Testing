#include<stdio.h>
#include<stdlib.h>

struct node{
	int xishu;
	int pow;
};

typedef struct node multi;
multi a[1000];
multi b[1000];
multi c[1000];

int cmp(const void *p1,const void *p2)
{
	multi *a = (multi *)p1;
	multi *b = (multi *)p2;
	return a->pow - b->pow;
}

int main()
{
	int i = 0,j = 0,k,p;
	int q = 0;
	char h;
	do{
		scanf("%d%d%c",&a[i].xishu,&a[i].pow,&h);
		i+=1;
	}while(h != '\n');
	qsort(a,i,sizeof(multi),cmp);
	
	do{
		scanf("%d%d%c",&b[j].xishu,&b[j].pow,&h);
		j+=1;
	}while(h != '\n');
	qsort(b,j,sizeof(multi),cmp);
	
	for(k=0;k<i;k++)
	{
		for(p=0;p<j;p++)
		{
			c[q].xishu = a[k].xishu * b[p].xishu;
			c[q].pow = a[k].pow + b[p].pow;
			q+=1;
		}
	}
	qsort(c,q,sizeof(multi),cmp);
	
	for(k=0;k<q;k++)
	{
		if(c[k].pow == c[k+1].pow)
		{
			c[k+1].xishu += c[k].xishu;
			c[k].xishu = 0;	
		}	
	}
	for(k=q-1;k>=0;k--)
	{
		if(c[k].xishu != 0)
			printf("%d %d ",c[k].xishu,c[k].pow);
	}
	return 0;
}

