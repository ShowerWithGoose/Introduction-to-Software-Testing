#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 200
#define WORDLEN 20
struct node{
	char word[WORDLEN];
	int cnt;
	struct node *next;
};

struct node *getNode(struct node *first,struct node **last,char *line); //将新读入的一行中的单词存入链表 
void sort(struct node *first);  //按字典序排序

int main()
{
	char curline[MAXLEN]="";
	struct node *first,*last;
	first=(struct node *)malloc(sizeof(struct node));
	first->next=NULL;
	last=first;
	FILE *in;
	in=fopen("article.txt","r");
	
	while(fgets(curline,MAXLEN,in)!=NULL)
		first=getNode(first,&last,curline);
	
	sort(first);
	
	for(last=first->next;last!=NULL;last=last->next)
	{
		printf("%s %d\n",last->word,last->cnt);
		free(first);
		first=last;
	}
	free(first);
	
	fclose(in);
	return 0;
}

struct node *getNode(struct node *first,struct node **last,char *line)
{
	struct node *scan;
	char *c,Word[WORDLEN]="";
	int i;
	
	for(c=line;isalpha(*c)==0&&*c!='\n'&&*c!='\0';c++); //跳过非字母的字符
	if(*c=='\n'||*c=='\0') return first; 
	for(i=0;isalpha(*c)!=0;i++,c++) 
		Word[i]=(islower(*c)==0)?*c-'A'+'a':*c;	
	Word[i]='\0';
	
	for(scan=first->next;scan!=NULL;scan=scan->next)
	{
		if(strcmp(scan->word,Word)==0)
		{
			scan->cnt++;
			return getNode(first,last,c);
		}	
	}
	
		(*last)->next=(struct node *)malloc(sizeof(struct node));
		(*last)=(*last)->next;
		(*last)->cnt=1;
		strcpy((*last)->word,Word);
		(*last)->next=NULL;
		return getNode(first,last,c);
}

void sort(struct node *first)
{
	struct node *t,*q,*p;
	int n=0,i,j;
	
	for(t=first->next;t!=NULL;t=t->next)
		n++;
		
	for(i=1;i<n;i++)
	{
		j=n-i;
		t=first;
		q=t->next;
		p=q->next;
		while(j--)
		{
			if(strcmp(q->word,p->word)>0)
			{
				t->next=p;
				q->next=p->next;
				p->next=q;
			}
			t=t->next;
			q=t->next;
			p=q->next;
		}
	}
	return;
}

