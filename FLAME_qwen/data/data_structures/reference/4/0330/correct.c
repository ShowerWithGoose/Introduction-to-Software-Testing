#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char str[10000];
char str1[10000];
char a[100];
typedef struct Word{
	char w[100];
	int count;
	struct Word *link;
}words,*links;
int main()
{
	
	char tem;
	int i,j,k,l,sum=0;
	int flag=0;
	links r,r1,p,q,head=NULL,con;
	freopen("article.txt","r",stdin); 
	for( i=0,j=0;(tem=getchar())!=EOF;i++)
	{
		if(islower(tem)!=0)
		{
			str[j++]=tem;
		}		
		else if(isupper(tem)!=0)
		{
			str[j++]=tem-'A'+'a';
		}
		else if(isalpha(tem)==0)
		{
			str[j++]='0';
		}
	}
	fclose(stdin);
	for(k=0,l=0;k<j;k++)
	{
		if(str[k]=='0'&&str[k+1]=='0')
		{
			while(str[k]=='0') 
			{
				k++;
			}
			str1[l++]='0';
			k--;
		}
		else
		str1[l++]=str[k];
	} 
	
	for(i=0,k=0;str1[i]!='\0';i++)
	{
		if(str1[i]=='0')
		{
			a[k]='\0';
			if(head==NULL)
			{
			p=(links)malloc(sizeof(words));
			strcpy(p->w,a);
			p->count=1;
			head=p;
			p->link=NULL;
			sum++;
			} 
			else
			{
			q=head;
			while(q!=NULL)
			{
				if(strcmp(q->w,a)==0)
				{
					(q->count)++;
					flag=1;
				}	
				r=q;
				q=q->link;			
			}
			if(flag==0)
			{
				p=(links)malloc(sizeof(words));
				strcpy(p->w,a);
				p->count=1;
				r->link=p;
				p->link=NULL;
				sum++;
			}
			flag=0; 
			}
			memset(a,0,sizeof(a));
			k=0;
			
		}
		else
		{
			a[k++]=str1[i];
		}
		
	}
	//ÅÅÐò 
	r1=(links)malloc(sizeof(words));
	r1->link=head;
	for(i=0;i<(sum-1);i++)	
	{
		r=r1;
		p=head;
		q=head->link;
		while(p!=NULL&&q!=NULL)
		{
			if(strcmp(p->w,q->w)>0)
			{
				if(p==head)
				{
					p->link=q->link;
					q->link=p;
					head=q;
					r1->link=q;
					con=p;
					p=q;
					q=con;		
				}
				else
				{
					p->link=q->link;
					q->link=p;
					r->link=q;
					con=p;
					p=q;
					q=con;
				}
			}
			r=r->link;
			p=p->link;
			q=q->link;
		}	
	}
		p=head;
		while(p!=NULL)
		{
			printf("%s %d\n",p->w,p->count);
			p=p->link; 
		}
	
	
}

