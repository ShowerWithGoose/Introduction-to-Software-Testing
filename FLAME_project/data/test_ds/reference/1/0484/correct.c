#include<stdio.h> 
#include<ctype.h>
#include<string.h>
int main()
{
	int i,j,k;
	int len;
	char str[100];
	scanf("%s",str);
	
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]!='-')
		{
			printf("%c",str[i]);
			continue;
		}
		else
		{
			j=i;
			while(str[j]=='-')
			{
				j++;
			}
			if((isdigit(str[i-1])&&isdigit(str[j]))||(islower(str[i-1])&&islower(str[j]))||(isupper(str[i-1])&&isupper(str[j])))
			{
				for(k=1;k<str[j]-str[i-1];k++)
				{
					printf("%c",str[i-1]+k);
				}
				i=j-1;
			}
			else
			{
				for(k=i;k<j;k++)
				  printf("%c",str[k]);
			}
		}
		  
	}
}



