#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
struct node
{
	char word[100];
	int num;
	struct node*next; 
}*head;
int main()
{
	head=NULL;
	FILE* in;
	in=fopen("article.txt","r");
	char c;
	struct node* tail,*q,*p,*head,*k;
	head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	tail=head;
	while((c=fgetc(in))!=EOF)
	{
		if(isalpha(c))
		{
			char s[100];//char *s不行 
			int i;
			for(i=0;isalpha(c)!=0;i++)
			{
				s[i]=tolower(c);
				c=fgetc(in);
			}
			s[i]='\0';
			int flag=0;
			p=head;
			while((p->next)!=NULL)
			{
				if(strcmp(p->next->word,s)==0)
				{
					p->next->num++;
					flag=1;
					break;
				}
				else if(strcmp(p->next->word,s)>0)
				{
					q=(struct node*)malloc(sizeof(struct node));
					q->num=1;
					strcpy(q->word,s);
					q->next=p->next;
					p->next=q;
					flag=1;
					break;
				}//插入错位 
				p=p->next;
			}
			if(flag==0)
			{
				k=(struct node*)malloc(sizeof(struct node));
				k->num=1;
				strcpy(k->word,s);
				k->next=NULL;
				tail->next=k;
				tail=k;
			}
		}
	}
	q=head->next;
	while(q!=NULL)
	{
		printf("%s %d\n",q->word,q->num);
		q=q->next; 
	}
	return 0; 
}


