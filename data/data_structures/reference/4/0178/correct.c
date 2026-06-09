#include<stdio.h>
#include<stdlib.h>
typedef struct word
{
	char s[20];
	int v;
	struct word *next;
}word;
inline void alloc(word **p)
{
	*p=(word*)malloc(sizeof(word));
	memset(*p,0,sizeof(word));
	return;
}
int main()
{
	FILE *in=fopen("article.txt","r+");
	char s[20],c;
	int t=0;
	word *st,*p,*q;
	alloc(&st);
	while(c=fgetc(in),c!=EOF)
	{
		if(c>=65&&c<=90)	c+=32;
		if(c>=97&&c<=122)	s[t++]=c;
		else if(t)
		{
			s[t]=0;
			p=st;
			//printf("%s\n",s);
			//system("pause");
			while(p->next&&strcmp(s,p->next->s)>0)	p=p->next;
			if(!p->next)
			{
				alloc(&(p->next));
				p=p->next;
				memcpy(p->s,s,t);
				p->v=1;
			}
			else if(strcmp(s,p->next->s)<0)
			{
				q=p->next;
				alloc(&(p->next));
				p=p->next;
				memcpy(p->s,s,t);
				p->v=1;
				p->next=q;
			}
			else	p->next->v++;
			t=0;
		}
	}
	p=st->next;
	while(p)
	{
		printf("%s %d\n",p->s,p->v);
		free(st);
		st=p;
		p=p->next;
	}
	free(st);
	fclose(in);
	return 0;
}

