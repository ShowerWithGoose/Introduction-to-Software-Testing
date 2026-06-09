#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char s[100];
struct list{
	char word[100];
	int num;
	struct list* next;
};
struct list* head=NULL;
int read(FILE* fp1,char *s)
{
	int i=0;
	char a;
	while((a=fgetc(fp1))!=EOF)
	{
		if(isalpha(a)!=0)
		{
			s[i]=tolower(a);
			i++;
		}
		else if(i>0)
		{
			s[i]='\0';
			return 0;
		}
	}
	return -1;
}
int insert(struct list* q,char *s)
{
	struct list* p;
	p=(struct list*)malloc(sizeof(struct list));
	if(p==NULL)
	return -1;
	strcpy(p->word,s);
	p->num=1;
	p->next=NULL;
	if(head==NULL)
	head=p;
	else if(q==NULL)
	{
		p->next=head;
		head=p;
	}
	else 
	{
		p->next=q->next;
		q->next=p;
	}
	
	return 0;
 } 
 int search(char *s)
 {
 	struct list*p,*q=NULL;
 	for(p=head;p!=NULL;q=p,p=p->next)
 	{
 		if(strcmp(s,p->word)<0)
 		{
 			break;
		 }
		 else if(strcmp(s,p->word)==0)
		 {
		 	p->num++;
		 	return 0;
		 }
	 }
	 return insert(q,s);
 }
int main()
{
	FILE *fp1=fopen("article.txt","r"); 
	 struct list* a;
	 while(read(fp1,s)!=EOF)
	 {
	 	search(s);
	 }
	 for(a=head;a!=NULL;a=a->next)
	 printf("%s %d\n",a->word,a->num);
	 	return 0;
}


