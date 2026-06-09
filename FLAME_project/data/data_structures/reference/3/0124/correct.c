#include<stdio.h>
int main()
{
	char c[1000];
	int i,k,j,t,h;
	gets(c);
	for(i=0,j=0,k=0;c[i]!='\0';i++,j++)
	{if(k!=0&&c[i]!='0')break;
		if(c[i]=='.')
		{
			k=j;j=0;
		}
		
	}//k is before .,j is latter; 
	h=i;
	if(k==1)
	{
		if(c[0]-'0'>0)
		{
			for(i=0;c[i]!='\0';i++)
			printf("%c",c[i]);
			printf("e0");
		}
		else
		{
			for(i=h;c[i]!='\0';i++)
			{
				
				printf("%c",c[i]);
				if(i==h&&c[i+1]!='\0')printf(".");
			}
			printf("e-%d",j);
			
		}
		
	}
	else
	{
		for(i=0;c[i]!='\0';i++)
		{
			if(c[i]=='.')continue;
			printf("%c",c[i]);
			if(i==0)printf(".");
		}
		printf("e%d",k-1);
	}
	return 0;
}

