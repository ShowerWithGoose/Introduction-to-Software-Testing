#include<stdio.h>
#include<string.h>
int judge(char n,char m)
{
	if(n>='a'&&n<='z'&&m>='a'&&n<='z')
	return 1;
	else if(n>='A'&&n<='Z'&&m>='A'&&m<='Z')
	return 1;
	else if(n>='0'&&n<='9'&&m>='0'&&m<='9')
	return 1;
	else return 0;
}
int main()
{
	char s[1000];
	gets(s);
	char a[100000];
	int i;
	char j;
	int k=0;
	int length=strlen(s);
	for(i=0;i<length;)
	{
		if(judge(s[i],s[i+2])==1&&s[i+1]=='-')
		{
			for(j=s[i];j<s[i+2];j++)
			{
				a[k]=j;
				k++;
			}
			i=i+2;
		}
		else
		{
			a[k]=s[i];
			k++;
			i++;
		}
	}
	puts(a);
	return 0;
} 

