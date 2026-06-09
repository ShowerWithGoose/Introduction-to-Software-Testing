#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define ep 1e-6
#define pi 3.14159265
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define NumberOf(x) (sizeof(x)/sizeof(x[0])
#define max(A,B) ((A)>(B)?(A):(B))
struct link {
	char *word;
	int count;
	struct link *next;
};
struct link * bublesort(struct link *first,int time);
struct link *search(char *str,struct link *first,int time);
int main()
{
	FILE *in;
	struct link *first=NULL,*p=NULL,*q=NULL;
	in=fopen("article.txt","r");
	char str[100],c[1000];
	int i,sh,time=0;
	while(fgets(c,100,in)!=NULL)
	{
        for(i=0,sh=0;c[i]!='\0';i++)
		{
			if(c[i]>='a'&&c[i]<='z')
			{
				str[sh]=c[i];
				sh++;
			}
			else if(c[i]>='A'&&c[i]<='Z')
			{
				str[sh]=c[i]+32;
				sh++;
			}
			else
			{
				str[sh]='\0';
				sh=0;
				if(strlen(str)!=0)
				{
					if((q=search(str,first,time))!=NULL)
					{
						(q->count)++; 
					}
					else
					{
						q=(struct link *)malloc(sizeof(struct link));
						q->word=(char *)malloc(strlen(str)+1);
						q->count=1;
						strcpy(q->word,str);
						if(first!=NULL)
						{
							p->next=q;
							p=p->next;
							p->next=NULL;
						}
						else
						{
							first=p=q;
							p->next=NULL;
						}
						time++;
					}
				}
			}
		}
	}
	first=bublesort(first,time);
	for(p=first,i=0;i<time;p=p->next,i++)
	{
		pf("%s %d\n",p->word,p->count); 
	}
	fclose(in);
}
struct link *search(char *str,struct link *first,int time)
{
	struct link *p;
	if(first==NULL)
	return NULL;
	int i;
	for(p=first,i=0;i<time;p=p->next,i++)
	{
		if(strcmp(p->word,str)==0)
		{
			return p;
		}
	}
	return NULL;
}
struct link * bublesort(struct link *first,int time)
{
	struct link *p=first,*q=first;
	int i,sh;
		for(sh=0;sh<time;sh++)
		{
			if(strcmp(first->word,first->next->word)>0)
			{
				p=first;
				first=first->next;
				p->next=first->next;
				first->next=p;
			}
			for(i=0,p=first,q=first->next;i<time-2;i++)
			{
				if(i==time-2)
				{
					if(strcmp(p->next->word,p->next->next->word)>0)
					{
						p->next=q->next;
						p->next->next=q;
					}
				}
				else
				{
					if(strcmp(q->word,q->next->word)>0)
					{
						p->next=q->next;
						q->next=q->next->next;
						p->next->next=q;
						p=p->next;
					}
					else
					{
						p=p->next;
						q=q->next;
					}
				}
			}
		}
		return first;
}

