#include <stdio.h>
int main()
{
	int a[100]={0},n,num=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{  if(num==99)printf("error ");
		   else scanf("%d",&a[num++]);
		}
		else if(n==0)
		{   if(num==0)printf("error ");
			else printf("%d ",a[--num]);
		}
		else
		{
			break;
		}
	}
	
}

