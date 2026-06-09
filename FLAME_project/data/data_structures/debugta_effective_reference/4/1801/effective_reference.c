#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define maxword 100
struct node{
	char word[maxword];
	int count;
	struct node *next;
};
struct node *head=NULL;

int getword(FILE *fi,char *w);
int searchword(char *w);
int insertword(struct node *p, char *w);

int main()
{
	char filename[20]={"article.txt"};
	char word[maxword];
	FILE *fi;
	struct node *p;
	if((fi=fopen(filename,"r")) == NULL)
	{ //打开一个文件
        fprintf(stderr,"%s cant open!\n",filename);
        return -1;
	}
	while(getword(fi,word)!=EOF) 
        if(searchword(word)== -1)
		{
            fprintf(stderr, "Memory is full!\n");
            return -1;
        }
	for(p=head;p!=NULL;p=p->next)
		printf("%s %d\n",p->word,p->count);
	return 0;
}
int getword(FILE *fi,char word[])
{
	int i=0;
	char op;
	while((op=fgetc(fi))!=EOF)
	{
		if(isalpha(op)){
            word[i]=tolower(op);
            i++;
        }//是英文字母则全部转化为小写同时计数加一 
        else if(i>0)
        {
        	word[i]='\0';
        	return 0;
		}
	}
	return EOF;
}
int insertword(struct node *p,char *w)
{
	struct node *q;
	q=(struct node *)malloc(sizeof(struct node));
	if(q==NULL)
	return -1;//这是个空表
	strcpy(q->word,w);//填充链表 
	q->count=1;//每个词初始时都是出现次数为1 
	q->next=NULL;
	if(head==NULL)
	head=q;
	else if(p==NULL)
	{
		q->next=head;
		head=q;
	}
	else {
		q->next=p->next;
		p->next=q;
	}
	return 0;
}
int searchword(char *w)
{
	struct node *p,*q=NULL;
	for(p=head;p!=NULL;q=p,p=p->next)
	{
		if(strcmp(w,p->word)<0)
		break;
		else if(strcmp(w,p->word)==0)
		{
		p->count++;
		return 0;	
		}
	}
	return insertword(q,w);
}

