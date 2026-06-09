#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#define MAX 1024
struct node
{
	char word[105];
	int num;
}count[100005];
int cmp(const void *a,const void *b)
{
	struct node *c= (struct node *) a;
	struct node *d= (struct node *) b;
	return strcmp(c->word,d->word);
}
char line[MAX];
int main()
{
	FILE *fin;
	int num=0,k,judge;
	fin=fopen("article.txt","r");
	while(fgets(line,MAX-1,fin)!=NULL)
	{
		for(int i=0;i<=strlen(line)-1;i++)
		{
			line[i]=tolower(line[i]);
		}
		int i=0;
		while(line[i]<'a'||line[i]>'z')
		{
			i++;
		}
		int len=strlen(line)-1;
		for(k=0;i<=len;i++)
		{
			judge=0;
			if(line[i]>='a'&&line[i]<='z')
			{
				count[num].word[k++]=line[i];	
				count[num].num=1;	
			}
			while(line[i]<'a'||line[i]>'z')
			{
				if(line[i]=='\0')break;
				i++;
				judge=1;
			}
			if(judge==1)
			{
				i--;
				count[num++].word[k]='\0';
				k=0;
			}
			
		}
	}
	qsort(count,num,sizeof(count[0]),cmp);
	for(int i=0;i<=num-1;i++)
	{
		for(int j=i+1;j<=num-1;j++)
		{
			if(count[i].num==-1)continue;
			if(strcmp(count[i].word,count[j].word)==0)
			{
				count[i].num++;
				count[j].num=-1;
			}
		}
	}
	for(int i=0;i<=num-1;i++)
	{
		if(count[i].num>0)
		printf("%s %d\n",count[i].word,count[i].num);
	}
	return 0;
} 

