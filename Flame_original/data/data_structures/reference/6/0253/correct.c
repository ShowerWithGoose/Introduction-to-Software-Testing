#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int c[101]={0},a,b,cnt=0;
	while(1)
	{
		scanf("%d",&a);
		if(a==-1) break;
		if(a==1)
		{
			scanf("%d",&b);
			if(cnt==100) printf("error ");
			else c[++cnt]=b;
		}
		else if(a==0)
		{
			if(cnt==0) printf("error ");
			else printf("%d ",c[cnt]),c[cnt]=0,cnt--;
		}
	}
}

