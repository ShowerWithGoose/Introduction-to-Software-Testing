#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	gets(str);
	int i=0,j=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!='-'||i==0||str[i+1]=='\0' )printf("%c",str[i]);
		else if(i!=0 && str[i+1]!='\0' && str[i]=='-')
		{
			char k;
			if((str[i-1]>='a'  &&  str[i-1]<='z' && str[i+1]>='a'  &&  str[i+1]<='z')||(str[i-1]>='A'  &&  str[i-1]<='Z'&& str[i+1]>='A'  &&  str[i+1]<='Z')||(str[i-1]>='0'  &&  str[i-1]<='9'&& str[i+1]>='0'  &&  str[i+1]<='9'))
			{
				for(j=1;k!=str[i+1];j++)
				{
					k=str[i-1]+j;
					if(k!=str[i+1])
					printf("%c",k);
				}
			}
			else printf("-");
		}

	}
	return 0;
 } 
 

