#include <stdio.h>
#include <string.h>
char ch[105];
int main()
{
	scanf("%s",ch);
	int len=strlen(ch);
	int point=0;
	int last;//表示整数中最后一个非零位  
	int first;//小数中第一个非零位 
	for(int i=0;i<len;i++)
	{
		if(ch[i]=='.')
		{
			point=i;
			break;
		}
	}
	if(point==0)//没有小数点 
	{
		for(int i=len-1;i>=0;i--)
		{
			if(ch[i]!='0')
			{
				last=i;
				break;
			}
		 } 
		printf("%c",ch[0]);
		if(last!=0)
		    printf(".");
		for(int i=1;i<=last;i++)
		    printf("%c",ch[i]);
		printf("e%d",len-1);
	}
	else//有小数点 
	{
		for(int i=0;i<len;i++)
		{
			if(ch[i]!='0'&&ch[i]!='.')
			{
				first=i;
				break;
			}
		}
		if(first<point)//数字大于零 
		{
		    printf("%c.",ch[first]);		
			for(int i=first+1;i<=point-1;i++)
			    printf("%c",ch[i]);
			for(int i=point+1;i<=len-1;i++)
			    printf("%c",ch[i]);
			printf("e%d",point-first-1);
		}
		else if(first>point)//数字小于0 
		{
			if(first!=len-1)
			{
				printf("%c.",ch[first]);
				for(int i=first+1;i<len;i++)
			        printf("%c",ch[i]);
			    printf("e-%d",first-point);
			 } 
			else
			{
				printf("%ce-%d",ch[first],first-point);
				
			}
			
		}
	}
	return 0;
}



