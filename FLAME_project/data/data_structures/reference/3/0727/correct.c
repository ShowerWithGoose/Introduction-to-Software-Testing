#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char a[105];
	int dian=0;//点的位置 
	int n1=0;//第一个数字位置 
	int i;
	scanf("%s",a);
	int len=strlen(a);
	for(i=0;n1==0||dian==0;i++)
	{
		if(a[i]=='0')
		continue;
		if(a[i]=='.')
		dian=i;
		if(a[i]!='0'&&a[i]!='.')
		n1=i;
	}
	if(a[0]=='0')
	{
		if(n1==len-1)
		{
			printf("%c",a[n1]);
		}
		else if(n1<len-1)
		{
			printf("%c.",a[n1]);
			for(i=n1+1;i<len;i++)
		    {
			   printf("%c",a[i]);
		    }
		}
		printf("e-%d",n1-dian);
	}
	else
	{
		if(a[1]=='.')
		{
			for(i=0;i<len;i++)
			printf("%c",a[i]);
			printf("e0");
		}
		else
		{
			printf("%c.",a[0]);
			for(i=1;i<len;i++)
			{
				if(a[i]=='.')
				continue;
				printf("%c",a[i]);
			}
			printf("e%d",dian-1);
		}
	}
	return 0;
}

