#include<stdio.h>
#include<string.h>
char s[1005],c[1005],tem;
int a,i,j,n,sign;
int main()
{
	scanf("%s",s);
	for(i=0,sign=0;i<strlen(s);i++)
	{
		if(s[i+1]=='-')
		{
			if(s[i]-'0'>=0&&s[i]-'0'<=9&&s[i+2]-'0'<=9&&s[i+2]-'0'>=0&&s[i]-'0'<s[i+2]-'0')
			{
				if(sign==0)
				for(j=s[i]-'0';j<=s[i+2]-'0';j++)
				{
					printf("%d",j);
				}
				else
				for(j=s[i]-'0'+1;j<=s[i+2]-'0';j++)
				{
					printf("%d",j);
				}
				if(s[i+3]=='-') 
				{
					i=i+1;
					sign=1;
				}
				else i=i+2;
			}
			else if(s[i]-'a'>=0&&s[i]-'a'<=26&&s[i+2]-'a'<=26&&s[i+2]-'a'>=0&&s[i]-'a'<s[i+2]-'a')
			{
				if(sign==0)
				for(j=s[i]-'a';j<=s[i+2]-'a';j++)
				{
					printf("%c",'a'+j);
				}
				if(sign==1)
				for(j=s[i]-'a'+1;j<=s[i+2]-'a';j++)
				{
					printf("%c",'a'+j);
				}
				if(s[i+3]=='-') 
				{
					i=i+1;
					sign=1;
				}
				else i=i+2;
			}
			else if(s[i]-'A'>=0&&s[i]-'A'<=26&&s[i+2]-'A'<=26&&s[i+2]-'A'>=0&&s[i]-'A'<s[i+2]-'A')
			{
				if(sign==0)
				for(j=s[i]-'A';j<=s[i+2]-'A';j++)
				{
					printf("%c",'A'+j);
				}
				if(sign==1)
				for(j=s[i]-'A'+1;j<=s[i+2]-'A';j++)
				{
					printf("%c",'A'+j);
				}
				if(s[i+3]=='-') 
				{
					i=i+1;
					sign=1;
				}
				else i=i+2;
			}
			else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
	}
	
	return 0;
}



