#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define Maxline 1024
struct node{
	char word[30];
	int times;
	struct node*next;
};
struct node*CreateList()
{
	struct node*head;
	head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	return head;
}

void Count(struct node*head,char s[])
{
	int i,j;
	char line[30]; 
	struct node*p,*q;
	int l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(isalpha(s[i]))
		{
			j=0;
			while(isalpha(s[i+j]))
			{
				line[j]=tolower(s[i+j]);
				j++;
			}
			line[j]='\0'; 
			i=i+j;
			if(head->next==NULL)
			{
				p=(struct node*)malloc(sizeof(struct node));
				head->next=p;
				p->next=NULL;
				strcpy(p->word,line);
				p->times=1;
			}
			else
			{
				p=head->next;
				q=p;
				while(p!=NULL)
				{
					if(strcmp(p->word,line)==0)
					{
						p->times++;
						break;
					}
					q=p;
					p=p->next;
				}
				if(p==NULL)
				{
					p=(struct node*)malloc(sizeof(struct node));
					q->next=p;
					p->next=NULL;
					p->times=1;
					strcpy(p->word,line);
				}
			}
		}	
	}
}
void Order(struct node*head)
{
	struct node*p,*q;
	int temp;
	char hold[30];
	for(p=head->next;p!=NULL;p=p->next)
	{
		for(q=head->next;q->next!=NULL;q=q->next)
		{
			if(strcmp(q->word,q->next->word)>0)
			{
				temp=q->times;
				q->times=q->next->times;
				q->next->times=temp;
				strcpy(hold,q->word);
				strcpy(q->word,q->next->word);
				strcpy(q->next->word,hold);
			}
		}
	}	
}
 
int main()
{
	FILE*in;
	in = fopen("article.txt","r");
	char s[Maxline];
	struct node *head,*p;
	head = CreateList();
	while(fgets(s,Maxline,in)!=NULL)
	{
		Count(head,s);
	}
	Order(head);
	p=head->next;
	while(p!=NULL)
	{
		printf("%s %d\n",p->word,p->times);
		p=p->next;
	}
	fclose(in);
	return 0;
}

