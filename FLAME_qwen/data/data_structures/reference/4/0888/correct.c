#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
typedef struct word{
	char c[50];
	int x;
	struct word *link;
}node,*nodeptr;
int main(){
	FILE *p1;
	int n=1,i,j;
	nodeptr p,q,head,now;
	char c[50];
	p1=fopen("article.txt","r");
	again:;
	for(i=0;;i++){
		c[i]=fgetc(p1);
		if(i==0&&isalpha(c[i])==0)
			i--;
		else if(i!=0&&isalpha(c[i])==0){
			c[i]=0;
			break;
		}else{
			c[i]=tolower(c[i]);
		}
	}
	if(strlen(c)==0)
		goto again;
	p=(nodeptr)malloc(sizeof(node));
	strcpy(p->c,c);
	head=p;
	head->x=1;
	head->link=NULL;
	while(1){
		for(i=0;;i++){
			c[i]=fgetc(p1);
			if(c[i]==EOF){
				goto out;
			}
			if(i==0&&isalpha(c[i])==0)
				i--;
			else if(i!=0&&isalpha(c[i])==0){
				c[i]=0;
				break;
			}else{
				c[i]=tolower(c[i]);
			}
		}
		if(strlen(c)==0)
			continue;
		now=head;
		if(strcmp(c,now->c)<0){
			q=(nodeptr)malloc(sizeof(node));
			q->x=1;
			strcpy(q->c,c);
			q->link=head;
			head=q;
			n++;
		}
		else{
			for(i=1;i<=n;i++){
				if(i!=n){
					if(strcmp(c,now->c)>0&&strcmp(c,now->link->c)<0)
						break;
					else if(strcmp(c,now->c)==0){
						now->x++;
						goto next;
					}
					now=now->link;
				}else if(strcmp(c,now->c)==0){
						now->x++;
						goto next;
					}
			}
			q=(nodeptr)malloc(sizeof(node));
			q->x=1;
			strcpy(q->c,c);
			if(i==n){
				n++;
				now->link=q;
				q->link=NULL;
			}
			else{
				n++;
				q->link=now->link;
				now->link=q;
			}
		}
		next:;
	}
	out:p=head;
	while(p->link!=NULL){
		printf("%s %d\n",p->c,p->x);
		p=p->link;
	}
	printf("%s %d\n",p->c,p->x);
	return 0;
}


