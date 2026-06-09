#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct line{
	char word[20];
	int times;
	struct line *next;
};
int Isword(char a)
{
	if(a>='a' && a<='z')
		return 1;
	else
		return 0;
}
void down(char *c)
{
	if(*c>='A' && *c<='Z')
		*c=*c-'A'+'a';
}
void sort(struct line *f)
{
	if(f->next==NULL || f->next->next==NULL)
		return;
	struct line *head,*pre,*cur,*next,*end,*temp;
	head=f;
	end=NULL;
	while(head->next!=end)
	{
		for(pre=head,cur=pre->next,next=cur->next;next!=end;pre=pre->next,cur=cur->next,next=next->next)
		{
			if(strcmp(cur->word,next->word)>0)
			{
				cur->next=next->next;
				pre->next=next;
				next->next=cur;
				temp=next;
				next=cur;
				cur=temp;
			}
		}
		end=cur;
	}
}
int main()
{
	struct line *f,*p,*q;
	FILE *in;
	char c,lc='/',w[20];
	int i,flag;
	in=fopen("article.txt","r");
	f=NULL;
	c=fgetc(in);
	while(lc!=EOF)
	{
		down(&c);
		if(Isword(c) && !Isword(lc))
		{
			i=0;
			w[i]=c;
		}
		else if(Isword(c) && Isword(lc))
		{
			i++;
			w[i]=c; 
		}
		else if(!Isword(c) && Isword(lc))
		{
			i++;
			w[i]='\0';
			if(f==NULL)
			{
				f=(struct line *)malloc(sizeof(struct line));
				p=f;
				p->next=NULL;
				p->times=1;
				strcpy(p->word,w);
			}
			else
			{
				flag=0;
				for(q=f;q!=NULL;q=q->next)
				{
					if(!strcmp(w,q->word))
					{
						q->times++;
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					p->next=(struct line *)malloc(sizeof(struct line));
					p=p->next;
					p->next=NULL;
					p->times=1;
					strcpy(p->word,w);
				}
			}
			memset(w,0,sizeof(w));
		}
		lc=c;
		c=fgetc(in);
	}
	p=f;
	f=(struct line *)malloc(sizeof(struct line));
	f->next=p;
	sort(f);
	for(p=f->next;p!=NULL;p=p->next)
		printf("%s %d\n",p->word,p->times);
	return 0;
 } 

