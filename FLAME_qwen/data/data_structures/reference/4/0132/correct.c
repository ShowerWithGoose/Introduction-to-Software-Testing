#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

char buf[20];

int getword()
{
	memset(buf,0,sizeof(buf));
	char c;
	while(1)
	{
		c=getchar();
		if(c==EOF) return EOF;
		if(c>='a'&&c<='z') break;
		if(c>='A'&&c<='Z')
		{
			c-='A'-'a';
			break;
		}
	}
	
	buf[0]=c;
	int i=1;
	while(1)
	{
		c=getchar();
		if(c>='a'&&c<='z')
		{
			buf[i++]=c;
		}
		else if(c>='A'&&c<='Z')
		{
			c-='A'-'a';
			buf[i++]=c;
		}
		else break;
	}
	buf[i]='\0';
	
	return 0;
}


typedef struct word{
	char s[20];
	int count;
	struct word *next;
}word,*pw;


int main()
{
	//freopen("damn.txt","r",stdin);//
	
	freopen("article.txt","r",stdin);
	
	pw start,p,q,front;
	
	start=p=q=front=NULL;
	
	
	while(getword()!=EOF)
	{
		q=(pw)malloc(sizeof(word));
		q->next=NULL;
		
		if(start==NULL)
		{
			start=q;
		}
		else
		{
			p->next=q;
		}
		
		memcpy(q->s,buf,sizeof(buf));
		q->count=1;
		
		p=q;
	}
	
	p=q=NULL;
	
	
	while(1)
	{
		int flag=0;
		p=start;q=start->next;
		front=NULL;
		
		while(1)
		{
			if(strcmp(p->s,q->s)>0)
			{
				flag=1;
				if(front==NULL)
				{
					start=q;
					p->next=q->next;
					q->next=p;
					
					p=q;
					q=q->next;
				}
				else
				{
					front->next=q;
					p->next=q->next;
					q->next=p;
					
					p=front->next;
					q=q->next;
				}
				
				front=p;
				p=p->next;
				q=q->next;
				
			}
			else if(strcmp(p->s,q->s)==0)
			{
				flag=1;
				if(front==NULL)
				{
					start=q;
					q->count+=p->count;
					free(p);
					p=q;
					q=q->next;
				}
				else
				{
					front->next=q;
					q->count+=p->count;
					free(p);
					p=q;
					q=q->next;
				}
			}
			else 
			{
				front=p;
				p=q;
				q=q->next;
			}
			if(q==NULL) break;
		}
		if(flag==0) break;
	}
	
	p=q=NULL;
	
	p=start;
	while(p!=NULL)
	{
		printf("%s %d\n",p->s,p->count);
		p=p->next;
	}
	
	return 0;
}

