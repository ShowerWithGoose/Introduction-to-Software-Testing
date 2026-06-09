#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node{
    char word[15];
    int time;
};
struct node item[100000];
int amount;
int m,x;
void insert(char word[]);
int main()
{
	FILE *in;
	char s[1024];
	int i;
	char tempword[15];
	in=fopen("article.txt","r");
	while(fgets(s,1024,in)!=NULL)
	{
		for(i=0;s[i]!='\0';i++)
		{
			if((s[i]>='a'&&s[i]<='z')||s[i]=='\'')
			{
				tempword[x]=s[i];
				x++;
			}
			else if(s[i]>='A'&&s[i]<='Z')
			{
				tempword[x]=tolower(s[i]);
				x++;
			}
			else if(/*s[i]==' '||s[i]=='.'||s[i]==';'||s[i]==','||s[i]==':'||s[i]=='?'*/((s[i-1]>='a'&&s[i]<='z')||s[i-1]=='\'')||(s[i-1]>='A'&&s[i]<='Z'))
			{
				tempword[x]='\0';
				insert(tempword);
				x=0;
			}
		}x=0;
	 } 
	for(i=0;i<amount;i++)
	{
		printf("%s %d\n",item[i].word,item[i].time);
	}
	return 0;
}
void insert(char word[])
{
	int i,j;
	if(amount==0)
	{
		amount++;
		strcpy(item[amount-1].word,word);
		item[amount-1].time=1;
		return;
	}
	for(i=0;i<amount;i++)
	{
		if(strcmp(item[i].word,word)==0)
		{
			item[i].time++;
			return;
		}
		else if(strcmp(item[i].word,word)>0)
		{
			for(j=amount-1;j>=i;j--)
			{
				item[j+1]=item[j];
			 }
			amount++;
			item[i].time=1;
			strcpy(item[i].word,word);
			return;
		}
	}
	amount++;
	item[amount-1].time=1;
	strcpy(item[amount-1].word,word);
	return;
}

