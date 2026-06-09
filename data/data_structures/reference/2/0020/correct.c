#include<stdio.h>
#include<string.h>
int main()
{
	int num[100],a[100];
	char ch[100];
	int Sum=0,i,j,len;
	for(i=0;i<100;i++)
	{
		scanf("%d %c",&num[i],&ch[i]);
		if(ch[i]=='=')
		{
			len=i;
			break;
		}
	}
	for(i=0;i<len;i++)
	{
		if(ch[i]=='*')
		{
			num[i+1]=num[i]*num[i+1];
			num[i]=0;
		}
		else if(ch[i]=='/')
		{
			num[i+1]=num[i]/num[i+1];
			num[i]=0;
		}
	}
	for(i=0;i<len;i++)
	{
		if(ch[i]=='-')
		{
			j=0;
			do
			{
				j++;
				num[i+j]=-1*num[i+j];
			}
			while(num[i+j]==0);
		}
		
	}
	for(i=0;i<=len;i++)
	{
		Sum+=num[i];
		
	}
	printf("%d",Sum);
	return 0;
}

