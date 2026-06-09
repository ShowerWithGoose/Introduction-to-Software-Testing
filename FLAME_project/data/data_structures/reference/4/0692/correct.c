#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Word{
	char str[100];
	int dist;
	struct Word*next;
}word;
int main()
{
	FILE*in;char c,temp[100];int num=0,i;
	temp[0]='\0';
	in=fopen("article.txt","r");
	word*head=NULL;
	while(1)
	{
		c=fgetc(in);
		if(c==EOF)break;
		if(c>='A'&&c<='Z')c-=('A'-'a');
		if(c>='a'&&c<='z')
		{
			temp[num]=c;num++;temp[num]='\0';
		}
		else if(temp[0]>='a'&&temp[0]<='z')
		{
			word*cur=head,*last=NULL;
			for(;cur!=NULL;last=cur,cur=cur->next)
			{
				if(strncmp(cur->str,temp,100)==0)
				{
					cur->dist++;break;
				}
				else if(strncmp(cur->str,temp,100)>0)
				{
					word*p=(word*)malloc(sizeof(word));
					p->dist=1;strncpy(p->str,temp,100);
					if(last==NULL)
					{
						p->next=cur;head=p;
					}
					else
					{
						p->next=cur;last->next=p;
					}
					break;
				}
			}
			if(cur==NULL)
			{
				word*p=(word*)malloc(sizeof(word));
				p->dist=1;strncpy(p->str,temp,100);
				if(head==NULL)
				{
					head=p;head->next=NULL;
				}
				else 
				{
					last->next=p;p->next=NULL;
				}
			}
		for(i=0;i<num;i++)temp[i]='\0';num=0;		
		}
	}
	word*cur=head;
	for(;cur!=NULL;cur=cur->next)
	printf("%s %d\n",cur->str,cur->dist);
	fclose(in);
	return 0;
}

