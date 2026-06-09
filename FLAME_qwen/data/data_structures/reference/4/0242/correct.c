#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int total;
struct giveword
{
	char s[50];
	int num;
}wordtable[500];
int getword(FILE *fp,char word[])
{
	char c;
	int i=0;
	while(!isalpha(c=fgetc(fp)))
	{
		if(c==EOF)
			return 0;
		else
			continue;
	}
	word[i++]=tolower(c);
	while((c=fgetc(fp))!=EOF)
	{
		if(!isalpha(c))
			break;
		word[i++]=tolower(c);
	}
	word[i]='\0';
	return 1;
}
int searchword(char word[])
{
	int i;
	for(i=0;i<total;i++)
	{
		if(strcmp(word,wordtable[i].s)==0)
			return i;
	}
	return -1;
}
int insertword(char word[])
{
	strcpy(wordtable[total].s,word);
	wordtable[total].num=1;
	total++;
	return total;
}
int cmp(const void *x,const void *y)//比较函数
{
	struct giveword *w1 = (struct giveword*) x;
	struct giveword *w2 = (struct giveword*) y;
	int ans;
	if(w1->num > w1->num)
		ans = -1;
	else if(w1->num < w1->num)
		ans = 1;
	else
	{
		ans = strcmp(w1->s,w2->s);
	}
	return ans;
}
int main()
{
	FILE *fp;
	int check,i;//边排边查
	char w[999999];//单词总表
	fp = fopen("article.txt","r");
    while(getword(fp,w))
	{
		check = searchword(w);
		if(check>=0)
		{
			wordtable[check].num++;
		}
		else
		{
			insertword(w);
		}
	}
	qsort(wordtable,total,sizeof(struct giveword),cmp);
	for(i=0;i<total;i++)
	{
		printf("%s %d\n",wordtable[i].s,wordtable[i].num);
	}
//	puts(w);
//	printf("%d",total);
	return 0;
}

