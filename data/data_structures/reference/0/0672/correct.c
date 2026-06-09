#include<stdio.h>
#include<string.h>
char c[100100];
int i,j;
int main()
{
	scanf("%s",c);
	int len=strlen(c);
	for(i=0;i<len;i++)
	{
		if(c[i]!='-')printf("%c",c[i]);
		else
		{
			if(i==0)printf("-");
			else if(((c[i-1]>='0'&&c[i-1]<='9'&&c[i+1]>='0'&&c[i+1]<='9')||(c[i-1]>='a'&&c[i-1]<='z'&&c[i+1]>='a'&&c[i+1]<='z')||(c[i-1]>='A'&&c[i-1]<='Z'&&c[i+1]>='A'&&c[i+1]<='Z'))&&c[i-1]<c[i+1])
			{
				for(j=c[i-1]+1;j<c[i+1];j++)
				{
					printf("%c",j);
				}
			}
			else printf("-");
		}
	}
}

