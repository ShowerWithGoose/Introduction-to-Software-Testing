#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


struct date
{
	char s[50];
	int t;//t记录出现次数 
};

int cmp(const void*_a,const void*_b)
{
	struct date *a=(struct date*)_a;
	struct date *b=(struct date*)_b;
	return strcmp(a->s,b->s);
}

int getword(FILE *fp,char *w)//从文件中读入单词 
{
	char c;
	while(!isalpha(c=fgetc(fp)))
	{
		if(c==EOF) return c;
		else continue;
	}
	do
	{
		*w++ = tolower(c);
	}
	while(isalpha(c=fgetc(fp)));
	*w = '\0'; 
	return 1;
	
}

int main()
{
	struct date word[1000];
	int i=0,n_i;
	FILE *fp;
	fp = fopen("article.txt","r");
	while(getword(fp,word[i++].s)!=EOF);
	n_i = i-1;
	qsort(word,n_i,sizeof(struct date),cmp);
	for(i=0;i<n_i;i++)
	{
		word[i].t = 1;
	}
	
	for(i=0;i<n_i;i++)
	{
		if(strcmp(word[i].s,word[i+1].s)==0&&i<n_i-1)
		{
			word[i+1].t += word[i].t;
			word[i].t = -1;
		}
	}
	for(i=0;i<n_i;i++)
	{
		if(word[i].t!=-1)
		{
			printf("%s %d\n",word[i].s,word[i].t);
		}
	}
	return 0;
}

