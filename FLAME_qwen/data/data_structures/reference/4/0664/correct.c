#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node{
	char word[50];
	int num;
	struct node *next;
}*ptr;
char a[100],b[100];
ptr insert(ptr L,char s[]);
int main()
{
	FILE *fp;
	ptr head=NULL,p=NULL;
	int len;
	fp=fopen("article.txt","r");
	while(fgets(a,1000,fp)!=NULL)
	{
		int cnt=0;
		len=strlen(a);
		for(int i=0;i<len;i++)
		{
			if(isalpha(a[i])!=0)
			b[cnt++]=tolower(a[i]);//小写转换 
			else
			//\0不是空格！所以程序无法执行到这里！！ 
			{
			if(b[0]!='\0')
				{ 
					b[cnt]='\0';
					//printf("%s\n",b);
					head=insert(head,b);
				}
				memset(b,'\0',sizeof(b));
				cnt=0;
			}
			}
		}
	
		p=head;
		for(p=head;p!=NULL;p=p->next)
		printf("%s %d\n",p->word,p->num);
		return 0;
 } 
ptr insert(ptr L,char s[])
{
	ptr p=(ptr)malloc(sizeof(struct node));
	p->num=1;
	strcpy(p->word,s);
	p->next=NULL;
	if(L==NULL)
	{
		L=p;
		return p;
	}
	else
	{
		ptr q=L;
		if(strcmp(L->word,s)>0)
		{
			p->next=L;
			L=p;
			return L;//少写一个return 
		}
		while(q)
		{
			//q=L->next;
			if(strcmp(q->word,s)==0)
			{
				q->num++;
				return L;
				//break;
			}
			else if(strcmp(q->word,s)<0&&q->next==NULL)
			{
				q->next=p;
				p->next=NULL;
				return L;
			//	break;
			}
			else if(strcmp(q->word,s)<0&&strcmp(q->next->word,s)>0)
			{
				p->next=q->next;
				q->next=p;
				return L;
				//break;
			}
			q=q->next;
		}
	}
	
	
}
 

