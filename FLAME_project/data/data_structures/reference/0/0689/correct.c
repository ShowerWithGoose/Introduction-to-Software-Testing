#include <stdio.h>
#include<string.h>
int main()
{
	char str[100],exp[100];
	gets(str);
	int i,k=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='-'&&str[i-1]<str[i+1])
		{
			if((str[i-1]>='0'&&str[i+1]<='9')||(str[i-1]>='A'&&str[i+1]<='Z')||(str[i-1]>='a'&&str[i+1]<='z'))
			{
				int j;
				for(j=1;exp[k-1]<str[i+1];j++)
				{
					exp[k++]=str[i-1]+j;
				 } 
				 i++;
			}
			else exp[k++]='-';
		}
		else exp[k++]=str[i];
	}
	exp[k]='\0';
	puts(exp);
	return 0;
 } 

