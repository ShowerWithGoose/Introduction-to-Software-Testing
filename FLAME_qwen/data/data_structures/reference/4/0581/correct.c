#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

struct word{
	char word[20];
	int num;
	struct word *next;
}*h,*p,*q;

void save(char *ch)
{
	p=h;
	while(strcmp(ch,p->word)>0)
	{
	//	printf("11\n");
		if(p->next==NULL)
		{
			q=malloc(sizeof(struct word));
			q->num=1;
			strcpy(q->word,ch);
			p->next=q;
			q->next=NULL;
			p=q;
			return;
		}
		p=p->next;
	}
	if(strcmp(ch,p->word)==0)
	{
	//	printf("111\n");
		p->num++;
	}
	else
	{
	//	printf("1111\n");
		q=malloc(sizeof(struct word));
		q->next=p->next;
		p->next=q;
		strcpy(q->word,p->word);
		q->num=p->num;
		strcpy(p->word,ch);
		p->num=1;
	}
}


int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char ch[40];
	char c;
	int i;
	h=malloc(sizeof(struct word));
	strcpy(h->word,"@");
	h->num=0;
	h->next=NULL;
//	printf("1\n");
	while(c=fgetc(in))
	{
	//	printf("1");
	//	putchar(c); 
		for(i=0;;i++)
		{
			if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
			{
				ch[i]=tolower(c);
			}
			else/* if(c==' '||c=='\n'||c==EOF)*/
			{
				ch[i]='\0';
			//	puts(ch);
				save(ch);
				break;
			}
		//	else i--;
			c=fgetc(in);
		}
		if(c==EOF) break;
//		printf("1");
	}
	p=h->next->next;
	while(p->next!=NULL)
	{
		printf("%s %d\n",p->word,p->num);
		p=p->next;
	}
	printf("%s %d\n",p->word,p->num);
	return 0;
}

