#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char e[1024];
char f[50];
struct word
{
	char ch[50];
	int count;
	struct word *next;
};
int isalph(char c)
{
	if('a'<=c&&c<='z')
		return 1;
	return 0;
}
struct word *settleword(struct word* head,struct word* p);//更新数据库
int main()
{
	FILE *in=fopen("article.txt","r");
	struct word *head=(struct word *)malloc(sizeof(struct word));
	struct word *p;
	head=NULL;
	while(fgets(e,1024,in)!=NULL)
	{
		int i,j,k;
		int len=strlen(e);
		for(i=0;e[i]!='\0';i++)
		{
			if(e[i]>='A'&&e[i]<='Z')
			{
				e[i]=e[i]+'a'-'A';
			}
		}
		for(i=0,j=0;e[j]!='\0';j++)
		{
			p=(struct word *)malloc(sizeof(struct word));
			for(i=j;isalph(e[i])==0;i++)
				if(i>=len)
				break;
			for(j=i;isalph(e[j])!=0;j++)
				if(j>=len)
				break;
			for(k=0;i+k<j;k++)
				p->ch[k]=e[i+k];
			p->ch[k]='\0'; 
			if(!isalph(p->ch[0]))
				continue;
			head=settleword(head,p);
		}
	}
	p=head;
	while(p)
	{
		printf("%s %d\n",p->ch,p->count);
		p=p->next;
	}
	fclose(in);
	return 0;	
}
struct word *settleword(struct word* head,struct word* p)//更新数据 
{
	struct word *pf,*pb;
	if(head==NULL)//第一次读入
	{
		head=p;
		p->next=NULL;
		p->count=1;
		return head;
	}
	pf=head;
	pb=pf->next;
	if(head!=NULL)
	{
		if(pb==NULL)//第二次读入
		{
			if(strcmp(pf->ch,p->ch)>0)
			{
				head=p;
				p->next=pf;
				p->count=1;
				return p;
			}
			else if(strcmp(pf->ch,p->ch)<0)
			{
				pf->next=p;
				p->next=NULL;
				p->count=1;
			}
			else
			{
				pf->count++;
			}
		return pf;
		}
		else//一般情况
		{
			if(strcmp(pf->ch,p->ch)>0)//p成为表头 
			{
				head=p;
				p->next=pf;
				p->count=1;
			return p;
			}
			else if(strcmp(pf->ch,p->ch)==0)
			{
				pf->count++;
				return head;
			}
			else if(strcmp(pf->ch,p->ch)<0)//否则遍历寻找插入位置
			{
				while(pb!=NULL)
				{
					if(strcmp(pb->ch,p->ch)<0)
					{
						pf=pf->next;
						pb=pb->next;
						continue;	
					}
					if(strcmp(pb->ch,p->ch)>0)
					{
					pf->next=p;
					p->next=pb;
					p->count=1;
					return head;
					}
					else if(strcmp(pb->ch,p->ch)==0)
					{
						pb->count++;
					}
				return head;	
				}//若pb==NULL仍未返回，则表明p应放在表尾 
				pf->next=p;
				p->next=NULL;
				p->count++;
			return head;
			} 
		} 
	}
}

