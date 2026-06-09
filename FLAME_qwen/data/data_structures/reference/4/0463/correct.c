#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct words
{
	char voc[1000];
	int flag;
	int num;
};
typedef struct words a;
a word[1000];
int main()
{
	FILE *article;
	int i=0,j,k=0,m=0;
	article=fopen("article.txt","r");
	char hold,s[10000];
	char temp[100],help[100];
	hold=fgetc(article);
	while(hold!=EOF)
	{
		s[i]=tolower(hold);
		i++;
		hold=fgetc(article);
	}//读入文件 
	for(i=0;s[i]!='\0';i++)
	{
		memset(temp,0,sizeof(temp));
		if(s[i]>='a'&&s[i]<='z'&&(s[i-1]>'z'||s[i-1]<'a'))
		{
			for(j=i;s[j]<='z'&&s[j]>='a';j++)
			{
				temp[j-i]=s[j];
			}
			strcpy(word[k].voc,temp);
			k++;//k是单词总的个数 
			i+=j-i;
		}
	}//记录所有的单词（没查重） 
	for(i=0;i<k;i++)
	{
		for(j=0;j<k-1;j++)
		{
			if(strcmp(word[j].voc,word[j+1].voc)>0)
			{
				strcpy(help,word[j].voc);
				strcpy(word[j].voc,word[j+1].voc);
				strcpy(word[j+1].voc,help);
			}
		}
	}//按首字母排序
	for(i=0;i<k;i++)
	{
		word[i].num=1;
		word[i].flag=0;
	}
	for(i=0;i<k;i++)
	{
		if(strcmp(word[i].voc,word[i+1].voc)==0)
		{
			word[i+1].num+=word[i].num;
			word[i].flag=1;
		}
	}//重复的flag会变成1
	for(i=0;i<k;i++)
	{
		if(word[i].flag==0)
		{
			printf("%s %d\n",word[i].voc,word[i].num);
		}
	} 
	return 0;
}



