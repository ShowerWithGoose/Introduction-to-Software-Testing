#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char a[1055],b[105];
typedef struct node
{
	char s[105];
	int number;
	struct node *next;
}*List;
List insert(List L,char s1[])
{
	List p=(List)malloc(sizeof(struct node));
	p->next=NULL;
	p->number=1;
	strcpy(p->s,s1);
	if(L==NULL)
	L=p;
	else
	{
		List q=L;
		if(strcmp(s1,L->s)<0)
		{
			p->next=L;
			return p;
		} 
		while(q)
		{
			if(strcmp(s1,q->s)==0)
			{
				q->number++;
				break;
			}
			else if(strcmp(s1,q->s)>0&&q->next==NULL)
			{
				q->next=p;
				break;
			}
			else if(strcmp(s1,q->s)>0&&q->next!=NULL)
			{
				if(strcmp(s1,q->next->s)<0)
				{
					p->next=q->next;
					q->next=p;
					break;
				}
				else
				{
					q=q->next;
				}
			}
		}
	}
	return L;
}
int main()
{
	FILE *in;
	List head=NULL,p=NULL;
	//head->next=NULL;
	in=fopen("article.txt","r");
	while(fgets(a,1055,in)!=NULL)
	{
		int len=strlen(a),k=0,cnt=0;
		for(int i=0;i<len;i++)
		{
			if(isalpha(a[i]))
			{
				if(a[i]>='A'&&a[i]<='Z')
				a[i]+=32;
				b[cnt++]=a[i];
				//k=1;
			}
			else
			{
				if(b[0]!='\0')
				{
					b[cnt]='\0';
					head=insert(head,b);
				}
				memset(b,'\0',sizeof(b));
				cnt=0;
			}
		}
		if(b[0]!='\0')
		{
			b[cnt]='\0';
			head=insert(head,b);
		}
	}
	p=head;
	while(p!=NULL)
	{
		printf("%s %d\n",p->s,p->number);
		p=p->next;
	}
	fclose(in);
	return 0;
}

