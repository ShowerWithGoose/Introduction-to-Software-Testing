#include<stdio.h>
#include<string.h>
int main()
{
	char a,b,c,s[1005];
	int i,l,j; 
	scanf("%s",s);
	l=strlen(s);
	printf("%c",s[0]);
	for(j=1;j<l-1;j++)
	{
		a=s[j-1];
		b=s[j];
		c=s[j+1];
		if(b=='-')
		{
			if(((c<='z'&&a>='a')||(c<='Z'&&a>='A')||(c<='9'&&a>='0'))&&(c>a))
			{
				for(i=1;a+i<c;i++)
				{
					printf("%c",a+i);
				}
			}
			else
			{
				printf("%c",b);
			}
		}
		else
		{
			printf("%c",b);
		}
	}
	printf("%c",s[j]);
	return 0;
}



