#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct list{
	int cnt;
	char word[100];
}list, *listptr;
list wordlist[100000];
int cmp(const void *p1,const void *p2)
{
	listptr p=(listptr)p1;
	listptr q=(listptr)p2;
	return strcmp(p->word,q->word);
}
int main()
{
	FILE *fp;
	fp=fopen("article.txt","r");
	char ch;
	int n=0,flag=-1;
	while((ch=fgetc(fp))!=EOF)
	{
		if((ch<='z'&&ch>='a')||(ch<='Z'&&ch>='A'))
		{
			flag++;
			wordlist[n].word[flag]=tolower(ch);
		}
		else if(flag>=0)
		{
			n++;
			flag=-1;
		}
	}
	//文件单词读取完毕
	//下面进行排序
	qsort(wordlist,n,sizeof(list),cmp) ;
	//排序完毕
	for(int i=0;i<n;i++) 
	{
		for(int j=i;j<=n;j++)
		{
			if(strcmp(wordlist[i].word,wordlist[j].word)==0)
			{
				wordlist[i].cnt++;
				if(i!=j)
				wordlist[j].cnt--;
			}
			else
			i=j+1;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(wordlist[i].cnt>0)
		printf("%s %d\n",wordlist[i].word,wordlist[i].cnt);
	}
	fclose(fp);
	return 0;
}

