#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
#define ll long long
#define Maxsize 1000
typedef struct node
{
	char s[10000];
	int num;
	int flag;
	struct node *link;
}lin;
lin*first;
lin ss;
char t[10000];
int find(lin*aim)
{
	lin*p=first;
	while(p!=NULL)
	{
		if(strcmp(p->s,aim->s)==0)
		{
			p->num++;
			return 1;
		}
		p=p->link;
	}
	return -1;
}
int main()
{
 	FILE*in;
 	in=fopen("article.txt","r");
 	lin*p,*q,*ans;
 	char a;
 	int ee=0;
 	int e=-1,flag,nlen=0,nflag=0;
 	while((a=fgetc(in))!=EOF)
 	{
 		if(isalpha(a))flag=1;
 		else flag=0;
 		if(flag)
 		{
 			a=tolower(a);
 			if(e==-1)
			 {
			 	q=(lin*)malloc(sizeof(ss));
			 	q->num=0;
				q->flag=0;
			 }
			q->s[++e]=a;
			nflag=1;
		}
		else
		{
			if(nflag==0)continue;
			else if(nflag==1)
			{
				nflag=0;
				nlen++;
			}
			if(nlen==1)
			{
				q->s[++e]='\0';
				first=q;
				p=q;
				e=-1;
				(q->num)++;
				p->link=NULL;
			}
			else
			{
				q->s[++e]='\0';
				e=-1;
				q->link=NULL;
				if(find(q)==-1)
				{
					p->link=q;
					p=q;
					(p->num)++;
					p->link=NULL;
				}
				else 
				{
					nlen--;
					continue;
				}
			}
		}
	}
	if(flag==1)
	{
		q->s[++e]='\0';
		if(first==NULL)first=q;
		else
		{
			p->link=q;
			p=q;
			(p->num)++;
		}
		nlen++;
		q->link=NULL;
	}
	e=0;
	if(nlen==0)return 0;
	if(nlen==1)printf("%s %d",first->s,first->num);
	else if(nlen==2)
	{
		if(strcmp(first->s,p->s)<0)
		{
			printf("%s %d\n%s %d",first->s,first->num,p->s,p->num);
		}
		else
		{
			printf("%s %d\n%s %d",p->s,p->num,first->s,first->num);
		}
	}
	else
	{
		p->link=first;
		while(e!=nlen)
		{
			p=first;
			ee=0;
			while(p->flag)
			{
				p=p->link;
				ee++;
				if(ee==nlen)break;
			}
			ans=p;
			q=p;
			do
			{
				if(strcmp(p->s,ans->s)<0&&!p->flag)ans=p;
				p=p->link;
			}while(p!=q);
			printf("%s %d\n",ans->s,ans->num);
			ans->flag=1;
			e++;
		}
	}
	return 0;
}


