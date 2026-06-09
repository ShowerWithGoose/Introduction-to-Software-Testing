#include<stdio.h>
#include<string.h>
#define bufsiz 512
void prt(char,char);
int judge(char,char);
int main()
{
	int i,j;
	char str1[bufsiz],str2[bufsiz];
	scanf("%s",str1);
	for(i=0;i<strlen(str1);i++)
	{
		if((str1[i+1]=='-')&&judge(str1[i],str1[i+2])==1)
		{
			prt(str1[i],str1[i+2]);
			i++;
		}
		else printf("%c",str1[i]);		
	}
	return 0;
}
void prt(char a,char b)
{
	int i;
	for(i=0;i<b-a;i++)
		printf("%c",a+i);
}
int judge(char a,char b)
{
	if(a>='0'&&b<='9')
		return 1;
	else if(a>='a'&&b<='z')
		return 1;
	else if(a>='A'&&b<='Z')
		return 1;
	else  
		return 0;
}

