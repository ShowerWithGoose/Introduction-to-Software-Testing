#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
	char s[105];
	int num;
	struct node *next;
}NODE,*PNODE;

int getword(FILE *in,char *w)
{
	int c;
	while(!isalpha(c=fgetc(in)))
	{
		if(c==EOF) return c;
		else continue;
	}
	do{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(in)));
	*w='\0';
	return 1;
}

PNODE insert_list(PNODE w,char c[105])
{
	PNODE new=(PNODE)malloc(sizeof(NODE));
	if(w->next==NULL)
	{
		strcpy(new->s,c);
		new->num=1;
		w->next=new;
		new->next=NULL;
	}
	else
	{
		strcpy(new->s,c);
		new->num=1;
		PNODE r=w->next;
		while(r!=NULL)
		{
			if(r->next==NULL)
			  break;
			else r=r->next;
		}
		r->next=new;
		new->next=NULL;	
	}
	return w;
}

bool search_list(PNODE w,char c[105])
{
	if(w->next==NULL)
	{
		return true;
	}
	else
	{
		PNODE p=w->next;
		while(p!=NULL)
		{
			if(strcmp(p->s,c)==0)
			{
				p->num++;
		    	return false;	
			}
			else
			p=p->next;  
		}
		return true;
	}

}
int length_list(PNODE pHead)
{
	int len=0;
	PNODE p=pHead->next;
	while(p!=NULL)
	{
		++len;
		p=p->next;
	}	
	return len;	
}
void soert_list(PNODE pHead)//ÅÅÐò 
{
	int i,j,len,num;
	char t[105];
	len=length_list(pHead);
	PNODE p,q;
	for(i=0,p=pHead->next;i<len-1;i++,p=p->next)
	{
		for(j=i+1,q=p->next;j<len;j++,q=q->next)
		{
		   if(strcmp(p,q)>0)
		   {
		   	 strcpy(t,p->s);
		   	 strcpy(p->s,q->s);
		   	 strcpy(q->s,t);
		   	 num=p->num;
		   	 p->num=q->num;
		   	 q->num=num;
		   }	
		}
	}
	return ;
}
void traverse_list(PNODE pHead)//±éÀú 
{
	PNODE p=pHead->next;
	while(NULL!=p)
	{
		printf("%s ",p->s);
		p=p->next;
	}
	return ;
} 
int main()
{
	FILE *in;
	PNODE w=(PNODE)malloc(sizeof(NODE));
	w->next=NULL;
	in=fopen("article.txt","r");
	char word[32];
	while(getword(in,word)!=EOF)
	{
		if(search_list(w,word))
		{
			w=insert_list(w,word);
			//traverse_list(head);
		}
	}
    soert_list(w);
	PNODE r=w->next;
	while(r!=NULL)
	{
		printf("%s %d\n",r->s,r->num);
		r=r->next;
	}
	fclose(in);
	return 0;
}



