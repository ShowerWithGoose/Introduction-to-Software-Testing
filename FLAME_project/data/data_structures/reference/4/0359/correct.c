#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Word{
	char s[51];
	int num;
};
typedef struct Word Word;
Word word[1000];
char str[10001];
int cmp(const void *a,const void *b)
{
	Word *c=(Word*)a;
	Word *d=(Word*)b;
	return strcmp(c->s,d->s);
}
int main()
{
	FILE* fp=fopen("article.txt","r");
	char ch;
	int cnt=0;
	while((ch=fgetc(fp))!=EOF)
	{
		str[cnt++]=ch;
	}
	cnt=0;
	int k=0;
	for(int i=0;i<=strlen(str);i++)
	{
		if(!isalpha(str[i]))
		{
			cnt++;
			k=0;
		}
		else
		{
			word[cnt].s[k++]=tolower(str[i]);
		}
	}
	qsort(word,cnt,sizeof(word[0]),cmp);
	for(int i=0;i<cnt;i++)
	{
		if(strlen(word[i].s)!=0)word[i].num=1;
	}
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<cnt;j++)
		{
			if(!strcmp(word[j].s,word[j+1].s))
			{
				word[j].num+=word[j+1].num;
				word[j+1].num=0;
			}
		}
	}
	for(int i=0;i<cnt;i++)
	{
		if(word[i].num!=0)
		{
			printf("%s %d\n",word[i].s,word[i].num);
		}
	}
	return 0;
}

