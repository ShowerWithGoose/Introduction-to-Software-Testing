#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct words{
	char word[100];
	int time;
	struct words *next;
}; 
int judge(char ch)
{
	if(ch>='a'&&ch<='z')
	return 1;
	else if(ch>='A'&&ch<='Z')
	return 2;
	else return 0;
}
typedef struct words *Nodeptr;
typedef struct words Node;
Nodeptr add(Nodeptr head,char s[]); 
int main()
{
	FILE*in;
	in=fopen("article.txt","r");
	int k=0;
	char s[100],ch;
	Nodeptr head,pre; 
	head=(Nodeptr)malloc(sizeof(Node));
	head->next=NULL;
	do{
		while(1){
			if(judge(ch)==1) s[k++]=ch;
			else if(judge(ch)==2) s[k++]=ch+'a'-'A';
			else{
				s[k]='\0';
				break;
			}
			fscanf(in,"%c",&ch);
		}
		if(k!=0){
			k=0;
			head=add(head,s); 
		}
	}while(fscanf(in,"%c",&ch)!=EOF);
	pre=head->next;
	while(pre!=NULL){
		printf("%s %d\n",pre->word,pre->time);
		head=pre;
		pre=pre->next;
		free(head);
	}
	 
}
Nodeptr add(Nodeptr head,char s[])
{
	Nodeptr p,q,r;
	r=(Nodeptr)malloc(sizeof(Node));
	r->next=NULL;
	r->time=1;
	strcpy(r->word,s);
	if(head->next==NULL){
		head->next=r;
		return head;
	}
	else{
		for(p=head->next,q=head;p!=NULL&&strcmp(p->word,s)<0;q=p,p=p->next);
		if(p==NULL){
			q->next=r;
			r->next=p;
		}
		else if(strcmp(p->word,s)==0)
		p->time++;
		else{
			q->next=r;
			r->next=p;
		}
		return head;
	}
}



