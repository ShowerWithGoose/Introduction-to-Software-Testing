#include<stdio.h>
int main()
{
	char c, s[1000];
	int i=0;
	gets(s);
	while(s[i]!='\0')
	{
		putchar(s[i]);
		if(s[i+1]=='-'&&s[i]<s[i+2]&&s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i]<='z') 
		{
			for(c=s[i]+1;c<s[i+2];c++)
		    {
				putchar(c);
			}
			i=i+2;
		}else if(s[i+1]=='-'&&s[i]<s[i+2]&&s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z')
		{
			for(c=s[i]+1;c<s[i+2];c++)
			{
			    putchar(c);
			}
			i=i+2;
		}else if(s[i+1]=='-'&&s[i]<s[i+2]&&s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9')
		{
			for(c=s[i]+1;c<s[i+2];c++)
			{
			    putchar(c);
			}
			i=i+2;
		}
		else{
			i++;
		}
	}
	return 0;
}

