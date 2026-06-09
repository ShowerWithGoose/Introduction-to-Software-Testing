#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
	char data[30];
	int cnt;
	struct Node* link;
} LNode,*Linklist;
int main(){
	FILE *x;
	char ch,al[30];
	int i=0,tmp,flag=0;
	Linklist list=NULL,p,q,r;
	x=fopen("article.txt","r");
	ch=fgetc(x);
	while(ch!=EOF){
		if(ch>='a'&&ch<='z'){
			al[i++]=ch;
			flag=1;
		}
		else if(ch>='A'&&ch<='Z'){
			al[i++]=ch-'A'+'a';
			flag=1;
		}
		else if(~(isalpha(ch))&&flag==1){
			al[i]='\0'; 
			p=(LNode*)malloc(sizeof(LNode));
			strcpy(p->data,al);
			p->cnt=1;
			if(list==NULL){
				list=p;
			}
			else{
				q->link=p;
			}
			q=p;
			flag=0;
			i=0;
		}
		ch=fgetc(x);
	}
	q->link=NULL;
	p=list;
	while(p!=NULL){
		r=p;
		q=p->link;
		while(q!=NULL){
			if(strcmp(p->data,q->data)==0){
				p->cnt+=q->cnt;
				r->link=q->link;
				q=r->link;
			}
			else{
				r=r->link;
				q=q->link;
			}
		}
		p=p->link;
	}
	p=list;
	while(p!=NULL){
		q=p->link;
		while(q!=NULL){
			if(strcmp(p->data,q->data)>0){
				tmp=p->cnt;
				p->cnt=q->cnt;
				q->cnt=tmp;
				strcpy(al,p->data);
				strcpy(p->data,q->data);
				strcpy(q->data,al);
			}
			q=q->link;
		}
		p=p->link;
	}
	p=list;
	while(p->link!=NULL){
		printf("%s %d\n",p->data,p->cnt);
		q=p->link;
		free(p);
		p=q;
	}
	printf("%s %d\n",p->data,p->cnt);
	free(p);
	fclose(x);
	return 0;
}

