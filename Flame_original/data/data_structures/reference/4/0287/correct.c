#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct _table{
	int num;
	char word[50];
}table[10005];
int cmp(const void *a,const void *b)
{
	struct _table c=*(struct _table *)a;
	struct _table d=*(struct _table *)b;
	return strcmp(c.word,d.word);
}
char cword[50],line[1005],c;
int getword(FILE *fp,char cword[])
{
	int i=0;
	while(!isalpha(c=fgetc(fp)))
		if(c==EOF)	return 0;
		else continue;
	cword[i++]=tolower(c);
	while((c=fgetc(fp))!=EOF)
	{
		if(!isalpha(c))	break;
		cword[i++]=tolower(c);
	}
	cword[i]='\0';
	return 1;
}
int main()
{
	FILE *fp;
	int i,j,k,l,m,n,count=0,pd;
	fp=fopen("article.txt","r");
	while(getword(fp,cword))
	{
		for(i=0;i<count;i++)
		{
			if(strcmp(cword,table[i].word)==0)
			{
				table[i].num++;
				break;
			}
		}
		if(i>=count)
		{
			strcpy(table[count].word,cword);
			table[count].num=1;
			count++;
		}
	}
	qsort(table,count,sizeof(table[0]),cmp);
	for(i=0;i<count;i++)	printf("%s %d\n",table[i].word ,table[i].num );
	return 0;
}

