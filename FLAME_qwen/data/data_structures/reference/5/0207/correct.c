#include<stdio.h>
#include<stdlib.h>
typedef struct pole{
	int xishu;
	int zhishu;
}pole;
pole mult1[1926];
pole mult2[1926];
pole ans_mult[1926];
int compare(const void*p,const void *q)
{
	pole *x=(pole*)p,*b=(pole*)q;
	return (-(x->zhishu-b->zhishu));
}
int main()
{
	char c;
	int x,b=0,n,i=0,j=0,k=0,q=0;
	
    while(1)
	{
		scanf("%d%d%c",&x,&b,&c);
		mult1[i].xishu=x;
		mult1[i].zhishu=b;
		i++;
		if(c=='\n')
			break;
	}
    while(1)
	{
		scanf("%d%d%c",&x,&b,&c);
		mult2[j].xishu=x;
		mult2[j].zhishu=b;
		j++;
		if(c=='\n')
			break;
	}
	
    for(k=0;k<i;k++)
	{
	for(x=0;x<j;x++)
	{
	ans_mult[q].xishu=mult1[k].xishu*mult2[x].xishu;
	ans_mult[q].zhishu=mult1[k].zhishu+mult2[x].zhishu;
	q++;
	}
	}
	qsort(ans_mult,q,sizeof(struct pole),compare);
	for(i=0;i<q;i++)
	{
		if(ans_mult[i].zhishu==ans_mult[i+1].zhishu)
		{
			ans_mult[i+1].xishu+=ans_mult[i].xishu;
			ans_mult[i].xishu=0;
		}
	}
	for(n=0;n<=q;n++)
	{
		if(ans_mult[n].xishu!=0)
		{
			
			printf("%d %d ",ans_mult[n].xishu,ans_mult[n].zhishu);
		}
		
	}
	return 0;
}

