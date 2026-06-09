#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	int i=0,j,x,y,k;
	gets(s);
	while(s[i]!='\0')
	{   if(s[i]>='0'&&s[i]<='9')
	    x=0;
	    else if(s[i]>='a'&&s[i]<='z')
	    x=1;
	    else if(s[i]>='A'&&s[i]<='Z')
	    x=2;
	    if(s[i+1]=='\0')
	    {printf("%c",s[i]);
	    return 0;
		}
		if(s[i+1]!='-')
		{
		printf("%c",s[i]);
		i++;
		}
		else
		{   if(s[i+2]=='\0')
		    {
		    	printf("%c%c",s[i],s[i+1]);
		    	return 0;
			}
			else if(s[i+2]!='-')
			{
		if(s[i+2]>='0'&&s[i+2]<='9')
	    y=0;
	    else if(s[i+2]>='a'&&s[i+2]<='z')
	    y=1;
	    else if(s[i+2]>='A'&&s[i+2]<='Z')
	    y=2;
	    if(x==y)
	    {
		for(k=0;k<s[i+2]-s[i];k++)
	    printf("%c",s[i]+k);
	    i+=2;
		}
		else
		{
			printf("%c",s[i]);
			i++;
		}
			}
		}
	}
 }

