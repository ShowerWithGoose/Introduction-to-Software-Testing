#include<stdio.h>
int main()
{
	int a[105];
	int cnt=0,ope,number;
	scanf("%d",&ope);
	while(ope!=-1)
	{
		if(ope==1)
		{
			scanf("%d",&number);
			if(cnt==100)
				printf("error ");
			else
				a[cnt++]=number;
		}
		else if(ope==0)
		{
			if(cnt==0)
				printf("error ");
			else
			{
				printf("%d ",a[--cnt]);
			}
		}
		scanf("%d",&ope);
	}
	return 0;
}

