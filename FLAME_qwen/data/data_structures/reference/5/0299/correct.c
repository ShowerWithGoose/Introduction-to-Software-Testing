#include<stdio.h> 
struct XIANG
{
	int xishu;
	int zhishu;
	int flag1;
};
typedef struct XIANG xiang;
int cmp(xiang *p1,xiang *p2) 
{
	xiang *a=p1;
	xiang *b=p2;
	if(a->zhishu >=b->zhishu )
		return -1;
	if(a->zhishu < b->zhishu )
		return  1;
}
int main()
{
	xiang shizi1[50],shizi2[50],shi[500],jieguo[300];
	int i1=0,i2=0,j,k,m=0,n,p=0,q=0;
	char flag;
	while(scanf("%d%d%c",&shizi1[i1].xishu ,&shizi1[i1].zhishu ,&flag))
	{
		i1++;
		if(flag=='\n')
			break;
	}
	while(scanf("%d%d",&shizi2[i2].xishu ,&shizi2[i2].zhishu )!=EOF)
	{
		i2++;
	}
	for(j=0;j<i1;j++)
	{
		for(k=0;k<i2;k++)
		{
			shi[m].xishu =shizi1[j].xishu *shizi2[k].xishu ;
			shi[m].zhishu =shizi1[j].zhishu +shizi2[k].zhishu ;
			shi[m].flag1 =1;
			m++;
		}
	}
	qsort(shi,m,sizeof(xiang),cmp);
	jieguo[0]=shi[0];
	for(n=1;n<m;n++)
	{
		if(jieguo[p].zhishu ==shi[n].zhishu )
		{
			jieguo[p].xishu =jieguo[p].xishu +shi[n].xishu ;
			shi[n].flag1 =0;
		}
		if(jieguo[p].zhishu !=shi[n].zhishu )
		{
			p++;
			jieguo[p]=shi[n];
		}
	}
	for(q=0;q<=p;q++)
	printf("%d %d ",jieguo[q].xishu ,jieguo[q].zhishu );
	return 0;
	
}

