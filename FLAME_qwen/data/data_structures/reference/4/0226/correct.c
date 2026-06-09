#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h> 
#include<ctype.h>
typedef struct vocabCount{
	char word[200];
	int times; 
}V, *Pv;


int cmp(const void*p1,const void*p2);

int main()
{	char s[200],tmp[200],ch;
	int i,j,k,cnt=0;
	V a[1000];
	
	FILE *fp1 = fopen("article.txt","r");
	//输入文章 
	ch=fgetc(fp1);
	i=0;
	while(ch!=EOF)
	{
		s[i]=ch;
		if(isalpha(s[i])) s[i]=tolower(s[i]);
		i++;
		ch=fgetc(fp1);
	}
	//读取单词 
	for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i]))
		{
			for(j=i;j<strlen(s);j++)
			{
				if(!isalpha(s[j]))
				{
					break;
				}
			}
			memset(tmp,0,sizeof(tmp));
			for(k=0;k<j-i;k++)
			{
				tmp[k]=s[i+k];
			}
			strcpy(a[cnt].word,tmp);
			cnt++;
			i=j;
		}
	}
	qsort(a,cnt,sizeof(V),cmp);
	for(i=0;i<cnt;i++) a[i].times=1;
	//去重
	for(i=0;i<cnt;i++)
	{
		if(strcmp(a[i].word,a[i+1].word)==0)
		{
			a[i+1].times+=a[i].times;
			a[i].times=0;
		}
	}
	qsort(a,cnt,sizeof(V),cmp);
	//输出 
	for(i=0;i<cnt;i++)
	{
		if(a[i].times==0)
		{
			continue;
		}
		else
		{
			printf("%s %d\n",a[i].word,a[i].times);
		}
	}
	return 0;
}

int cmp(const void*p1,const void*p2)
{
	Pv a=(Pv)p1;
	Pv b=(Pv)p2;
	return strcmp(a->word,b->word);
}
	




