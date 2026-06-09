#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


struct date
{
	char s[50];
	int n;//t记录出现次数 
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
	struct date b[1000];
	int k=0,n_i;
	FILE *fp;
	fp = fopen("article.txt","r");
	while(getword(fp,b[k++].s)!=EOF);
	n_i = k-1;
	qsort(b,n_i,sizeof(struct date),cmp);
	for(k=0;k<n_i;k++)
	{
		b[k].n = 1;
	}
	
	for(k=0;k<n_i;k++)
	{
		if(strcmp(b[k].s,b[k+1].s)==0&&k<n_i-1)
		{
			b[k+1].n += b[k].n;
			b[k].n = -1;
		}
	}
	for(k=0;k<n_i;k++)
	{
		if(b[k].n!=-1)
		{
			printf("%s %d\n",b[k].s,b[k].n);
		}
	}
	return 0;
}

