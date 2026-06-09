#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000005];
	gets(s);
	int i,l;
	if(s[0]=='0')
	{
		int cnt=1,i;
		for(i=1;i<strlen(s);i++)
		{
			if(s[i]=='0')
			cnt++;
			else if((s[i]>'0'&&s[i]<='9')&&(s[i+1]=='\0'||s[i+1]=='\n'))
			{
				printf("%ce-%d",s[i],cnt);
				return 0;
			}
			else if((s[i]>'0'&&s[i]<='9')&&(s[i+1]>='0'&&s[i+1]<='9'))
			{
				printf("%c.",s[i]);
				int h;
				for(h=i+1;s[h]>='0'&&s[h]<='9';h++)
				printf("%c",s[h]);
				printf("e-%d",cnt);
				return 0; 
			}
		}		
	} 
	else
	{
		for(i=0;i<strlen(s);i++)
		{
		
			if(s[i]=='.')
				l=i;	
			if(s[i]=='\n')
				s[i]='\0';
		}
		int n;
		for(n=l;n>=2;n--)
			s[n]=s[n-1];
			s[1]='.';
	printf("%s",s);
	printf("e%d",l-1);
	return 0;
	}
	
}

