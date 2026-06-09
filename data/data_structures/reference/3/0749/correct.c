#include<stdio.h>
#include<string.h>
char s[105],a[155];
int main()
{
	int j=0,k=0,n,cnt=0,m=-1;
	gets(s);
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='.') 
		{
			m=i;
			break;
		}
	}
		if(m==1&&s[0]=='0')
		{
			j=2;
			while(s[j]=='0')
			j++;
			cnt=j-1;
			
			if(j==n-1)
			printf("%c",s[j]);
			else
			{
				printf("%c.",s[j]);
				for(int t=j+1;t<n;t++)
				printf("%c",s[t]);
			}
			printf("e-%d",cnt);
		}
		else if(m!=-1)
		{
			cnt=m-1;
			printf("%c.",s[0]);
			for(int t=1;t<n;t++)
			{
				if(s[t]=='.') continue;
				printf("%c",s[t]);
			}
			printf("e%d",cnt);
		}
		else
		{
			if(n==0) printf("%ce0",s[0]);
			else
			{
				printf("%c.",s[0]);
				for(int t=1;t<n;t++)
				{
					printf("%c",s[t]);
				}
				printf("e%d",n-1);
			}
		}
	
	return 0;
 } 

