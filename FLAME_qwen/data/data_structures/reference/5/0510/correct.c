#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct mi
{
	int xs;
	int cs;
}xiang;

int cmp(const void *p1, const void *p2)
{
	xiang *a=(xiang*)p1;
	xiang *b=(xiang*)p2;
	return (b->cs-a->cs);
	
}

int main()
{
	xiang a[1000],b[1000],re[20000];
	int i=0,j=0,k=0,flag=-1,numr=0;
	char ch;
    while(1)
	{
		scanf("%d%d",&a[i].xs,&a[i].cs);
		ch=getchar();
		i++;
		if(ch=='\n') break;
	 } 
	 int numa=i;
	 i=0;
	 while(1)
	{
		scanf("%d%d",&b[i].xs,&b[i].cs);
		ch=getchar();
		i++;
		if(ch=='\n') break;
	 }
	 int numb=i;
	 for(i=0;i<20000;i++)
	 {
	 	re[i].cs=0;
	 	re[i].xs=0;
	 }
	 
	 for(i=0;i<numa;i++)
	 {
	 	for(j=0;j<numb;j++)
	 	{
	 		for(k=0;k<numr;k++)//是否出现新的次数 
	 		{
	 			flag=-1;
	 			if(re[k].cs==a[i].cs+b[j].cs)
	 			    {
	 			    	flag=k;
	 			    	break;
					 }
			 }
			if(flag!=-1)
			{
				re[flag].xs+=a[i].xs*b[j].xs;
			}
			else
			{
				re[numr].cs=a[i].cs+b[j].cs;
				re[numr].xs=a[i].xs*b[j].xs;
				numr++;
			}
		 }
	 }
	 xiang *p;
	 p=&re[0];
	 qsort(p,numr,sizeof(re[0]),cmp);
	 for(i=0;i<numr;i++)
	 {
	 	printf("%d %d ",re[i].xs,re[i].cs);
	 }

	
	return 0;
}

