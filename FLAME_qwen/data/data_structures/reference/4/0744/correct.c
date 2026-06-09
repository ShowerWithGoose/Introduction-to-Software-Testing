#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//题目描述：统计一个文件中每个单词的出现的个数 并按字典序进行输出
//解题思路：首先我们得设计一个函数来读取文本中每个单词的个数
//然后我们用链表来对这些单词经行储存
// 最后开始进行合并  将相同的单词统计在一起  经行排序  输出 

struct word_list{
	int num;
	char word[50];
	struct word_list* link;
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
struct word_list* insert(struct word_list * head_elem,char *s)//将单词s插入到以head_elem为头指针的单词表中 
{
	struct word_list* now,* next;
	struct word_list* p=(struct word_list*)malloc(sizeof(struct word_list));
	now=head_elem;
	next=head_elem;
	strcpy(p->word,s);
	p->link=NULL;
	p->num=1;
	if(head_elem==NULL)return p;
	if(strcmp(head_elem->word,p->word)>0)//这里是当s比第一个单词还要小的时候s应该插入到head_elem的前面 
	{
		p->link=head_elem;
		head_elem=p;
		return head_elem;
	}
	
	for(;next!=NULL;now=next,next=next->link)
	{   
		if(strcmp(next->word,p->word)==0)
		{
			next->num++;
			return head_elem;		
		}

		else 
		if(strcmp(next->word,p->word)>0)
		{
		    p->link=now->link;
			now->link=p;
			p->num=1;
			return head_elem;
		}
	}
		if(next==NULL)//假如s比单词表中的任何一个单词都要大 那么就要插入到最后 
	{
		
		now->link=p;
		p->link=NULL;
		p->num=1;
		return head_elem;
	}

}

//开始创建链表 
struct word_list *head_elem=NULL;
void create_list()
{
    char *s=(char*)malloc(sizeof(char)*50);
	do{
		s=getword(in,s);
		head_elem=insert(head_elem,s);
	}while(s[0]!='\0');
}

 
void put_list(struct word_list * head_elem)
{
	struct word_list *p=head_elem->link;
	while(p!=NULL)
	{   
		printf("%s %d\n",p->word,p->num);
		p=p->link;
	}
 } 
int main()
{
	in=fopen("article.txt","r"); 
	if(in==NULL)printf("can't open the file");
	create_list();
	put_list(head_elem);
	fclose(in);
	
	return 0;
 } 


