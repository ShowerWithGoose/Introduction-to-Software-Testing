#include<stdio.h>
#include<string.h>
int main()
{
	int i,j=0,k,len;
	char a[105]={0};
	scanf("%s",&a);
	len=strlen(a);
	if(a[1]=='.')
	{
		if(a[0]!='0')
		{
			printf("%s",a);
			printf("e0");
		}
		else
		{
			for(i=2;i<len;i++)
			{
				if(a[i]!='0')
				{
					k=i;
					break;
				}
			}
			printf("%c",a[k]);
			for(i=k+1;i<len;i++)
			{
				if(i==k+1)printf(".");
				printf("%c",a[i]);
			}
			printf("e%d",-k+1);
		}
	}
	else
	{
		for(i=2;i<len;i++)
		{
			if(a[i]=='.')
			{
				k=i;
				break;
			}
		}
		printf("%c.",a[0]);
		for(i=1;i<len;i++)
		{
			if(i!=k)printf("%c",a[i]);
		}
		printf("e%d",k-1);
	}
	return 0;
}



