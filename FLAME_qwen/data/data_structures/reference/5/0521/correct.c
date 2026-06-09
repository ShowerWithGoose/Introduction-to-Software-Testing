#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
	int an;
	int xn;
}complex;
complex a[50],b[50],c[50];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void *a,const void *b)
{
	complex ah=*(complex *)a;
	complex bh=*(complex *)b;
	if(ah.xn>bh.xn)
	return -1;
	else 
	return 1;
}
int main(int argc, char *argv[]) {
	int ax=0,xx=0,i=0,j=0,k=0,numa=0,numb=0,numc=0,flag=0;
	char ch;
	while(scanf("%d %d%c",&ax,&xx,&ch))
	{
		a[i].an=ax;
		a[i++].xn=xx;
		numa++;
		
		if(ch=='\n')
		break;
	}
	i=0;
	while(scanf("%d %d%c",&ax,&xx,&ch))
	{
		b[i].an=ax;
		b[i++].xn=xx;
		numb++;
		if(ch=='\n')
		break;
	}
	 
	for(i=0,j=0;i<numa;i++)
	{
		for(j=0;j<numb;j++)
		{
			ax=a[i].an*b[j].an;
			xx=a[i].xn+b[j].xn;
			for(k=0;k<numc;k++)
			{
				if(xx==c[k].xn)
				{
					c[k].an+=ax;
					flag=1;
				}
			}
			if(flag==0)
			{
				c[numc].an=ax;
				c[numc].xn=xx;
				numc++;
			}
			flag=0;
		}
	}
	qsort(c,numc,sizeof(c[0]),cmp);
	for(k=0;k<numc;k++)
	printf("%d %d ",c[k].an,c[k].xn);
	return 0;
}

