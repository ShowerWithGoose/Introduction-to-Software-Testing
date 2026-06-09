#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char s1[10000][50];
int cmp(const void*a,const void*b)
{
return strcmp((char*)a,(char*)b);
}
int main()
{
	FILE* in;
	int i=0,len,j=0,tmp=1,k;
	in=fopen("article.txt","r");
	char ch=fgetc(in);
	while(ch!=EOF)
	{
		if(isalpha(ch))
		{
			s1[i][j]=ch;
			j++;
		}
		else if(isspace(ch)||ispunct(ch))
	    {
	    	s1[i][j]=0;
	    	j=0;
	    	i++;
		}
		ch=fgetc(in);
	}
	for(j=0;j<i;j++)
	{
		for(k=0;k<strlen(s1[j]);k++)
		s1[j][k]=tolower(s1[j][k]);
	}
	qsort(s1,i,50,cmp);
	for(j=1;j<i;j++)
	{
		if(strcmp(s1[j],s1[j-1])==0)
		{
			tmp++;
		}
		else
		{
			if(s1[j-1][0]!='\0')
			printf("%s %d\n",s1[j-1],tmp);
			tmp=1;
		}
	}
	printf("%s %d",s1[j-1],tmp);
	fclose(in);
	return 0;
 } 

