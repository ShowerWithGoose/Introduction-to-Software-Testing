#include <stdio.h>
int main()
{
	char s[10000]={'\0'};
	gets(s);
	int length=strlen(s);
	int i,k,j=1;
	for(i=0;i<length;i++)
	{
		if(s[i]!='-')
		printf("%c",s[i]);
		else
		{
			if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>=s[i-1]&&s[i+1]<='9'||s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>=s[i-1]&&s[i+1]<='z'||s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>=s[i-1]&&s[i+1]<='Z')
			{
		    	for(k=s[i+1]-s[i-1];j<k;j++)
				printf("%c",s[i-1]+j);
				j=1;
			}
			else
			printf("-");
		}
	}
	return 0;
}

