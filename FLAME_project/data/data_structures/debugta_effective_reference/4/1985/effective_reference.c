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

PNODE insert_list(PNODE head,char c[105])
{
	PNODE new=(PNODE)malloc(sizeof(NODE));
	if(head->next==NULL)
	{
		strcpy(new->s,c);
		new->num=1;
		head->next=new;
		new->next=NULL;
	}
	else
	{
		strcpy(new->s,c);
		new->num=1;
		PNODE p=head->next;
		while(p!=NULL)
		{
			if(p->next==NULL)
			  break;
			else p=p->next;
		}
		p->next=new;
		new->next=NULL;	
	}
	return head;
}

bool search_list(PNODE head,char c[105])
{
	if(head->next==NULL)
	{
		return true;
	}
	else
	{
		PNODE p=head->next;
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
	PNODE head=(PNODE)malloc(sizeof(NODE));
	head->next=NULL;
	in=fopen("article.txt","r");
	char w1[32];
	while(getword(in,w1)!=EOF)
	{
		if(search_list(head,w1))
		{
			head=insert_list(head,w1);
			//traverse_list(head);
		}
	}
    soert_list(head);
	PNODE p=head->next;
	while(p!=NULL)
	{
		printf("%s %d\n",p->s,p->num);
		p=p->next;
	}
	fclose(in);
	return 0;
}



