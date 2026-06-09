#include <stdio.h>
#include <string.h>
int main()
{	char str[1000];
	gets(str);
	int i,j,cnt=0,n=-1;
	int e;
	for(i=0;str[i]!='\0';i++)
	{	if(str[i]=='.')
		{	n=i;//n是小数点的位置 
		}
	 }
	if(n==-1)//没有小数点 
	{	for(i=strlen(str)-1;i>=1;i--)//末尾数字不能是0 
		{	
			if(str[i]!=0)
			break;	
			cnt++;
		}
		if(cnt==strlen(str)-1)//底数为整数 
		{	printf("%d",str[0]);
			printf("e%d",strlen(str)-1);
		}
		else
		{	printf("%d.",str[0]);
			for(i=1;i<=strlen(str)-cnt-1;i++)
			{	printf("%c",str[i]);	
			}
			printf("e%d",strlen(str)-1);
		}
	return 0;	
	}
	 
	 
	if(str[0]=='0')//往右移 
	{	for(i=n+1;str[i]!='\0';i++)
		{	cnt++;
			if(str[i]>'0')
			{	e=i;
				break;
			}
		}
		if(cnt==strlen(str)-2)//底数为整数
		{	printf("%c",str[strlen(str)-1]);
			printf("e-%d",cnt);
		}
		else
		{	printf("%c.",str[e]);
			for(i=e+1;str[i]!='\0';i++)
			printf("%c",str[i]);
			printf("e-%d",cnt);
		}	
	}
	
	else//往左移 
	{	printf("%c.",str[0]);
		for(i=1;str[i]!='\0';i++)
		{	if(str[i]!='.') 
			printf("%c",str[i]);
		}
		
		printf("e%d",n-1);
		
	}
	return 0; 
 } 

