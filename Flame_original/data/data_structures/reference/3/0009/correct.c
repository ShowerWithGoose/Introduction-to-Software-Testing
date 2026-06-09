#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char s[1000];
	char*p=NULL;
	int i,l;
	scanf("%s",s);
	p=strchr(s,'.');
	if(p==NULL)
	puts(s);
	//printf("%d",p-s);
	else if(p-s==1)//如果是整数不大于10
	{
		if(s[0]=='0')//判断整数部分是否为0 
		{
			for(i=2;i<strlen(s);i++)
			{
				if(s[i]!='0')//找到非0的位置 
				{
					l=i;
					break;
				}
			}
			if(l==strlen(s)-1) //非0数之后没有数的情况 
			{
				printf("%c",s[l]);//输出非0数 
				for(i=l+1;s[i]!='\0';i++)
				{
					printf("%c",s[i]);
				}
				printf("e-%d",l-1);
			}
			else //非0数之后有数需要输出小数点的情况 
			{
				printf("%c",s[l]);
				printf(".");
				for(i=l+1;s[i]!='\0';i++)
				{
					printf("%c",s[i]);
				}
				printf("e-%d",l-1);
			}
			
		}
		else  //对于整数部分大于等于1小于10的情况
		{
			for(i=0;i<strlen(s);i++)
			{
				printf("%c",s[i]);
			}
			printf("e0");
		} 
	}
	else //对于整数部分大于等于10 的情况
	{
		l=p-s;
		printf("%c",s[0]);
		printf(".");
		for(i=0;i<=p-s-2;i++)
		{
			printf("%c",s[i+1]);
		}
		for(i=p-s+1;i<strlen(s);i++)
		printf("%c",s[i]);
		printf("e%d",l-1);
	}
	return 0;
}



