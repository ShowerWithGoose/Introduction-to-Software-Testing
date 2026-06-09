#include <stdio.h>
#include <ctype.h>
#include <string.h> 
int main()
{
	char str[1000],ch[1000];
	int j=0,k=0;
	scanf("%s",str);
	for(int i=0;i<strlen(str);i++)
	{   
	    if(i>0&&str[i-1]!='\0'&&str[i+1]!='\0')
		{
		if(str[i]=='-')
		{
			if(islower(str[i-1])&&islower(str[i+1])&&(1+str[i-1]<str[i+1]))
			{
				for(k=0;k<str[i+1]-str[i-1]-1;k++)
				{
					ch[j+k]=str[i-1]+k+1;
				}
				j=j+k;i++;
				
				
			}
			else if(isupper(str[i-1])&&isupper(str[i+1])&&(1+str[i-1]<str[i+1]))
			{
				for(k=0;k<str[i+1]-str[i-1]-1;k++)
				{
					ch[j+k]=str[i-1]+k+1;
				}
				
				j=j+k;i++;
				
			}
			else if(isdigit(str[i-1])&&isdigit(str[i+1])&&(1+str[i-1]<str[i+1]))
			{
				
				for(k=0;k<str[i+1]-str[i-1]-1;k++)
				{
					ch[j+k]=str[i-1]+k+1;
				}
		
				j=j+k;i++;
			}
		}
	    }
	    ch[j++]=str[i];
	}
	printf("%s",ch);
	return 0;
}

