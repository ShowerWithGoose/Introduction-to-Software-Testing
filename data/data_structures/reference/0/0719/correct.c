#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
char str[10005];
char ans[10005]; 
int main()
{
	gets(str);
	int l=strlen(str);
	int j=0;
	for(int i=0;i<l;i++)
	{
		if(str[i]!='-')
		{
			ans[j++]=str[i];
		}
		else
		{
			if(((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z'))||((str[i-1]>='A'&&str[i-1]<='Z')&&(str[i+1]>='A'&&str[i+1]<='Z'))||((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9')))
			{
				int k=1;
				while(str[i-1]+k<str[i+1])
				{
					ans[j++]=str[i-1]+k;
					k++;
				}
			}
			else ans[j++]=str[i];
		}
	}
	ans[j]='\0';
	puts(ans);
	return 0;
}



