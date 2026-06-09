#include <stdio.h>
#include <string.h>
#include <ctype.h> 
int main()
{
	char s[60];
	char a[]={"abcdefghijklmnopqrstuvwxyz"};
	char b[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char c[]={"0123456789"};
	int i,j,k;
	scanf("%s",&s);	
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!='-')
			printf("%c",s[i]);
		else if(s[i]=='-')
		{
			k=1;
			if(islower(s[i-1])&&islower(s[i+1])&&s[i-1]<s[i+1])
				for(j=0;j<26;j++)
				{
					if(a[j]>s[i-1]&&a[j]<s[i+1])
						printf("%c",a[j]);
					else if(a[j]>=s[i+1])
						break;
				}
			else if(isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<s[i+1])
				for(j=0;j<26;j++)
				{
					if(b[j]>s[i-1]&&b[j]<s[i+1])
						printf("%c",b[j]);
					else if(b[j]>=s[i+1])
						break;
				}
			else if(s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])
				for(j=0;j<10;j++)
				{
					if(c[j]>s[i-1]&&c[j]<s[i+1])
						printf("%c",c[j]);
					else if(c[j]>=s[i+1])
						break;
				}
			else
				printf("-");
		}
	}
	return 0;
}

