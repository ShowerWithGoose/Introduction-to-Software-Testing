#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define tolower(c)  (c>='A'&&c<='Z'?'a'-'A'+c:c)
struct node{
	char word[20];
	int cnt;
	struct node *next;
};
struct node *p,*q,*head,*p0;
void count(char word[])
{
	for(p=head->next;p!=NULL;p=p->next)
	{
		if(strcmp(p->word,word)==0)
		{
			p->cnt++;
			return;
		}
	}
	p0=(struct node*)malloc(sizeof(struct node));
	strcpy(p0->word,word);
	p0->cnt=1;
	for(q=head,p=head->next;p!=NULL;q=p,p=p->next)
	{
		if(strcmp(p0->word,p->word)<0)
		{
			p0->next=p;
			q->next=p0;
			return;
		}
	}
	p0->next=NULL;
	q->next=p0;
	return;
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char line[100],word[20];
	int i,j;
	p=head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	while(fgets(line,100,in)!=NULL)
	{
		for(i=0;line[i]!='\0';i++)
		{
			if(isalpha(line[i]))
			{
				for(j=0;isalpha(line[i]);i++)
					word[j++]=tolower(line[i]);
				word[j]='\0';
				count(word);
			}
		}
	}
	for(p=head->next;p!=NULL;p=p->next)
		printf("%s %d\n",p->word,p->cnt);
	for(p=head;p!=NULL;)
	{
		head=p->next;
		free(p);
		p=head;
	}
	fclose(in);
	return 0;
}

