#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define tolower(c) (c>='A'&&c<='Z'?c+'a'-'A':c)

typedef struct word{
	char s[15];
	int num;
	struct word *link;
}LNode,*LinkList;

void ADD(char s[]);
void print();

FILE *in;
LinkList list=NULL;

int main(){
	int i,j;
	char line[1025],s[15];
	LinkList p=NULL;
	in=fopen("article.txt","r");
	while(fgets(line,1024,in)!=NULL){
		i=0;
		while(1){
			j=0;
			while((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z')){
				s[j]=tolower(line[i]);
				i++,j++;
			}
			s[j]='\0';
			if(j)
				ADD(s);
			if(line[i]=='\0')
				break;
			i++;
		}
	}
	print();
	return 0;
}

void print(){
	LinkList p=list;
	while(p!=NULL){
		printf("%s %d\n",p->s,p->num);
		p=p->link;
	}
}

void ADD(char s[]){
	LinkList p=list,r=list,creat;
	int check;
	if(list==NULL){
		list=(LinkList)malloc(sizeof(LNode));
		strcpy(list->s,s);
		list->num=1;
		list->link=NULL;
		return;
	}
	while((p->link!=NULL)&&(strcmp(p->s,s)<0)){
		r=p;
		p=p->link;
	}
	check=strcmp(p->s,s);
	if(check==0){//相等
		(p->num)++;
	}else if(check>0){//s小
		creat=(LinkList)malloc(sizeof(LNode));
		if(r==p)
			list=creat;
		else
			r->link=creat;
		strcpy(creat->s,s);
		creat->num=1;
		creat->link=p;
	}else if(check<0){//s大
		creat=(LinkList)malloc(sizeof(LNode));
		if(p->link==NULL){
			p->link=creat;
			creat->link=NULL;
		}else{
			r->link=creat;
			creat->link=p;
		}
		creat->num=1;
		strcpy(creat->s,s);
	}
}






