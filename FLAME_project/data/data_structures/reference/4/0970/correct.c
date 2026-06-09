#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	
	typedef struct node{
		char s[20+3];
		int count;
		struct node *link;
	}list;
	
	typedef struct node2{
		char s[20+3];
		int count,judge;
	}output;
	
	list *head=NULL,*p,*r;
	char str[20+3];
	int c,i=0,count=0,j;
	
	while((c=fgetc(in))!=EOF)//读入 
	{
		if(isalpha(c))//读字母 
		{
			if(isupper(c))//大写字母
				str[i++]=tolower(c);
			else
				str[i++]=c;
		} 
		else//读完一个单词
		{
			if(i==0)
				continue;
			str[i]='\0';
			p=(list*)malloc(sizeof(list));//创建一个结点存数据 
			strcpy(p->s,str);
			p->count=1;
			if(head==NULL)
			{
				head=p;
			}
			else
				r->link=p;
			r=p;
			i=0;
		}
	}
	list *end=(list*)malloc(sizeof(list));
	r->link=end;
	end->link=NULL;
	fclose(in);
	
	for(p=head;p!=end;p=p->link)//词频统计 
	{
		for(r=p->link;r!=end;r=r->link)
		{
			if(strcmp(p->s,r->s)==0)
			{
				p->count=p->count+r->count;
				r->count=0;
			}
		}
	}
	
	output out[1000];
	for(p=head;p!=end;p=p->link)
	{
		if(p->count!=0)
		{
			strcpy(out[count].s,p->s);
			out[count].count=p->count;
			out[count].judge=1;
			count++;
		}
	}
	for(i=0;i<count;i++)//冒泡排序 
	{
		int flag=0;
		for(j=0;j<count-1;j++)
		{
			if(strcmp(out[j].s,out[j+1].s)>0)
			{
				output temp;
				temp=out[j+1];
				out[j+1]=out[j];
				out[j]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
	for(i=0;i<count;i++)
	{
		printf("%s %d\n",out[i].s,out[i].count);
	}
	free(head);
	return 0;
}

