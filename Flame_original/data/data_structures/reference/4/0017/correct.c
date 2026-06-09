#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct vo{ //词频结构体 
	char word[200];//单词 
	int times;     //词频 
}V;
char s[200],tmp[200],c;
int i,j,k,cnt=0;
V a[1000];
int cmp(const void*x,const void*y); //根据字典序排序 
void GetArticle(FILE *fp1)
{
	c=fgetc(fp1);
	i=0;
	while(c!=EOF)
	{
		s[i]=c;
		i++;
		c=fgetc(fp1);
	}
	for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i])) 
		s[i]=tolower(s[i]); //全部转化为小写 
	}
}
void GetWord(FILE *fp1)
{
	for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i])) //如果是字母，确定为单词开头 
		{
			for(j=i;j<strlen(s);j++)
			{
				if(!isalpha(s[j])) //遇到非字母的元素 
				{
					break;
				}
			}
			memset(tmp,0,sizeof(tmp));
			for(k=0;k<j-i;k++)
			{
				tmp[k]=s[i+k];   //存储单词 
			}
			strcpy(a[cnt].word,tmp); //拷贝单词 
			cnt++;
			i=j;
		}
		else	
		continue;
	}
	qsort(a,cnt,sizeof(V),cmp); //排序 
	for(i = 0;i<cnt;i++) 
	{
		a[i].times=1;
	}
}
void del(FILE *fp1)
{
	for(i = 0;i<cnt;i++)
	{
		if(strcmp(a[i].word,a[i+1].word)==0) //重复 
		{
			a[i+1].times+=a[i].times;//频率加一 
			a[i].times=0;
		}
	}
	qsort(a,cnt,sizeof(V),cmp);
}
void Output(FILE *fp1)
{
	for(i = 0;i<cnt;i++)
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
}
int main()
{	
	FILE *fp1 = fopen("article.txt","r");
	GetArticle(fp1);	//读取文章 
	GetWord(fp1);		//读取单词 
	del(fp1);	//去重 
	Output(fp1);		//输出 
	return 0;
}
int cmp(const void*x,const void*y) //根据字典序排序 
{
	struct vo *a=(struct vo*)x;
	struct vo *b=(struct vo*)y;
	return strcmp(a->word,b->word);
}


