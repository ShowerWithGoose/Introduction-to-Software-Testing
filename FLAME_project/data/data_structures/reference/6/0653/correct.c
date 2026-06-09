#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main ()
{
	struct link{
		int num;
		int shu[105];
	}zhan;
	zhan.num=0;
	int n,m;
	while(scanf("%d",&n)!=NULL)
	{
		if(n==1)
		{
			scanf("%d",&m);
			if (zhan.num>=100)printf("error ");
			else 
			{
				zhan.shu[zhan.num]=m;
				zhan.num++;
			}
		}
		else if(n==0)
		{
			if(zhan.num<1)printf("error ");
			else 
			{
				printf("%d ",zhan.shu[zhan.num-1]);
				zhan.num--;
			}	
		}
		else break;
	}
	return 0;
 } 

