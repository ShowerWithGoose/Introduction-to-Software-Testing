//3-5 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct word{
	char s[32];
	int n;
	struct word *next; 
}; 
char buf1[10000],buf2[500][32];
int i,j,k,r,l1,flag;
struct word *head=NULL,*p=NULL,*q=NULL;
FILE *in;
void read()
{
	l1=strlen(buf1);
	while(i<l1&&!((buf1[i]>='A'&&buf1[i]<='Z')||(buf1[i]>='a'&&buf1[i]<='z')))
		i++;
	for(;i<l1;i++)
	{
		if(buf1[i]>='A'&&buf1[i]<='Z')
			buf2[k][r++]=buf1[i]+'a'-'A';
		else if(buf1[i]>='a'&&buf1[i]<='z')
			buf2[k][r++]=buf1[i];
		else
		{
			k++;
			r=0;
		}
	}
}
int main()
{
	in=fopen("article.txt","r");
	memset(buf1,0,sizeof(buf1));
	memset(buf2,0,sizeof(buf2));
	head=(struct word*)malloc(sizeof(struct word));
	memset(head->s,0,sizeof(head->s));
	head->n=-1;
	head->next=NULL; 
	while(fgets(buf1,10000,in)!=NULL)
	{
		i=0;
		read();
		if(head->next==NULL)
		{
			p=(struct word*)malloc(sizeof(struct word));
			memset(p->s,0,sizeof(p->s));
			strcpy(p->s,buf2[0]);
			p->n=1;
			p->next=NULL;
			head->next=p;
		}
		for(i=1;i<k;i++)
		{
			flag=0;
			q=(struct word*)malloc(sizeof(struct word));
			memset(q->s,0,sizeof(q->s));
			strcpy(q->s,buf2[i]);
			q->n=1;
			q->next=NULL;
			p=head;
			while(p->next!=NULL)
			{
				if(strcmp(p->next->s,q->s)==0)
				{
					p->next->n++;
					free(q);
					flag=1;
					break;
				}
				p=p->next;
			}
			if(!flag)
			{
				if(strcmp(head->next->s,q->s)>0)
				{
					flag=1;
					q->next=head->next;
					head->next=q;
				}
				else
				{
					p=head->next;
					while(p->next!=NULL)
					{
						flag=0;
						if(strcmp(p->next->s,q->s)>0&&strcmp(p->s,q->s)<0)
						{
							flag=1;
							q->next=p->next;
							p->next=q;
							break;
						}
						p=p->next;
					}
					if(!flag)
						p->next=q;
				}
			}
		}
		memset(buf1,0,sizeof(buf1));
		memset(buf2,0,sizeof(buf2));
	}
	p=head->next;
	if(p->next!=NULL)
	{
		p=p->next;
		while(p!=NULL)
		{
			printf("%s %d\n",p->s,p->n);
			p=p->next;
		}
	}
	p=head;
	while(p!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	}
	fclose(in);
	return 0;
}


