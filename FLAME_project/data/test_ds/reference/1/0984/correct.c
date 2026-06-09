#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	gets(s);
	int i;
	printf("%c",s[0]);
	for(i=1;i<strlen(s);i++)
	{
		if(s[i]=='-')
		{
			if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]-1)
			 {
			 	int j;
			 	for(j=1;j<s[i+1]-s[i-1];j++)
			 	  printf("%c",s[i-1]+j);
			 }
			else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]-1)
			 {
			 	int j;
			 	for(j=1;j<s[i+1]-s[i-1];j++)
			 	  printf("%c",s[i-1]+j);
			 }
			else if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]-1)
			 {
			 	int j;
			 	for(j=1;j<s[i+1]-s[i-1];j++)
			 	  printf("%c",s[i-1]+j);
			 }
			else
			  printf("%c",s[i]);
		}
		else
		  printf("%c",s[i]);
	}
	return 0;
}



