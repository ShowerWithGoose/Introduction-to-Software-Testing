#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
struct word{
	char a[20];
	int b;
	struct word *next;
}*head,*q,*p,*t;

int main(){
	head=NULL;
	FILE *in;
	in=fopen("article.txt","r");
	char s[1024],c[20];
	int lenth,i,j,k;
	while(fgets(s,1023,in)!=NULL){
		lenth=strlen(s);
		for(i=0,j=0;i<lenth;i++){
			if(s[i]>='A'&&s[i]<='Z'){
				c[j++]=s[i]-'A'+'a';
			}
			else if(s[i]>='a'&&s[i]<='z'){
				c[j++]=s[i];
			}
			else if(j!=0){
				c[j]='\0';
				if(head!=NULL){
					p=head->next;
					q=head;
					while(p!=NULL){
						if(strcmp(q->a,c)==0){
							q->b++;
						}
						else if(strcmp(q->a,c)<0&&strcmp(p->a,c)>0){
							t=(struct word*)malloc(sizeof(struct word));
							q->next=t;
							q=t;
							q->next=p;
							strcpy(q->a,c);
							q->b=1;
						}
						else if(strcmp(q->a,c)>0&&q==head){
							t=(struct word*)malloc(sizeof(struct word));
							t->next=head;
							q=head=t;
							p=t->next;
							strcpy(q->a,c);
							q->b=1;
						}
						q=p;
						p=p->next;
					}
					if(strcmp(q->a,c)==0&&p==NULL){
						q->b++;
					}
					else if(strcmp(q->a,c)<0&&p==NULL){
						p=(struct word*)malloc(sizeof(struct word));
						strcpy(p->a,c);
				    	p->b=1;
				    	p->next=NULL;
				    	q->next=p;
					}
					else if(strcmp(q->a,c)>0&&q==head){
						t=(struct word*)malloc(sizeof(struct word));
						t->next=head;
						q=head=t;
						p=t->next;
						strcpy(q->a,c);
						q->b=1;
					}
				}
				else{
					p=(struct word*)malloc(sizeof(struct word));
					strcpy(p->a,c);
					p->b=1;
					p->next=NULL;
					head=p;
					q=p;
				}
				j=0;
			}
		}
	}
	p=head;
	while(p!=NULL){
		printf("%s %d\n",p->a,p->b);
		p=p->next;
	}
	fclose(in);
	
	return 0;
}



