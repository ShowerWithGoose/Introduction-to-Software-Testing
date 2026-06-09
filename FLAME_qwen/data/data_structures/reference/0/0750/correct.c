#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define ll long long
char s[1010],ans[1010];
int main()
{
	scanf("%s",s);
	int j=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]!='-') ans[j++]=s[i];
		else
		{
			if(i>=1&&i+1<strlen(s)&&s[i-1]<s[i+1]&&((s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9')||(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z')))
			{
				int k=s[i+1]-s[i-1];
				while(k--) 
				{
					ans[j]=ans[j-1]+1;
					j++;
				}
				i++;
			}
			else ans[j++]=s[i];
		}
	}
	printf("%s",ans);
	return 0;	
}

