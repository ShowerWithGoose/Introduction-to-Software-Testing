#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN sizeof(NODE)
#define M 100
typedef struct node
{
	char c;
	struct node *link;
}NODE;
int compare(char a,char b)
{
	if(((a=='+')&&((b=='*')||(b=='/')))||((a=='-')&&((b=='*')||(b=='/'))))
		return 0;
	else 
		return 1;
} 
int isnum(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/')
		return 2 ;
	else if(c>='0'&&c<='9')
		return 1 ;
	else
		return 0 ;
}
void transfer(char s[],char t[])
{
	int len,i,j=0;
	NODE *p=NULL,*r;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t[j++]=s[i];
			if(isnum(s[i+1])!=1)
				t[j++]=' ';
		}
		else
		{
			if(p==NULL)
			{
				p=(NODE *)malloc(LEN);
				p->c=s[i];
				r=NULL;
				p->link=r;	
			}
			else
			{
				if(compare(p->c,s[i])==0)
				{
					r=p;
					p=(NODE *)malloc(LEN);
					p->c=s[i];
					p->link=r;
				}
				else
				{
					while(compare(p->c,s[i])==1)
					{
						t[j++]=p->c;
						free(p);
						p=r;
						if(p==NULL)
							break;
						r=p->link;
					}
					if(p==NULL)
					{
						p=(NODE *)malloc(LEN);
						p->c=s[i];
						r=NULL;
						p->link=r;
					}
					else
					{
						r=p;
						p=(NODE *)malloc(LEN);
						p->c=s[i];
						p->link=r;
					}
				}
			}
		}
	}
	for(;p!=NULL;p=p->link)
		t[j++]=p->c;
}
int calculate(char t[])
{
	int stack[M];
	int i,j=-1,len=strlen(t),d=0;
	for(i=0;i<len;)
	{
		if(isnum(t[i])==1)
		{
			for(;isnum(t[i])==1;i++)
				d=10*d+(t[i]-'0');
			stack[++j]=d;
			d=0;
		}
		else if(isnum(t[i])==2)
		{
			if(t[i]=='+')
			{
				stack[j-1]=stack[j-1]+stack[j];
				j--;
			}
			else if(t[i]=='-')
			{
				stack[j-1]=stack[j-1]-stack[j];
				j--;
			}
			else if(t[i]=='*')
			{
				stack[j-1]=stack[j-1]*stack[j];
				j--;
			}
			else if(t[i]=='/')
			{
				stack[j-1]=stack[j-1]/stack[j];
				j--;
			}
			i++;
		}
		else
			i++;
	}
	return stack[0];
}
int main()
{
	char s[M],t[M];
	int i,j,len;
	gets(s);
	len=strlen(s);
	for(i=j=0;i<len;i++)
	{
		if(s[i]!=' '&&s[i]!='=')
			s[j++]=s[i];
	}
	s[j]='\0';
	transfer(s,t);
	printf("%d",calculate(t));
	return 0 ;
}




