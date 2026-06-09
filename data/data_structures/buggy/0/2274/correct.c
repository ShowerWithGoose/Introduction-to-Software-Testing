#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j=0,k=0,l;
	char s[100],s1[200];
	scanf("%s",s);
	int len = strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]!='-') s1[j++] = s[i];
		else
		{
			if((isupper(s[i-1])&&isupper(s[i+1])&&(s[i-1]<s[i+1]))||(islower(s[i-1])&&islower(s[i+1])&&(s[i-1]<s[i+1]))||isdigit(s[i-1])&& isdigit(s[i+1])&&(s[i-1]<s[i+1]))
			{
				k = s[i+1] - s[i-1];
				for(l=1;l<k;l++)
				{
					s1[j++]=s[i-1]+l;
				}
			}
			else s1[j++]= s[i];
		}
	}
	s1[j]='\0';
	printf("%s",s1);
	return 0;
}


