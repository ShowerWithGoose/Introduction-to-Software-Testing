#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct words{
	char word[15];
	int times;
	struct words *link;
}LNode,*LinkList;

FILE *in;
int main()
{
	char m[100]={0};
	LinkList list=NULL,p,q,r;
	char s[100]={0};
	if((in=fopen("article.txt","r"))==NULL)
	{
		printf("wrong\n");
		return 1;
	}
	while((fgets(s,100,in))!=NULL)
	{
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
				s[i]=s[i]-'A'+'a';
		}
		for(int i=0;i<len;i++)
		{
			int j=i;
			while(s[j]>='a'&&s[j]<='z')
				j++	;
			if(j>i)
			{
				int k=0;
				for(i=i;i<j;i++)
				{
					m[k++]=s[i];
				}
				m[k]='\0';
				if(list==NULL)
				{
					p=(LinkList)malloc(sizeof(LNode));
					strcpy(p->word,m);
					p->times=1;
					list=p;
					list->link=NULL;
				}
				else
				{
					p=list;
					if(strcmp(p->word,m)>0)
					{
						q=(LinkList)malloc(sizeof(LNode));
						strcpy(q->word,m);
						q->times=1;
						q->link=p;
						list=q;
						continue;
					}
					if(strcmp(p->word,m)==0)
					{
						p->times++;
						continue;
					}
					r=p->link;
					if(r==NULL)
					{
						q=(LinkList)malloc(sizeof(LNode));
						strcpy(q->word,m);
						q->times=1;
						p->link=q;
						q->link=NULL;
						continue;
					}
					while(r->link!=NULL&&strcmp(r->word,m)<0)
					{
						p=p->link;
						r=p->link;
					}
					if(r->link==NULL)
					{
						int pp=strcmp(r->word,m);
						if(pp<0)
						{
							q=(LinkList)malloc(sizeof(LNode));
							strcpy(q->word,m);
							q->times=1;
							r->link=q;
							q->link=NULL;
							continue;
						}
						if(pp==0)
						{
							r->times++;
							continue;
						}
						if(pp>0)
						{
							q=(LinkList)malloc(sizeof(LNode));
							strcpy(q->word,m);
							q->times=1;
							p->link=q;
							q->link=r;
							continue;
						}
					}
					else
					{
						if(strcmp(r->word,m)==0)
						{
							r->times++;
							continue;
						}
						else
						{
							q=(LinkList)malloc(sizeof(LNode));
							strcpy(q->word,m);
							q->times=1;
							p->link=q;
							q->link=r;
							continue;
						}
					}
				}
			}
		}
	}
	while(list!=NULL)
	{
		printf("%s %d\n",list->word,list->times);
		list=list->link; 
	}
 	return 0;
}


