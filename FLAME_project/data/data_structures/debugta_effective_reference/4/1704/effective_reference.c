#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	char word[50];
	int count;
	struct node *next;
}NODE;
int getWord(FILE *fp,char *w);
void bubbleSort(NODE *list);
int main()
{
	FILE *in;
	NODE *list=NULL,*p,*q,*r;
	char word[50],*word1;
	in=fopen("article.txt","r");//只读方式打开 
	if(in==NULL)
	{
		printf("Can't open file!!!");
		return -1;
	}
	while(getWord(in,word)!=EOF)
	{
		if(list==NULL)
		{
			q=(NODE *)malloc(sizeof(NODE));
			strcpy(q->word,word);
			q->count++;
			q->next=NULL;
			list=q;
		}
		else
		{
			p=list;
			while(p!=NULL)
			{
				if(strcmp(p->word,word)==0)
				{
					p->count++;
					break;
				}
				p=p->next;
			}//线性查找 
			if(p==NULL)//如果没找到，就再建立一个结点 
			{
				r=list;
				while(r->next!=NULL)r=r->next;
				q=(NODE *)malloc(sizeof(NODE));
				strcpy(q->word,word);
				q->count=1;
				q->next=NULL;
				r->next=q;
			}
		}
	}
	bubbleSort(list);
	p=list;
	while(p!=NULL)
	{
		printf("%s %d\n",p->word,p->count);
		p=p->next;
	}
	fclose(in);
	return 0;
}
int getWord(FILE *fp,char *w)
{
	int c;
	while(!isalpha(c=fgetc(fp)))
	if(c==EOF)return c;
	else continue;
	do
	{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;
}
void bubbleSort(NODE *list)
{
	NODE *cur=list,*tail=NULL;
	int tmp;
	char tmp1[50];
	if(cur==NULL||cur->next==NULL)return;
	while(cur!=tail)
	{
		while(cur->next!=tail)
		{
			if(strcmp(cur->word,cur->next->word)>0)
			{
				tmp=cur->count;
				cur->count=cur->next->count;
				cur->next->count=tmp;
				strcpy(tmp1,cur->word);
				strcpy(cur->word,cur->next->word);
				strcpy(cur->next->word,tmp1);
			}
			cur=cur->next;
		}
		tail=cur;
		cur=list;
	}
}

