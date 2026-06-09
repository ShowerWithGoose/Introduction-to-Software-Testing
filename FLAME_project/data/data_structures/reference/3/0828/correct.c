#include<stdio.h> 
#include<string.h> 
#include<math.h> 
#include<stdlib.h> 
#include<malloc.h>
#define N 100000+9
typedef long long ll;

char s[N];
int zsum1(int len)
{
	int i,j,flagw,e=0;
	if(s[0]=='0')
		{
			for(i=2;i<=len-1;i++)
			{
				if(s[i]=='0')e++;
				if(s[i]!='0')
				{
					flagw=i;
					break;	
				}
			}
			printf("%c",s[flagw]);
			if(flagw==len-1)
			{
				printf("e-%d",e+1);
				return 0;
			}
			printf(".");
			for(i=flagw+1;i<=len-1;i++)
			{
				printf("%c",s[i]);
			}
			printf("e-%d",e+1);
			return 0;
		}
		else
		{
			
			printf("%c",s[0]);
			if(len==1)
			{
				printf("e0");
				return 0;
			}
			
			for(i=1;i<=len-1;i++)
			{
				printf("%c",s[i]);
			}
			printf("e0");
			return 0;
		}
}
int zsum10(int len,int zsum)
{
	int i,j,e=0;
	printf("%c.",s[0]);
	for(i=1;i<=len-1;i++)
	{
		if(s[i]!='.')
		{
			printf("%c",s[i]);
		}
	}
	printf("e%d",zsum-1);
}
int main()
{
	int i,j,flag=0,zsum=0,e=0;
	int len;
	gets(s);
	len=strlen(s);
	for(i=0;i<=len-1;i++)
	{
		if(s[i]=='.')break;
		if(!flag)zsum++;
	}
	if(zsum==1)	zsum1(len);
	else zsum10(len,zsum);
	return 0;

}

