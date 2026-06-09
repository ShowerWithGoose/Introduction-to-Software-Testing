#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct typeword{
char word[100];
int num;
}words[5000]; 
int cmp(const void *a,const void *b)
{
	return strcmp((*(struct typeword*)a).word,(*(struct typeword*)b).word);
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char c;
	int i=1,j=0;
	while((c=fgetc(in))!=EOF)
	{
		if(c>='A'&&c<='Z')
		{
			words[i].word[j]=c-'A'+'a';
			words[i].num=1;
			j++;
		}
		else if(c>='a'&&c<='z')
		{
			words[i].word[j]=c;
			words[i].num=1;
			j++;
		}
		else 
		{
			i++;
			j=0;
		}
	}
	qsort(words,i,sizeof(struct typeword),cmp);
	int k=1;
	for(j=2;j<=i;j++)
	{
		if(words[k].word[0]<'a'||words[k].word[0]>'z')
		{
			words[k].num=0;
			k++;
			j=k+1;
		}
		if(strcmp(words[k].word,words[j].word)==0)
		{
			words[k].num++;
			words[j].num=0;
		}
		else
		{
			k=j;
		}
	}
	for(j=1;j<=i;j++)
	{
		if(words[j].num!=0)
		{
			printf("%s %d\n",words[j].word,words[j].num);
		}
	}
	return 0;
 } 

