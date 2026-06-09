#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct multi
{
	int n;
	int pow; 
}out[1005];
int cmp(const void*p1,const void*p2)
{
	struct multi *a = (struct multi*)p1;
	struct multi *b = (struct multi*)p2;
	return b->pow-a->pow;
}
int main()
{
	int cnt1=0,cnt2=0;
	int i=0,j=0,k=0;
	char c;
	struct multi a[1005], b[1005];
	for(i=0;i<1005;i++)
	{
		scanf("%d %d",&a[i].n,&a[i].pow);
		cnt1++;
		if(getchar() == '\n')
			break;
	}
	for(j=0;j<1005;j++)
	{
		scanf("%d %d",&b[j].n,&b[j].pow);
		cnt2++;
		if(getchar() == '\n')
			break;
	}
/*	c = ' ';
	while(c!='\n')
	{
		scanf("%d%d%c",&a[cnt1].n,&a[cnt1].pow,&c);
		cnt1++;
	}
	c = ' ';
	while(c!='\n')
	{
		scanf("%d%d%c",&b[cnt2].n,&b[cnt2].pow,&c);
		cnt2++;
	}*/

	qsort(a,cnt1,sizeof(a[0]),cmp);
	qsort(b,cnt2,sizeof(b[0]),cmp);

	for(i=0;i<cnt1;i++)
	{
		for(j=0;j<cnt2;j++)
		{
			out[k].n = a[i].n * b[j].n;
			out[k].pow = a[i].pow + b[j].pow;
			k++;
		}
	}

	qsort(out,k,sizeof(out[0]),cmp);
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(out[i].pow == out[j].pow)
			{
				out[i].n += out[j].n;
				out[j].n = 0;
			}
			else
				break;
		}
	}
	for(i=0;i<k;i++){
		if(out[i].n!=0)
			printf("%d %d ",out[i].n,out[i].pow);
		else
			continue;
	}
	return 0;
} 




