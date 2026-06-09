#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int judge(char a)
{
	if(isupper(a))return 0;
	else if(islower(a))return 1;
	else if(a-'0'>=0&&a-'0'<=9)return 2;
	else return 3;
 } 
int main()
{
	char ch[1000];
	fgets(ch,1000,stdin);//int length=strlen(ch);
	char *c;
	while((c=strchr(ch,'-'))!=NULL)
	{	
		int j;
		for(j=0;j<c-ch-1;j++)
		printf("%c",ch[j]);
		if(judge(*(c-1))==judge(*(c+1))&&*(c-1)!=3)
		{
			for(j=0;*(c-1)+j<*(c+1);j++)
			printf("%c",*(c-1)+j);
		}
		else
		{
			printf("%c%c",*(c-1),*c);
		}
		strcpy(ch,c+1);
	}
	printf("%s",ch);
	return 0;
	
 }
  



