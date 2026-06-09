#include <stdio.h>
int main()
{
	char s[10000]={'\0'};
	gets(s);
	int length=strlen(s);
	int i,j,k=1;
	for(i=0;i<length;i++)
	{
		if(s[i]!='-')
		printf("%c",s[i]);
		else
		{
			if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>=s[i-1]&&s[i+1]<='9'||s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>=s[i-1]&&s[i+1]<='z'||s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>=s[i-1]&&s[i+1]<='Z')
			{
		    	for(j=s[i+1]-s[i-1];k<j;k++)
				printf("%c",s[i-1]+k);
				k=1;
			}
			else
			printf("-");
		}
	}
	return 0;
}

