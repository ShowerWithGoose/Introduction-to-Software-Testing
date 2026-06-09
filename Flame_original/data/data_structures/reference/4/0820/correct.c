#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct word{
	char s[30];
	int time;
	struct word *next;
}line={"",0,NULL};
int main(){
	FILE *in,*out;
	struct word *p,*q,*first,*front,*ex;
	char temp[30]="";
	int ob=0;
	first=&line;
	p=&line;
	q=&line;
	in=fopen("article.txt","r");
	while(fscanf(in,"%c",&temp[ob])!=EOF){
		if(isalpha(temp[ob])){
			if(isupper(temp[ob])){
				temp[ob]+=32;
			}
			ob++;
		}
		else {
			if(ob!=0){
				temp[ob]='\0';
				strcpy(p->s,temp);
				q=p;
				p->time=1;
				p->next=(struct word*)malloc(sizeof(struct word));
				p=p->next;
			}
			ob=0;
			memset(temp,'\0',sizeof(temp));
		}
		
	}
	if(ob!=0){
				strcpy(p->s,temp);
				q=p;
				p->time=1;
				p->next=(struct word*)malloc(sizeof(struct word));
				p=p->next;
			}
	p=first;
	q->next=NULL;
	ob=1;
	while(ob){
		ob=0;
		while(p->next!=NULL){
			if(strcmp(p->s,p->next->s)>0){
				ob=1;
				if(p==first){
					first=p->next;
					ex=p->next;
					p->next=p->next->next;
					ex->next=p;
					p=first;
				}
				else{
					ex=p->next;
					p->next=p->next->next;
					ex->next=p;
					front->next=ex;
					p=front;
				}
			}
			else if(strcmp(p->s,p->next->s)==0){
				ob=1;
				p->time+=p->next->time;
				p->next=p->next->next;
				p=front;
			}
			front=p;
			p=p->next;
		}
		p=first;
	}
	p=first;
	while(p->next!=NULL){
		printf("%s %d\n",p->s,p->time);
		p=p->next;
	}
	printf("%s %d\n",p->s,p->time);
	return 0;
} 

