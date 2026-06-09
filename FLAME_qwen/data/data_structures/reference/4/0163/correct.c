#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct word 
{
	char wordname[35];
	int count;
};
struct word words[500];
int compare(const void *p1,const void *p2)
{
	struct word *a=(struct word *)p1;
	struct word *b=(struct word *)p2;
	return strcmp(a->wordname,b->wordname);
}

int main()
{
	FILE *fp=fopen("article.txt","r");
	char a;
	int i=0,j=0,n,m;
	while((a=fgetc(fp))!=EOF)
	{
		if((a>='a'&&a<='z')||(a>='A'&&a<='Z')) words[i].wordname[j++]=a;
		else
		{
			words[i].wordname[j]='\0';
			j=0;
			i++;
		}
	}
	n=i;
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<strlen(words[i].wordname);j++)
		if(words[i].wordname[j]>='A'&&words[i].wordname[j]<='Z') words[i].wordname[j]=words[i].wordname[j]-'A'+'a';
	}
	qsort(words,n,sizeof(words[0]),compare);
	for(i=0;i<=n-1;i++)
	{
		words[i].count =0;
	}
	for(i=1;i<=n-1;i++)
	{
		if(strcmp(words[i].wordname,words[i-1].wordname)==0) 
		{
			words[i-1].count++;
			for(j=i;j<n-1;j++) 
			{
			words[j]=words[j+1];
		    }
		    n--;
			i--;
		}
		else words[i].count++;
	}
	for(i=0;i<=n-1;i++)
	{
		if(words[i].wordname[0]!='\0') printf("%s %d\n",words[i].wordname,words[i].count);
	}
	return 0;
}

