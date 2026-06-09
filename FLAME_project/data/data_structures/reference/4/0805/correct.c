#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct Node{
	char word[500];
	int times;
};
struct Node m[500];
int compare(const void *p1,const void *p2)
{
	struct Node*a=(struct Node*)p1;
	struct Node*b=(struct Node*)p2;
	return strcmp(a->word,b->word);
} 
int main()
{
	char ch;
	char list[500]={0},tmp[50]={0};//读入文章list tmp存临时单词 
	int i,j,k,n,cnt=0;
	FILE *in,*out;
	in=fopen("article.txt","r");//读入文章,并全部转化为小写 
	ch=fgetc(in);
	i=0;
	while(ch!=EOF)
	{
		if(ch>='A'&&ch<='Z') ch=ch+'a'-'A';
		list[i]=ch;
		i++;
		ch=fgetc(in);
	} 
	//puts(list);
	n=strlen(list);
	for(i=0;i<n;i++)
	{
		if(isalpha(list[i])!=0)
		{
			for(j=i;j<n;j++)
				if(isalpha(list[j])==0) break;
			for(k=0;k<j-i;k++)
				tmp[k]=list[k+i];
			strcpy(m[cnt].word,tmp);
			cnt++;
			i=j;
			memset(tmp,0,sizeof(tmp));
		}
	}
	for(i=0;i<cnt;i++) m[i].times=1;//去重 
	qsort(m,cnt,sizeof(struct Node),compare);
	for(i=0;i<cnt;i++)
	{
		if(strcmp(m[i].word,m[i+1].word)==0)
		{
			m[i+1].times=m[i+1].times+m[i].times;
			m[i].times=0;
		}
	}
	qsort(m,cnt,sizeof(struct Node),compare);
	for(i=0;i<cnt;i++)
	{
		if(m[i].times==0) continue;
		else printf("%s %d\n",m[i].word,m[i].times);
	}
	return 0;
} 

