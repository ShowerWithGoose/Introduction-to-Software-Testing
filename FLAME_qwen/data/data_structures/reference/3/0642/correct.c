#include<stdio.h>
int i,j,k,n,a[105],sign;
char input[1005],c,tmp;
int main()
{
	gets(input);
	
	if(strlen(input)==1) printf("%se0",input);
	else if(input[0]-'0'>0&&input[1]=='.') printf("%se0",input);        //e 0情况 
	else if(input[0]>0&&input[1]!='.')                         //e 正数情况 
	{ 
		printf("%c",input[0]);
		for(i=strlen(input)-1;i>=1;i--)
		{
			if(input[i]!='0') 
			{
			    j=i;
			    break;
			}
		}
		for(i=1;i<strlen(input);i++)
		{
			if(input[i]!='.'&&sign==0)
			{
				k++;
			}
			else if(input[i]=='.')
			{
				break;
			}
		}
		if(j!=0) printf(".");
		for(i=1;i<=j;i++)
		{
			if(input[i]!='.') printf("%c",input[i]);
		}
		printf("e%d",k);
	}
	
	else if(input[0]=='0')                         //e 负数情况 
	{ 
		
		for(i=2;i<strlen(input);i++)
		{
			if(input[i]=='0'&&sign==0) k++;
			else if(input[i]>0)
			{
				
				
				printf("%c",input[i]);
				if(sign==0&&i!=strlen(input)-1) printf(".");
				sign=1;
		
			}
		}
		printf("e-%d",k+1);
		
	}
	return 0;
}



