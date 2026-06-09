#include<stdio.h>
#include<string.h>
char s[10000];
char S[10000];
int main()
{
	
	scanf("%s",s);
	int i,j=0;
	int l=strlen(s);
	for(i=0;i<l;i++)
	{
	
			if(s[i]=='-'&&s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]||s[i]=='-'&&s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]||s[i]=='-'&&s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])
			{
				S[j]=s[i-1]+1;
				for(;S[j]<s[i+1];)
				{
					j++;
					S[j]=S[j-1]+1;
				}
			}
			
			else
			{
				S[j]=s[i];
				j++;
			}
	}
	printf("%s",S);
}



