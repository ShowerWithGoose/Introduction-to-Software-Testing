#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int len, note=0;
char buf[100];
typedef struct _sta
{
	char word[15];
	int count;
} sta, *psta;

sta  inf[105];
int cmp(const void*p1, const void*p2)
{
	psta a = (psta)p1;
	psta b = (psta)p2;
	return strcmp(a->word,b->word);
}
int main()
{
	
	int x, i=1, j, flag=0;
	char ch;
	FILE* fp = fopen("article.txt", "r");
	if(fp==NULL)
	{
		perror("cannot open the file!\n");
		return 0;
	}
	
	
	while((ch=fgetc(fp))!=EOF)
	{
		if(isalpha(ch)==0)
		continue;
		i=0;
		do
		{
			buf[i++]=tolower(ch);
			
		}while(isalpha(ch=fgetc(fp)));
		buf[i]='\0';
		flag=0;
		for(i=0;i<len;i++)
		{
			if(strcmp(buf,inf[i].word)==0)
			{
				inf[i].count++;
				flag=1;
				break;
			}
		}
		if(flag==0) 
		{
			strcpy(inf[len].word, buf);
			inf[len].count++;
			len++;
		}
	}
	qsort(inf, len, sizeof(sta),cmp);
	for(i=0;i<len;i++)
	{
		printf("%s %d\n", inf[i].word, inf[i].count);
	}
	
}

