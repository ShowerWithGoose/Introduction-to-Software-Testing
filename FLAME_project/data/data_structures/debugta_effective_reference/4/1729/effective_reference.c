#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//题目描述：统计一个文件中每个单词的出现的个数 并按字典序进行输出
//解题思路：首先我们得设计一个函数来读取文本中每个单词的个数
//然后我们用链表来对这些单词经行储存
// 最后开始进行合并  将相同的单词统计在一起  经行排序  输出 

struct word_list{
	int count;
	char word[50];
	struct word_list* next;
};

FILE*in;

char* getword(FILE* fun_in,char *word)//word一定要事先开辟空间  否者就会报错 
{
	char c;
	int i=0;
	while(((c=tolower(fgetc(fun_in)))<'a'||c>'z')&&c!=EOF);
	word[i++]=c;//把第一个单词给存下来 
	while((c=tolower(fgetc(fun_in)))>='a'&&c<='z'&&c!=EOF)
	{
		word[i]=c;
		++i;
	}
	word[i]='\0';//字符串的结束符一定不可以少 
	if(c==EOF)return "";
	else
	return word;
} 
struct word_list* insert(struct word_list * word_list,char *str)//将单词s插入到以head_elem为头指针的单词表中 
{
	struct word_list* now,* next;
	struct word_list* p=(struct word_list*)malloc(sizeof(struct word_list));
	now=word_list;
	next=word_list;
	strcpy(p->word,str);
	p->next=NULL;
	p->count=1;
	if(word_list==NULL)return p;
	if(strcmp(word_list->word,p->word)>0)//这里是当s比第一个单词还要小的时候s应该插入到head_elem的前面 
	{
		p->next=word_list;
		word_list=p;
		return word_list;
	}
	
	for(;next!=NULL;now=next,next=next->next)
	{   
		if(strcmp(next->word,p->word)==0)
		{
			next->count++;
			return word_list;		
		}

		else 
		if(strcmp(next->word,p->word)>0)
		{
		    p->next=now->next;
			now->next=p;
			p->count=1;
			return word_list;
		}
	}
		if(next==NULL)//假如s比单词表中的任何一个单词都要大 那么就要插入到最后 
	{
		
		now->next=p;
		p->next=NULL;
		p->count=1;
		return word_list;
	}

}

//开始创建链表 
struct word_list *word_list=NULL;
void create_list()
{
    char *str=(char*)malloc(sizeof(char)*50);
	do{
		str=getword(in,str);
		word_list=insert(word_list,str);
	}while(str[0]!='\0');
}

 
void put_list(struct word_list * word_list)
{
	struct word_list *p=word_list->next;
	while(p!=NULL)
	{   
		printf("%s %d\n",p->word,p->count);
		p=p->next;
	}
 } 
int main()
{
	in=fopen("article.txt","r"); 
	if(in==NULL)printf("can't open the file");
	create_list();
	put_list(word_list);
	fclose(in);
	
	return 0;
 } 


