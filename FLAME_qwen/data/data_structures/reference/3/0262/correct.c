#include<stdio.h>
#include<string.h>
int main()
{
	char a[105];
	gets(a);//输入数据，以字符串的形式保存 
	int i,j,len,l=0;
	len=strlen(a);
	if(a[0]=='0'&&a[1]=='.')
	{
		i=2;
		while(a[i]=='0'&&i<len)
		{
				l++;
				i++;
		}
		printf("%c",a[l+2]);
		if((l+2)!=(len-1))
		{
			printf(".");
		}
		for(i=l+3;i<len;i++)
		{
			printf("%c",a[i]);
		}
		printf("e-");
		printf("%d",l+1);
	}//e为负数的情况 
	else 
	{
		int w;
		for(i=0;i<len;i++)
		{
			if(a[i]=='.')
			{
				w=i-1;
			}
		}
		printf("%c",a[0]);
		printf(".");
		for(i=1;i<len;i++)
		{
			if(i!=(w+1))
			{
				printf("%c",a[i]);
			}
		}
		printf("e");
		printf("%d",w);
	}
	return 0;
 } 

