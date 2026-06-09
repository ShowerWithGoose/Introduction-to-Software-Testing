#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct word{
	char str[50];
	int num;
	struct word *link;
};
int getword(FILE *p,char q[]);
void compare(char ch[],struct word *head);
void destroylist(struct word *list);
int main()
{
	FILE *in,*fp;
	struct word *head,*p;
	char ch[50];
	in=fopen("article.txt","r");
	fp=in;
	head=malloc(sizeof(struct word));
	head->str [0]='0';
	head->str [1]='\0';
	head->num =0;
	head->link =NULL;
	while(getword(fp,ch)!=EOF)
	{
		compare(ch,head);
	}
	for(p=head->link ;p!=NULL;p=p->link )
	{
		printf("%s %d\n",p->str ,p->num );
	}
	destroylist(head);
	fclose(in);
	return 0;
}
int getword(FILE *p,char q[])
{
	int i=1,c;
	c=fgetc(p);
	while(!((c>='a'&&c<='z')||(c>='A'&&c<='Z')))
	{
		if(c==EOF)
		{
			return c;
		}
		else
		{
			c=fgetc(p);
		}
	}
	if(c>='A'&&c<='Z')
	{
		c=c-'A'+'a';
	}
	q[0]=c;
	while((c=fgetc(p))!=EOF)
	{
		if(!((c>='a'&&c<='z')||(c>='A'&&c<='Z')))
		{
			break;
		}
		else 
		{
			if(c>='A'&&c<='Z')
			{
				c=c-'A'+'a';	
			}
			q[i]=c;
			i++;
		}
	}
	q[i]='\0';
	return 1;
}
void compare(char ch[],struct word *head)
{
	struct word *q,*p=head,*r=NULL;
	q=malloc(sizeof(struct word));
	strcpy(q->str ,ch);
	q->num =1;
	q->link =NULL;
	for(p=head;p!=NULL&&(strcmp(p->str ,q->str )<0);r=p,p=p->link )
	{
		;
	}
	if(p==NULL)
	{
		r->link =q;
		q->link =p;
	}
	else if(strcmp(p->str ,q->str )==0)
	{
		p->num =p->num +1;
		free(q);
	}
	else
	{
		r->link =q;
		q->link =p;
	}
}
void destroylist(struct word *list)
{
	if(list->link ==NULL)
	{
		free(list);
	}
	else
	{
		destroylist(list->link );
		free(list);
	}
}

