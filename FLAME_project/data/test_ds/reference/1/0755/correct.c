#include<stdio.h>
int i;
char s[2000],result[2000];
void expand(int p)
{
	char a,b;
	a=s[p-1];
	b=s[p+1];
	for(;a<b;a++) result[i++]=a;
}
int main()
{
	scanf("%s",s);
	for(int j=0;s[j]!='\0';j++)
	{
		if(s[j+1]!='-')
			result[i++]=s[j];
		else if(s[j]>s[j+2])
			result[i++]=s[j];
		else if(s[j]<='z'&&s[j]>='a'&&s[j+2]<='z'&&s[j+2]>='a')
		{
			expand(j+1);
			j+=1;
		}
		else if(s[j]<='Z'&&s[j]>='A'&&s[j+2]<='Z'&&s[j+2]>='A')
		{
			expand(j+1);
			j+=1;
		}
		else if(s[j]<='9'&&s[j]>='0'&&s[j+2]<='9'&&s[j+2]>='0')
		{
			expand(j+1);
			j+=1;
		}
		else
			result[i++]=s[j];
	}
	result[i]='\0';
	printf("%s",result);
	return 0;
}


