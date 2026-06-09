#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct word{
	char str[200];
};

typedef struct word word;

word words[200];

int cnt[200];

int cmp(const void *p,const void *q);

int main()
{
	FILE *ip;
	ip=fopen("article.txt","r");
	
	char ch;
	ch=fgetc(ip);
	int i=0,j=0;
	while(ch!=EOF)
	{
		if(isalpha(ch))
		{
			ch=tolower(ch);
			words[i].str[j]=ch;
			j++;
		}
		else
		{
			words[i].str[j]='\0';
			j=0;
			i++;
		}
		ch=fgetc(ip);
	}
	
	int len=i;
	qsort(words,len,sizeof(word),cmp);
	
	memset(cnt,0,sizeof(cnt));
	int k=0;
	int flag=0;
	for(i=0;i<len;i++)
	{
		if(words[i].str[0]=='\0')
			continue;
		for(j=i+1;j<len;j++)
		{
			if(strcmp(words[i].str,words[j].str)==0)
			{
				cnt[k]++;
				strcpy(words[j].str,"\0");
				flag=1;
			}
			if(words[j].str[0]=='\0')
			{
				continue;
			}
			else
			{
				if(flag==1)
				i=j-1;
				k++;
				break;
			}
		}
	}
	
	qsort(words,len,sizeof(word),cmp);
	j=0;
	for(i=0;i<len;i++)
	{
		if(words[i].str[0]!='\0')
		{
			printf("%s %d\n",words[i].str,cnt[j]+1);
			j++;
		}
	}
	return 0;
}
int cmp(const void *p,const void *q)
{
	struct word *a = (struct word*)p;
	struct word *b = (struct word*)q;
	return strcmp(a->str,b->str);
}


