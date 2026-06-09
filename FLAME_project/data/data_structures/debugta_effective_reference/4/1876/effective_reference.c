/*#include <stdio.h>//结构体做法 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h> 
char s[40005][25];
int n[40005];//核心在于删除标点 
int cmp(const void*, const void*);
int main()
{
	FILE *fp1 = fopen("article.txt", "r");
	int i = 0, num = 0, j, k;
	while (~fscanf(fp1,"%s", s[i]))
	{
		i++;
	}
	num = i-1;
	for (i = 0; i <= num; i++)
	{
		int l = strlen(s[i]);
		for (j = 0; j < l; j++)
		{
			if (isalpha(s[i][j]))
			{
				s[i][j] = tolower(s[i][j]);
			}
			else
			{
				for (k = j; k < l; k++)
				{
					s[i][k] = s[i][k+1];
				}
			}
		}
	}
	qsort(s,num+1, sizeof(s[0]), cmp);//在这里SIG 
	for (i = 0; i < num; i++)
	{
		for (j = i+1; j <= num; j++)
		{
			if (!strcmp(s[i], s[j]))
			{
				memset(s[j], '\0', sizeof(s[j]));
				n[i]++;
			}
		}
	}
	for (i = 0; i <= num; i++)
	{
		if (s[i][0])
		printf("%s %d\n", s[i], n[i]+1);
	}
	fclose(fp1);
	return 0;
} 
int cmp(const void* p1, const void* p2)
{
	char**a = (char**)p1;
	char**b = (char**)p2;
	return strcmp(*a, *b);
}*/
/*#include <stdio.h>//结构体做法 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h> 
struct dic{
	char name[25];
	int cnt;
}word[40005];
char empty[25];//输入情况考虑齐全 并不一定以空白字符分割单词 
int cmp(const void*, const void*);
int main()
{
	FILE *fp1 = fopen("article.txt", "r");
	int i = 0, num = 0, j, k;
	while (~fscanf(fp1,"%s", word[i].name))
	{
		i++;
	}
	num = i;
	for (i = 0; i < num; i++)
	{
		int l = strlen(word[i].name);
		for (j = 0; j < l; j++)
		{
			if (isalpha(word[i].name[j]))
			{
				word[i].name[j] = tolower(word[i].name[j]);
			}
			else
			{
				word[i].name[j] = '\0';
			}
		}
		for (j = 0; j < l; j++)
		{
			if (word[i].name[j] == '\0')//写成赋值号le 
			{
				for (k = j; k < 25; k++)
				{
					word[i].name[k] = word[i].name[k+1];
				}
				l--;
			}
		}
		while (!word[i].name[0])
		{
			for (k = 0; k < 25; k++)
			{
				word[i].name[k] = word[i].name[k+1];
			}
		}
	}
	qsort(word,num, sizeof(word[0]), cmp);
	for (i = 0; i < num-1; i++)
	{
		for (j = i+1; j < num; j++)
		{
			if (!strcmp(word[i].name, word[j].name))
			{
				memset(word[j].name,'\0',sizeof(word[j].name));
				word[i].cnt++;
			}
		}
	}
	for (i = 0; i < num; i++)
	{
		if (strcmp(empty,word[i].name))
		printf("%s %d\n", word[i].name, word[i].cnt+1);
	}
	fclose(fp1);//do不对劲 
	return 0;
}
int cmp(const void* p1, const void* p2)
{
	struct dic* a = (struct dic*)p1;
	struct dic* b = (struct dic*)p2;
	return strcmp(a->name, b->name);
}*/
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct vocabCount{ //词频结构体 
	char word[200];//单词 
	int times;     //词频 
};
typedef struct vocabCount V;
char s[200],tmp[200],ch;
int i,j,k,cnt=0;
V a[1000];
int cmp(const void*p1,const void*p2);
void GetArticle(FILE *fp1); //读取文章 
void GetWord(FILE *fp1);    //读取单词 
void DelRepeated(FILE *fp1);//去重 
void Output(FILE *fp1);     //输出 
int main()
{	
	FILE *fp1 = fopen("article.txt","r");
	GetArticle(fp1);	//读取文章 
	GetWord(fp1);		//读取单词 
	DelRepeated(fp1);	//去重 
	Output(fp1);		//输出 
	return 0;
}
int cmp(const void*p1,const void*p2) //根据字典序排序 
{
	struct vocabCount *a=(struct vocabCount*)p1;
	struct vocabCount *b=(struct vocabCount*)p2;
	return strcmp(a->word,b->word);
}
void GetArticle(FILE *fp1)
{
	ch=fgetc(fp1);
	i=0;
	while(ch!=EOF)
	{
		s[i]=ch;
		i++;
		ch=fgetc(fp1);
	}
	for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i])) s[i]=tolower(s[i]); //全部转化为小写 
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
		else	continue;
	}
	qsort(a,cnt,sizeof(V),cmp); //排序 
	for(i=0;i<cnt;i++) a[i].times=1;
}
void DelRepeated(FILE *fp1)
{
	for(i=0;i<cnt;i++)
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
}*/
#include <stdio.h>//结构体做法 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h> 
struct dic{
	char name[25];
	int cnt;
}a[40005];
char empty[25];//输入情况考虑齐全 并不一定以空白字符分割单词 
char s[200], ss[200], c;
int cnt, i, j, k;
int cmp(const void*, const void*);
int main()
{
	FILE *fp1 = fopen("article.txt", "r");
	while (~(c = fgetc(fp1)))
	{
		//if (isalpha(c))
		//{
			s[i] = c;
			i++;
		//}不能只读字母 
	}
	int len = strlen(s); 
	for(i = 0;i < len;i++)
	{
		if(isalpha(s[i])) s[i]=tolower(s[i]); //全部转化为小写 
	}
	for(i=0;i<len;i++)
	{
		if(isalpha(s[i])) //如果是字母，确定为单词开头 
		{
			for(j=i;j<len;j++)
			{
				if(!isalpha(s[j])) //遇到非字母的元素 
				{
					break;
				}
			}
			memset(ss,0,sizeof(ss));
			for(k=0;k<j-i;k++)
			{
				ss[k]=s[i+k];   //存储单词 
			}
			strcpy(a[cnt].name,ss); //拷贝单词 
			cnt++;
			i=j;
		}
		else	continue;
	}
	qsort(a,cnt,sizeof(struct dic),cmp); //排序 
	for(i=0;i<cnt;i++) a[i].cnt=1;
	
	for(i=0;i<cnt;i++)
	{
		if(strcmp(a[i].name,a[i+1].name)==0) //重复 
		{
			a[i+1].cnt+=a[i].cnt;//频率加一 
			a[i].cnt=0;
		}
	}
	qsort(a,cnt,sizeof(struct dic),cmp);
	
	for(i=0;i<cnt;i++)
	{
		if(a[i].cnt==0)
		{
			continue;
		}
		else
		{
			printf("%s %d\n",a[i].name,a[i].cnt);
		}
	}
	 
	fclose(fp1);//do不对劲 
	return 0;
}
int cmp(const void* p1, const void* p2)
{
	struct dic* a = (struct dic*)p1;
	struct dic* b = (struct dic*)p2;
	return strcmp(a->name, b->name);
}


