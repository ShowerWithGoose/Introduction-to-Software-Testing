#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char s[105],c;
	gets(s);
	int a=strlen(s),b,d;
	if(s[0]=='0')
	{
		for(int i=0;i<a;i++)
		{
			if(s[i]>'0')
			{
			b=i;
			c=s[i];
			break;
			}	
		}
		if(s[b+1]>'0')
		printf("%c.",s[b]);
		else printf("%c",s[b]);
		for(int j=b+1;j<a;j++)
		printf("%c",s[j]);
		printf("e-");
		printf("%d",b-1);
	}
	else 
	{
		for(int k=0;k<a;k++)
		{
			if(s[k]=='.')
			{
				d=k;
			}
		}
		printf("%c",s[0]);
		printf(".");
		for(int l=1;l<a;l++)
		{
			if(s[l]!='.')
			printf("%c",s[l]);
		}
		printf("e");
		printf("%d",d-1);
	}
	return 0;
}
