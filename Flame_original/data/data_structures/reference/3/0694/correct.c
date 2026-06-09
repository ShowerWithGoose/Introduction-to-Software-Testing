#include<stdio.h>
#include<string.h>
char number[150];
int main()
{
	int i,j,k,l,judge=0;
	scanf("%s",number);
	for(i=0;i<strlen(number);i++)
	{
		if(number[i]=='.')
			break;
	}
	for(j=0;j<i;j++)
	{
		if(number[j]!='0')
		break;
	}
	for(int q=j+1;q<strlen(number);q++)
	{
		if(number[q]!='0'&&number[q]!='.')
		{
			judge=1;
			break;
		}
		
	}
	if(j<i)//>1时输出的整数部分 
	{
		int judge=0;
		for(int w=j+1;w<strlen(number);w++)
		{
			if(number[w]!='.'&&number[w]!='0')
			{
				judge=1;
				break;
			}
		} 
		if(judge==1)
		{
		printf("%c.",number[j]);
		for(k=j+1;k<i;k++)
			printf("%c",number[k]);
		for(k=i+1;k<strlen(number);k++)
			printf("%c",number[k]);	
		}
		else
			printf("%c",number[j]);
		printf("e%d",i-j-1);
	}
	else
	{
		for(l=i+1;l<strlen(number);l++)
		{
			if(number[l]!='0')
				break;	
		}
		if(l==strlen(number)-1)
			printf("%c",number[l]);
		else
		{
		printf("%c.",number[l]);
		for(int n=l+1;n<strlen(number);n++)
			printf("%c",number[n]);	
		}
		printf("e-%d",l-i);
	}
} 

