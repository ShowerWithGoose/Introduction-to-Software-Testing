#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>	

int main()
{
	char s[1000],ans[1000];
	int i,j,k,n;
	scanf("%s",s);
	n=strlen(s);
	for(i=0,j=0;i<n;i++,j++)
	{
		ans[j]=s[i];
		if(s[i]=='-')
		{
			if((s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'))
			{
				if(s[i+1]>s[i-1])
				{
					for(k=1;ans[j-1]!=s[i+1];j++,k++)
						ans[j]=s[i-1]+k;
					i++;
					j--;
				}
			}
		}
	}
	ans[j]='\0';
	puts(ans);
	return 0;
}



