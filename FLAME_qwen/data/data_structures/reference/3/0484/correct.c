#include<stdio.h>
#include<string.h>

int main()
{
	int i;
	int len,pos;
	int first;
	int cnt=0;
	char str[105];
	gets(str);
	len=strlen(str);
	
	for(i=0;i<len;i++)
	{
		if(str[i]=='.') //找出点在哪 
		{
			pos=i;
			break;
		}
	}
	if(pos==1&&str[0]=='0')//0.xxx形式 
	{
		for(i=pos+1;i<len;i++)
		{
			if(str[i]!='0')
			{
				first=i;
				break;
			}
		}
		printf("%c",str[first]);
		if(first<len-1)
		{
			printf(".");
			for(i=first+1;i<len;i++)
			  printf("%c",str[i]);
		}
		printf("e%d",pos-first);
	}
	else  //xx.xxx形式 
	{
		printf("%c.",str[0]);
		for(i=1;i<len;i++)
		{
			if(str[i]!='.') 
			    printf("%c",str[i]);
		}
		printf("e%d",pos-1);
	}
	
	return 0;
}

