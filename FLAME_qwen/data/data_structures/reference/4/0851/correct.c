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
struct link * bublesort(struct link *first,int N);
struct link *search(char *str,struct link *first,int N);
int main()
{
	FILE *in;
	struct link *first=NULL,*p=NULL,*q=NULL;
	in=fopen("article.txt","r");
	char str[100],st[1000];
	int i,j,N=0;
	while(fgets(st,100,in)!=NULL)
	{
        for(i=0,j=0;st[i]!='\0';i++)
		{
			if(st[i]>='a'&&st[i]<='z')
			{
				str[j]=st[i];
				j++;
			}
			else if(st[i]>='A'&&st[i]<='Z')
			{
				str[j]=st[i]+32;
				j++;
			}
			else
			{
				str[j]='\0';
				j=0;
				if(strlen(str)!=0)
				{
					if((q=search(str,first,N))!=NULL)
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
						N++;
					}
				}
			}
		}
	}
	first=bublesort(first,N);
	for(p=first,i=0;i<N;p=p->next,i++)
	{
		pf("%s %d\n",p->word,p->count); 
	}
	fclose(in);
}
struct link *search(char *str,struct link *first,int N)
{
	struct link *p;
	if(first==NULL)
	return NULL;
	int i;
	for(p=first,i=0;i<N;p=p->next,i++)
	{
		if(strcmp(p->word,str)==0)
		{
			return p;
		}
	}
	return NULL;
}
struct link * bublesort(struct link *first,int N)
{
	struct link *p=first,*q=first;
	int i,j;
		for(j=0;j<N;j++)
		{
			if(strcmp(first->word,first->next->word)>0)
			{
				p=first;
				first=first->next;
				p->next=first->next;
				first->next=p;
			}
			for(i=0,p=first,q=first->next;i<N-2;i++)
			{
				if(i==N-2)
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

