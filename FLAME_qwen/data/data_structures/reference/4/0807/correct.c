#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct vol{
	char word[58];
	int times;
}a[2003];
int cmp(const void *x,const void *y)
{
	struct vol *a=(struct vol *)x;
	struct vol *b=(struct vol *)y;
return strcmp(a->word,b->word);
}
int main()
{
	FILE *f1=fopen("article.txt","r");
	int i=0,len,j,k=0,num=0;
	char ss[2000],s[2000],c;
	c=fgetc(f1);
	while(c!=EOF)
	{
		ss[i++]=c;	
	c=fgetc(f1);
	}
	len=i;
	for(i=0;i<len;i++)
	{
		if(isalpha(ss[i]))
		{
			k=0;//不是开头初始化就够了！每一次新单词开始都得 
			for(j=i;isalpha(ss[j]);j++)
			{
				a[num].word[k++]=tolower(ss[j]);
				a[num].times=1;
			}
			num++;
			i=j;
			continue;
		}
		else
		continue;
	}
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(strcmp(a[i].word,a[j].word)==0&&a[i].times!=0)
			{
				a[i].times++;
				a[j].times=0;
			}
		}
	}
	qsort(a,num,sizeof(struct vol),cmp);
	for(i=0;i<num;i++)
	{
		if(a[i].times!=0)
		printf("%s %d\n",a[i].word,a[i].times);
	}
 } 

