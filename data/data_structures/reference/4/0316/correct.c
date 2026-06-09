#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define tolower(c) (c>='A'&&c<='Z'?'a'-'A'+c:c) 
struct dic{
	char word[50];
	int count;
	struct dic *next;
};
struct dic *first=NULL;
int input(struct dic *op1,char *op){
	struct dic *r;
	r=(struct dic *)malloc(sizeof(struct dic));
	strcpy(r->word,op);
	r->count=1;
	r->next=NULL;
	if(first==NULL)
	{
		first=r;
	 } 
	 else if(op1==NULL)//传进来的东西字典序靠前 
	{
		r->next=first;
		first=r;//在前面插入； 
	}
	if(first!=NULL&&op1!=NULL)//传进来的东西字典序靠后； 
	{
	r->next=op1->next;
	op1->next=r;
	}
	
	return 0;		
}
int search(char *op){
	struct dic *z=NULL,*y=NULL;
	for(z=first;z!=NULL;y=z,z=z->next)
	{
		if(strcmp(z->word,op)==0)
		{
			z->count++;
			return 0;
		}
		else if(strcmp(z->word,op)>0)//传进来的东西字典序靠前，向前插入 
		break;
	}
	return input(y,op);
}
int getword(FILE*gaoshi,char word[]){
	int i=0;
	char s;
	while((s=fgetc(gaoshi))!=EOF)
	{
		if((s>='a'&&s<'z')||(s>='A'&&s<='Z'))
		{
			s=tolower(s);
			word[i++]=s;
		}
		else if(i>0)
		{
			word[i]='\0';
			return 0;
		}
	}
	return EOF;
} 
int main()
{
	char word[50];
	struct dic *p=NULL;
	FILE *in;
	in=fopen("article.txt","r");
	while(getword(in,word)!=EOF)
	{
		search(word);
		
	}
	for(p=first;p!=NULL;p=p->next)
	printf("%s %d\n",p->word,p->count);
	return 0;
}

