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
		for(int j=i;j<=n;j++)//j可多取点，以让最后一个单词和空单词比较来结束 
		{
			if(strcmp(wordlist[i].word,wordlist[j].word)==0)
			{
				wordlist[i].cnt++;
				wordlist[j].cnt--;//这样的操作会使第一次cnt自增失败 
			}
			else
			i=j;//不用i=j+1;防止j+1越界直接跳出循环（其实没啥，定义域弄大点就行） 
		}
	}
	for(int i=0;i<n;i++)
	{
		if(wordlist[i].cnt>=0)//重复的都是-1,空单词不在定义域 
		printf("%s %d\n",wordlist[i].word,wordlist[i].cnt+1);//所以这里要加1 
	}
	fclose(fp);
	return 0;
}

