#include<stdio.h>
#include<string.h>
#include<ctype.h>

char temp[20]={};

struct a
{
	char word[20];
	int num;
	int judge;
}note[300];

int main()
{
	char ch;
	int i=0,j=0,k,x=0;
	FILE*in;
	in=freopen("article.txt","r",stdin);
	while((ch=getchar())!=EOF)
	{
		if(isalpha(ch)>0)
		{
			note[i].word[j]=tolower(ch);
			j++;
		}
		else
		{
			if(strlen(note[i].word)==0) {j=0;continue;}
			i++;
			j=0;
		}
	}
	fclose(in);
//  for(j=0;j<i;j++) puts(note[j].word );
	for(j=0;j<i;j++)
	{
		if(note[j].judge>0) continue;
		note[j].num=1;
		for(k=j+1;k<i;k++)
		{
			if(note[k].judge==0&&strcmp(note[k].word,note[j].word)==0)
			{
				note[j].num++;
				note[k].judge++;
			}
		}
	}
//	for(j=0;j<i;j++) if(note[j].judge==0) printf("%s %d\n",note[j].word ,note[j].num );
	strcpy(temp,note[0].word);
	int loc=0;
	for(j=0;j<i;j++)
	{
		if(note[j].judge==0) 
		{
			x++;
			if(strcmp(temp,note[j].word)<0)
			{
				strcpy(temp,note[j].word);
				loc=j;
			}
		}
	}
//	printf("%d",x);
	for(j=0;j<x;j++)
	{
		int min=loc;
		for(k=0;k<i;k++)
		{
			if(strcmp(note[min].word,note[k].word)>0&&note[k].judge==0)
			{
				min=k;
			}
		}
		note[min].judge++;
		printf("%s %d\n",note[min].word ,note[min].num );
	}
	
	
}

