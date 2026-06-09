#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char hc;
	char s[100];
	int j=0,i=0;
	scanf("%s",s);
	int p=strlen(s);
	for(i=0;i<p;i++)
	{
		if(s[i]!='-')
		{
			printf("%c",s[i]);
		}
		else if((s[i+1]<='Z'&&s[i-1]>='A')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='0'&&s[i+1]<='9'))
		{
			hc=s[i+1];
			int k=1;
			for(k=1;k<hc-s[i-1];k++)
			{
				printf("%c",s[i-1]+k);
			}
			
		}
		else
		{
			printf("%c",s[i]);
		}
	}
}

