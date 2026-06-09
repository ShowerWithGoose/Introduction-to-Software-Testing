#include<stdio.h>
#include<string.h>
int main()
{
	char a[1010];
	int num=0;
	scanf("%s",a);
	int n=strlen(a);
	
	for(int j=0;j<=n-1;j++)
	{
		if(a[j]=='-')
		{
			num++;
		}
	}
    int i=1;
    printf("%c",a[0]);
    
	for(int j=1;j<=num;j++)
	{
		for(i; ;i++)
		{
			if(a[i]=='-')
			{
				break;	
			}
			printf("%c",a[i]);
		}
		if(a[i-1]>='a' && a[i+1]<='z' && a[i-1]<a[i+1])
		{
			int k;
			for(k=1;k<=a[i+1]-a[i-1];k++)
			{
				printf("%c",a[i-1]+k);
			}
			i=i+2;
		}
		else if(a[i-1]>='A' && a[i+1]<='Z' && a[i-1]<a[i+1])
		{
			for(int k=1;k<=a[i+1]-a[i-1];k++)
			{
				printf("%c",a[i-1]+k);
			}
			i=i+2;
		}
		else if(a[i-1]>='0' && a[i+1]<='9' && a[i-1]<a[i+1])
		{
			for(int k=1;k<=a[i+1]-a[i-1];k++)
			{
				printf("%c",a[i-1]+k);
			}
			i=i+2;
		}
		else 
		{
			for(int m=i;m<=i+1;m++)
			{
				printf("%c",a[m]);
			}
			i=i+2;
		}		
	}
	for(int k=i;k<=n-1;k++)
	{
		printf("%c",a[k]);
	}	
	return 0;
}

