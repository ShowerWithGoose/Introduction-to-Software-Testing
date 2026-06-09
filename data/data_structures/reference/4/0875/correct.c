#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#define MAX 1024
struct node
{
	char word[105];
	int num;
}sta[100005];
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
	int count=0,cnt,flag;
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
		for(cnt=0;i<=len;i++)
		{
			flag=0;
			if(line[i]>='a'&&line[i]<='z')
			{
				sta[count].word[cnt++]=line[i];	
				sta[count].num=1;	
			}
			while(line[i]<'a'||line[i]>'z')
			{
				if(line[i]=='\0')break;
				i++;
				flag=1;
			}
			if(flag==1)
			{
				i--;
				sta[count++].word[cnt]='\0';
				cnt=0;
			}
			
		}
	}
	qsort(sta,count,sizeof(sta[0]),cmp);
	for(int i=0;i<=count-1;i++)
	{
		for(int j=i+1;j<=count-1;j++)
		{
			if(sta[i].num==-1)continue;
			if(strcmp(sta[i].word,sta[j].word)==0)
			{
				sta[i].num++;
				sta[j].num=-1;
			}
		}
	}
	for(int i=0;i<=count-1;i++)
	{
		if(sta[i].num>0)
		printf("%s %d\n",sta[i].word,sta[i].num);
	}
	return 0;
} 

