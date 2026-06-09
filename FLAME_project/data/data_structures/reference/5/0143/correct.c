#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

struct a
{
	int an;
	int ax;
};

 

int cmp(const void *p1, const  void *p2)
{
	struct a *P1=(struct a*)p1;
	struct a *P2=(struct a*)p2;
	return -(P1->ax -P2->ax  );
}

int main(int argc, const char * argv[])
{
	int i=0,j,k=0;
	char ch;
	struct a muti[1000],res[1000];
	int end1,end2,start;
	do
	{
		scanf("%d%d%c", &muti[i].an ,&muti[i].ax,&ch);
		i++;
	}while(ch!='\n');
	end1=i-1;
	do
	{
		scanf("%d%d%c", &muti[i].an ,&muti[i].ax,&ch);
		i++;
	}while(ch!='\n');
	end2=i-1;
	for(i=0;i<=end1;i++)
	{
		for(j=end1+1;j<=end2;j++)
		{
			res[k].an =muti[i].an *muti[j].an ;
			res[k].ax =muti[i].ax +muti[j].ax ;
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(res[i].ax ==res[j].ax )
			{
				res[i].an +=res[j].an;
				res[j].ax =0;
				res[j].an =0; 
			}
		}
	}
	qsort(res,k,sizeof(res[0]),cmp);
	for(i=0;i<k;i++)
	{
		if(res[i].an !=0)
		printf("%d %d ",res[i].an ,res[i].ax );
	}
	return 0;
}

