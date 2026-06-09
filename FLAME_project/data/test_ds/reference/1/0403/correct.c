#include<stdio.h>
#include<string.h>
int main()
{
	char s[10005],p;
	int len;
	gets(s);
	len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
		{
			printf("%c",s[i]);
		}
		else if(s[i]=='-')
		{
			if(i==0||i==len-1)
			  printf("%c",s[i]);
			else if((s[i-1]>='0'&&s[i-1]<='9')&&(s[i+1]>='0'&&s[i+1]<='9'))
			{
				for(p=s[i-1]+1;p<s[i+1];p++)
				   printf("%c",p);
			}
			else if((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z'))
		    {
				for(p=s[i-1]+1;p<s[i+1];p++)
				   printf("%c",p);
			}
			else if((s[i-1]>='A'&&s[i-1]<='Z')&&(s[i+1]>='A'&&s[i+1]<='Z'))
			{
				for(p=s[i-1]+1;p<s[i+1];p++)
				   printf("%c",p);
			}
			else 
			   printf("-");
			
		}
		else
		    printf("%c",s[i]);
		    
	}
	return 0;
} 



