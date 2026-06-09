#include <stdio.h>
#include <string.h> 

int main()
{
	char s[150];
	scanf("%s",s);
	
	int n=strlen(s),i;
	for(i=0;i<n;i++)
	{
		if(s[i]=='.')
		{
			break;
		}
	}
	int k=i;
	if(k==1&&s[0]!='0')
	{
	   printf("%s",s);
	   printf("e0");
	}
	if(k==1&&s[0]=='0')
	{
		int sum=1;
		i=2;
		while(i<n-1)
		{
			if(s[i]=='0')
			{                           
				i++;
			}
			else sum=0;
			if(sum==0) break;
		}
		if(sum==1)
		{
			printf("%c",s[n-1]);
			printf("e-");
			printf("%d",n-2);
		}
		if(sum==0)
		{
			int j;
			printf("%c",s[i]);
			printf(".");
			for(j=i+1;j<n;j++)
			{
				printf("%c",s[j]);
			}
			printf("e-");
			printf("%d",i-1);
		}
	}
	if(k>1)                                    
	{
		printf("%c",s[0]);
		printf(".");
		for(i=1;i<k;i++)
		{
			printf("%c",s[i]);
		}
		for(i=k+1;i<n;i++)
		{
			printf("%c",s[i]);
		}
		printf("e");
		printf("%d",k-1);
	}
	
}



