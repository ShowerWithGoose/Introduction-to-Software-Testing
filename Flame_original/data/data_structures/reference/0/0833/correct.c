#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
char s[10000000];

int main() {
scanf("%s",s);
int i,len,j;
len=strlen(s);
for(i=0;i<len;i++)
{
	if(s[i]!='-'||i==0||i==len-1)
	printf("%c",s[i]);
	else
	{
		if((s[i-1]>='a'&&s[i-1]<s[i+1]&&s[i+1]<='z')||(s[i-1]>='A'&&s[i-1]<s[i+1]&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i-1]<s[i+1]&&s[i+1]<='9'))
		{
			for(j=s[i-1]+1;j<s[i+1];j++)
			printf("%c",j);
		}
		else
		printf("%c",s[i]);
	}
}
return 0;
}


