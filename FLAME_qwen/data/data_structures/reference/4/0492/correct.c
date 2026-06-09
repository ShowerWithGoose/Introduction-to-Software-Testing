#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
struct text{
	char s[10000];
	int num;
}m[10000];
int cmp(const void *a,const void *b)
{
	struct text* c=(struct text*)a;
	struct text* d=(struct text*)b;
	return strcmp(c->s,d->s); 
}
int main()
{
	FILE*fp=fopen("article.txt","r");
	char h[10000],x;
	int i=0,k=0,nn=0;
	while((x=fgetc(fp))!=EOF)
	{
		h[nn]=x;
		nn++;
	}
	nn=0;
	for(i=0;i<strlen(h);i++)
	{
		if(isalpha(h[i])==0)
		{
			nn++;
			k=0;
		}
		else
		{
			m[nn].s[k]=tolower(h[i]);
			k++;
		}
	}
	qsort(m,nn,sizeof(m[0]),cmp);
	for(i=0;i<nn;i++)
	{
		if(strlen(m[i].s))
		{
			m[i].num=1;
		}
	}
	for(i=0;i<nn;i++)
	{
		if(!strcmp(m[i].s,m[i+1].s))
		{
			m[i+1].num+=m[i].num;
			m[i].num=0;
		}
	}
	for(i=0;i<nn;i++)
	{
		if(m[i].num!=0)
		{
			printf("%s %d\n",m[i].s,m[i].num);
		}
	}
	return 0;
}


