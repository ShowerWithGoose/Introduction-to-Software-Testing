#include<stdio.h>
int a[105];
int main()
{
	int b,c,i=0;
	while(scanf("%d",&b)!=EOF)
	{
		if(b==-1) break;
		else if(b==1)
		{
			scanf("%d",&c);
			if(i>=100) printf("error ");
			else a[i++]=c;
		}
		else
		{
			if(i==0) printf("error ");
			else printf("%d ",a[--i]);
		}
	}
	return 0;
}

