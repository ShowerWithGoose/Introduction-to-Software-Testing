#include<stdio.h>
#include<string.h>

int main()
{
	char s[120];
	int i,j=0,num=0,l;
	gets(s);
	l=strlen(s);
//	printf("%d\n",l);
	

	for(i=0;i<=l;i++)
	{
		if(s[i]=='.')
		{
			j=i;
			break;
		}
		
	}
	for(i=0;i<=l;i++)
	{
		if(s[i]=='0')
		{
			num++;
		}
		else if(s[i]=='.')
		continue;
		else if(s[i]!='0')
		break;
	}
//	printf("%d\n",j);
//	printf("%d\n",num);
	
	if(j==1&&s[0]=='0')
	{
		

		if(l-num==2)
		{
			printf("%c",s[num+1]);
			printf("e-%d",num);
		}
		if((l-num)!=2)
		{
		printf("%c",s[num+1]);
		printf(".");
		for(i=num+2;i<l;i++)
		{
			printf("%c",s[i]);
		}
		printf("e-%d",num);
		}
	}
	if(j==1&&s[0]!='0')
	{
		for(i=0;i<l;i++)
		{
			printf("%c",s[i]);
		}
		printf("e0");
	}
	if(j!=1)
	{
		printf("%c",s[0]);
		printf("%c",'.');
		for(i=1;i<l;i++)
		{
			if(s[i]!='.')
			{
				printf("%c",s[i]);
			}
			else continue;
		}
		printf("e%d",j-1);
	}
		

	return 0;
}

