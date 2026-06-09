#include <stdio.h>
#include<string.h>
int main()  
{
	int k=0;
	char s[100],t[1000];
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='-'&&s[i+1]>s[i-1]&&((s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0')||(s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a')||(s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A')))
		{
			for(int j=1;j<s[i+1]-s[i-1];j++)
			{
				t[k]=s[i-1]+j;
				k++;
			}
		}
		else
		{
			t[k]=s[i];
			k++;
		}
	}
	printf("%s",t);
}

