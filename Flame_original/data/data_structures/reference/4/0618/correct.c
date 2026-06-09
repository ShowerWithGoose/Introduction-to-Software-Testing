#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	struct node {
		char ch[100]; 
    	int data;
    	struct node * next;
	};
	typedef struct node *Nodeptr;
	typedef struct node Node;
	Nodeptr list,p,q,tmp;
	list=(Nodeptr)malloc(sizeof(Node));
	list->next=NULL;
	FILE *in,*out;
	char s[100],c;
	int flag;
	in=fopen("article.txt","r");
	out=fopen("out.txt","w");
	while((c=fgetc(in))!=EOF)
	{
		if(c>='A'&&c<='Z') fputc(c+32,out);
		else if(c>='a'&&c<='z') fputc(c,out);
		else fputc('\0',out);
	}
	fclose(in);
	fclose(out);
	out=fopen("out.txt","r");
	in=fopen("article.txt","w");
	while((c=fgetc(out))!=EOF)
	{
		flag=1;
		while(c>='a'&&c<='z')
		{
			flag=0;
			fputc(c,in);
			c=fgetc(out);
		}
		if(!flag) fputc('\n',in);
	}
	fclose(in);
	fclose(out);
	in=fopen("article.txt","r");
	fscanf(in,"%s",list->ch);
	list->data=1;
	while(fscanf(in,"%s",s)!=EOF)
	{
		p=list;
		while(p!=NULL&&strcmp(p->ch,s)<0)
		{
			q=p;
			p=p->next;
		}
		if(p==NULL)
		{
			p=(Nodeptr)malloc(sizeof(Node));
			q->next=p;
			p->next=NULL;
			strcpy(p->ch,s);
			p->data=1;
		}
		else if(strcmp(p->ch,s)==0)
		{
			p->data++;
		}
		else if(p==list)
		{
			q=(Nodeptr)malloc(sizeof(Node));
			q->next=list;
			list=q;
			q->data=1;
			strcpy(q->ch,s);
		}
		else
		{
			tmp=(Nodeptr)malloc(sizeof(Node));
			tmp->data=1;
			strcpy(tmp->ch,s);
			q->next=tmp;
			tmp->next=p;
		}
	}
	fclose(in);
	p=list;
	while(p!=NULL)
	{
		printf("%s %d\n",p->ch,p->data);
		p=p->next;
	}
	return 0;
}

