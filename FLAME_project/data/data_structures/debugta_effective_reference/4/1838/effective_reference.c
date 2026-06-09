#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Compare (const void *,const void *);
typedef struct {
	char word[30];
	int times;
}count,*pcount;
count words[305];
int judge( char c);               //判断是不是字母 
int library(char *tmp);           //存新单词   或  旧单词++ 
void output( int );               //输出 
int main()
{
	FILE *fp = fopen("article.txt","r");
	char ch,tmp[30];
	int index = 0,flag = 0,num;
	while(fscanf(fp,"%c",&ch)!=EOF)
	{
		if(judge(ch))           //判断是否是字母 
		{
			tmp[index++] = tolower(ch);
			flag = 1;
		}
		else if(!judge(ch))
		{
			if(flag==1)           //是单词 
			{
				num = library(tmp);
				memset(tmp,0,sizeof(tmp));
				flag = 0;
				index = 0;
			}
			else if(flag==0)      //不是单词 
			{
				continue;
			} 
		}
	}
	qsort(words,num,sizeof(count),Compare);
	output(num);
	fclose (fp);
	return 0;
} 
int judge( char c )
{
	if(c>='a'&&c<='z') return 1;
	else if(c>='A'&&c<='Z') return 1;
	else return 0;
}
int library(char *tmp)
{
	static int j;
	int i,sign = 0;
	for(i=0;i<j;i++)
	{
		if(strcmp(words[i].word,tmp)==0)        //判断相等
		{
			words[i].times++;
			sign = 1;                  //旧单词   做标记 
			break;
		} 
	}
	if(sign==0)                    //新单词 
	{
		strcat(words[j].word,tmp);
		words[j].times = 1;
		j++;
	}
	return j;         //从0开始  正好输出数组下标+1 
}
int Compare (const void *c,const void *d)
{
	pcount a = (pcount)c;
	pcount b = (pcount)d;
	return strcmp(a->word,b->word);
}
void output(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",words[i].word,words[i].times);
	}
}

