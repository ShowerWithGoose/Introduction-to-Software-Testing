//注意：打印时pmove->next不可以置空
//只有新结点才需要动态分配内存 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node
{
	int count;
	char word[505];
	struct node *next;
};
void getarticle(FILE *in);
void getword(FILE *in);
char s[505];
struct node info[505];
int i,j,k,l;
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	getarticle(in);
	getword(in);
	struct node *head=NULL;
	head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	strcpy(head->word,"!");
	head->count=1;
	struct node *p=head;
	p->next=NULL;
	for(i=0;i<l;i++)
	{
		int flag=0;
		/*if(head==NULL)
		{
			strcpy(head->word,info[i].word);
			head->count++;
		}*/
		for(p=head;p!=NULL;p=p->next)//查找单词位置 
		{
			if(strcmp(p->word,info[i].word)==0)//找到了 
			{
				p->count++;
				flag=1;
			}
		}//正确 
		if(flag==1) continue;
		else if(flag==0)//没找到 
		{
			struct node *t;
			struct node *tfront;
			struct node *r=(struct node*)malloc(sizeof(struct node));
			for(t=head->next,tfront=head;t!=NULL;tfront=t,t=t->next)
			{
				if(strcmp(tfront->word,info[i].word)<0&&strcmp(t->word,info[i].word)>0)//找到位置，插入 
				{
					strcpy(r->word,info[i].word);
					r->count=1;
					r->next=tfront->next;
					tfront->next=r;
					break;
				}
			}
			if(t==NULL)
			{
				r->count=1;
				strcpy(r->word,info[i].word);
				tfront->next=r;
				r->next=NULL;
			}
		}
		/*struct node *pmove=head->next;
		pmove->next=NULL;
		while(pmove!=NULL)
	{
		printf("%s %d\n",pmove->word,pmove->count);
		pmove=pmove->next; 
	}
	printf("\n");*/
	}
	struct node *pmove=head->next;
	//pmove->next=NULL;
	//printf("%s %d\n",head->word,head->count);
	while(pmove!=NULL)
	{
		printf("%s %d\n",pmove->word,pmove->count);
		pmove=pmove->next; 
	}
	fclose(in); 
	return 0;
}
void getarticle(FILE *in)
{
	int i=0;
	char c;
	while((c=fgetc(in))!=EOF)
	{
			s[i]=c;
			i++;
	}
	for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i]))
		{
			s[i]=tolower(s[i]);
		}
	}
} 
void getword(FILE *in)
{
	int i,j,k;
	char tmp[505];
	for(i=0;i<strlen(s);i++)
	{
		if(isalpha(s[i])!=0)
		{
			for(j=i+1;j<strlen(s);j++)
			{
				if(isalpha(s[j])==0)
				break;
			}
			memset(tmp,0,sizeof(tmp));
			for(k=0;k<j-i;k++)
			{
				tmp[k]=s[k+i];
				//printf("%c",tmp[k]);
			}
			strcpy(info[l].word,tmp);
			l++;
			i=j;
		}
		else continue;
	}
}



