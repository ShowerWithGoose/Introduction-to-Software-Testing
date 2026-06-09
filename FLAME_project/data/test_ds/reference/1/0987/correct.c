#include<stdio.h>
#include<string.h>
int isNum(char x)
{
	if(x>='0'&&x<='9')
	return 1;
	else
	return 0;
}
int isMin(char x)
{
	if(x>='a'&&x<='z')
	return 1;
	else
	return 0;
}
int isMax(char x)
{
	if(x>='A'&&x<='Z')
	return 1;
	else
	return 0;
}
char s[1000];
int main()
{
	gets(s);
	for(int i=0;i<=strlen(s);i++)
	{
		if(i>=1)
		{
			if(s[i-1]=='-')
			{	
				if(isMax(s[i])&&isMax(s[i-2])&&s[i-2]<s[i])
				{
					for(char j=s[i-2]+1;j<=s[i];j++)
					{
						printf("%c",j);
					}
				}
				else if(isMin(s[i])&&isMin(s[i-2])&&s[i-2]<s[i])
				{
					for(char j=s[i-2]+1;j<=s[i];j++)
					{
						printf("%c",j);
					}
				}else if(isNum(s[i])&&isNum(s[i-2])&&s[i-2]<s[i])
				{
					for(char j=s[i-2]+1;j<=s[i];j++)
					{
						printf("%c",j);
					}
				}else{
					printf("-%c",s[i]);
				}
			}
			else if	(s[i]=='-'&& i>0);
			else	printf("%c",s[i]);
		}
		else	printf("%c",s[i]);
	}
	return 0;
 } 

