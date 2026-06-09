#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	char s[1005];
	int i,k,m,n,p;
	scanf("%s",s);
	m=strlen(s);
	for(i=0;i<=(m-1);i++)
	{
			if((s[i-1]>=48)&&(s[i-1]<=57)&&(s[i]==45)&&(s[i+1]>=48)&&(s[i+1]<=57)&&(s[i-1]<s[i+1]))
			{
				s[i]=s[i+1];
				for(k=1;k<=(s[i+1]-s[i-1]-1);k++)
				{
					printf("%c",s[i-1]+k);
				}
			}
			else if((s[i-1]>='A')&&(s[i-1]<='Z')&&(s[i]==45)&&(s[i+1]>='A')&&(s[i+1]<='Z')&&(s[i-1]<s[i+1]))
			{	
				s[i]=s[i+1];		
				for(p=1;p<=(s[i+1]-s[i-1]-1);p++)
				{
					printf("%c",s[i-1]+p);
				}
			}
			else if((s[i-1]>='a')&&(s[i-1]<='z')&&(s[i]==45)&&(s[i+1]>='a')&&(s[i+1]<='z')&&(s[i-1]<s[i+1]))
			{
				s[i]=s[i+1];
				for(n=1;n<=(s[i+1]-s[i-1]-1);n++)
				{
					printf("%c",s[i-1]+n);
				}
			}
		else
		{
			printf("%c",s[i]);
		}
	}
	
	
	
	 
	return 0;
}

