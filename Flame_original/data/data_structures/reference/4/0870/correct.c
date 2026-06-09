#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct table{
	char words[64];
	int times;
	struct table* link;
}tab,*star;
star init(){
	star temp=(star)malloc(sizeof(tab));
	temp->link=NULL;
	return temp;
}
void fre(star head){
	star p=head,temp;
	while(p!=NULL)
	{
		temp=p->link;
		free(p);
		p=temp;
	}
}
void attach(star a,star head)
{
	star f=head->link;
	a->link=f;
	head->link=a;
}
void insert(star head,char word[]){
	star p=head->link;
	while(p!=NULL)
	{
		if(!strcmp(p->words,word))
		{
			(p->times)++;
			return ;
		}
		p=p->link;
	}
	star q=(star)malloc(sizeof(tab));
	q->times=1;
	strcpy(q->words,word);
	p=head;
	star e=p->link;
	if(e==NULL)attach(q,head);
	else if(strcmp(e->words,word)>0)attach(q,head);
	else if(strcmp(e->words,word)<0&&e->link==NULL)attach(q,e);
	else {
		p=head->link;
		e=p->link;
		while(e!=NULL)
		{
			
			if(strcmp(p->words,word)<0&&strcmp(e->words,word)>0)
			{
				attach(q,p);
				return;
			}
			p=p->link;e=e->link;
		}
		if(e==NULL)attach(q,p);return;
		}
		
	}

void print(star head)
{
	star p=head;
	while((p=p->link)!=NULL)
		printf("%s %d\n",p->words,p->times);
}
int main()
{
	star head=init();
	FILE *in;in=fopen("article.txt","r");
	char hang[256];
	int i,j,k=0,s;
	while(fgets(hang,255,in))
	{
		char word[64]={0};
		for(i=0;;)
		{
			
			j=0;
			while(isalpha(hang[i]))
			{
				word[j++]=hang[i];i++;k=1;
			}
			if(k==1)
			{
				for(s=0;word[s]!='\0';s++)word[s]=tolower(word[s]);
				insert(head,word);
				memset(word,0,64*sizeof(char));k=0;
			}
			while(!isalpha(hang[i]))
			{
				i++;if(hang[i]==0)goto next;
			}
		}
		next:;
	}
	print(head);
	fre(head);
	fclose(in);
	return 0;
}

