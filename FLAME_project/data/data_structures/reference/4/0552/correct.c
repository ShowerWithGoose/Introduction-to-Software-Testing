#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char text[10000];
typedef struct node
{
	char word[1024];
	int num;
	struct node *link;	
}NODE;
void Bubblesort(NODE *head)/*冒泡排序*/
{
	int flag=1;/*flag用于记录过得一趟是否有交换*/
	char temp[1024];/*temp用于交换*/
	NODE *cur=head,*tail=NULL;/*tail用来记录为排好序的部分的尾部*/
	if((head==NULL)||(head->link==NULL))/*当链表为空或只有一个元素的时候不用排序*/
		return ; 
	while((cur!=tail)&&(flag==1))
	{
		flag=0;
		while(cur->link!=tail)
		{
			if(strcmp(cur->word,cur->link->word)>0)
			{
				strcpy(temp,cur->word);
				strcpy(cur->word,cur->link->word);
				strcpy(cur->link->word,temp);
				flag=1;
			}
			cur=cur->link;
		}
		tail=cur;
		cur=head;
	}
}
void print(NODE *head)/*打印最终链表*/
{
	NODE *p;
	for(p=head;p!=NULL;p=p->link)
		if(p->num!=0)
			printf("%s %d\n",p->word,p->num);
}
int main()
{
	int len=0,i,j=0;
	char c,single[1024];
	FILE *fp;
	NODE *head=NULL,*p,*r;
	if((fp=fopen("article.txt","r"))==NULL)
	{
		printf("Can't open the file");
		return 0 ;
	}
	c=fgetc(fp);
	while(c!=EOF)
	{
		text[len++]=c;
		c=fgetc(fp);
	}
	for(i=0;i<len;i++)
	{
		if((isalpha(text[i])==0)&&(isalpha(text[i-1])!=0))/*代表一个单词截止了*/
		{
			single[j]='\0';
			p=(NODE *)malloc(sizeof(NODE));
			strcpy(p->word,single);
			p->num=1;
			p->link=NULL;
			if(head==NULL)
				head=p;
			else
				r->link=p;
			r=p;
			memset(single,0,sizeof(char));
			j=0;
		}
		else if(isalpha(text[i])!=0)
			single[j++]=tolower(text[i]);/*记录单词*/
	}
	Bubblesort(head);
	for(p=head;p!=NULL;p=p->link)
	{
		if(p->num!=0)
		{
			for(r=p->link;r!=NULL;r=r->link)
				if(strcmp(r->word,p->word)==0)
				{
					p->num++;
					r->num=0;
				}
		}
		else
			continue;
	}
	print(head);
	return 0 ;
}

