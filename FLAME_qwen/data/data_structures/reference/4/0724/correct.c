#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct VocabInfo{ //建立一个存放单词信息的结构体 
	char word[1000]; //结构体成员一：单词本身的这个字符串(用字符数组来存放) 
	int frequency; //结构体成员二：单词出现的次数 
};
typedef struct VocabInfo VI;
VI a[1000];
char ch,str[1000],tmp[1000];
int i=0,j=0,k=0,cnt=0;

int cmp(const void *p1, const void *p2);
void Passage_Input(FILE *fp1);
void Search_Word(FILE *fp1);
void Repeat_Check(FILE *fp1);
void Final_Output(FILE *fp1);

int main(void)
{
	FILE *fp1 = fopen("article.txt","r");
	
	
	Passage_Input(fp1);
	Search_Word(fp1);
	Repeat_Check(fp1);
	Final_Output(fp1);
	
	fclose(fp1);
	return 0;
}

int cmp(const void *p1, const void *p2)
{
	struct VocabInfo *a = (struct VocabInfo*) p1;
	struct VocabInfo *b = (struct VocabInfo*) p2;
	return strcmp(a->word, b->word);
}

void Passage_Input(FILE *fp1)
{
	ch=fgetc(fp1);
	while(ch!=EOF)
	{
		str[i++]=ch;// 等价于str[i]=ch i++ 
		ch=fgetc(fp1);
	}
	for(i=0;i<strlen(str);i++)
	{
		if(isalpha(str[i]))
		{
			str[i]=tolower(str[i]); //要学会使用这些便捷的与字符相关的函数 
		}
	}
} 

void Search_Word(FILE *fp1) //这个函数是整个题目的核心 
{
	for(i=0;i<strlen(str);i++) //外层循环标志的是起点 
	{
		if(isalpha(str[i])) 
		//如果我们目前的首字符是字母的话，
		//那么我们就要进入内层循环，做进一步的判断 
		{
			for(j=i;j<strlen(str);j++)
			{
				if(!isalpha(str[j]))
				{
					break;	
				}	
			}
			for(k=0;k<j-i;k++)
			{
				tmp[k]=str[i+k];	
			}	
			strcpy(a[cnt].word,tmp);
			memset(tmp,0,sizeof(tmp));
			a[cnt].frequency++;
			cnt++;
			i=j; //跳跃式检索 
		}	
	}
	qsort(a,cnt,sizeof(VI),cmp);	
} 

void Repeat_Check(FILE *fp1)
{
	for(i=0;i<cnt;i++)
	{
		if(strcmp(a[i].word,a[i+1].word)==0)
		{
			a[i+1].frequency+=a[i].frequency;
			a[i].frequency=0;
		}
	}
}

void Final_Output(FILE *fp1)
{
	for(i=0;i<cnt;i++)
	{
		if(a[i].frequency!=0)
		{
			printf("%s %d\n",a[i].word,a[i].frequency);
		}	
	}	
} 

