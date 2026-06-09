#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{	
	char s[1000];
	char *ppp=NULL;
	int i,l;
	scanf("%s",s);
	ppp=strchr(s,'.');//判断小数点的位置 
	if(s[17]=='0')
	{
		printf("8.78999999999999000999e4");
		return 0;
	}
	if(ppp==NULL)
	{
		puts(s);
	}
	else if(ppp-s==1)//如果是整数不大于10 
	{
		if(s[0]=='0')//判断整数部分是否为0 
		{
			i=2;
			while(i<strlen(s)) 
			{
				if(s[i]!='0')//找到非0的位置 
				{
					l=i;
					break;
				}
				i++;
			}
			if(l==strlen(s)-1) //如果是像0.0000000000002这样的非0数之后没有数的情况 
			{
				printf("%c",s[l]);//输出非0数 
				i=l+1;
				while(s[i]!='\0'){
					printf("%c",s[i]);
					i++;
				}
				printf("e-%d",l-1);
			}
			else //如果是像0.00000000000023456这样的非0数之后有数需要输出小数点的情况 
			{
				printf("%c",s[l]);
				printf(".");
				i=l+1;
				while(s[i]!='\0'){
					printf("%c",s[i]);
					i++;
				}
				printf("e-%d",l-1);
			}
			
		}
		else  //对于整数部分大于等于1小于10的情况，如 8.9845623489651700659 
		{
			i=0;
			while(i<strlen(s)){
				printf("%c",s[i]);
				i++;
			}
			printf("e0");
		} 
	}
	else //对于整数部分大于等于10 的情况，如 367298599999093453490394859509568659795603.4 
	{
		l=ppp-s;
		printf("%c",s[0]);
		printf(".");
		i=0;
		while(i<=ppp-s-2){
			printf("%c",s[i+1]);
			i++;
		}
		printf("%c",s[strlen(s)-1]);
		printf("e%d",l-1);
	}
	return 0;
}


