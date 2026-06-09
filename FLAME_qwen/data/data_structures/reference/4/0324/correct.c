#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i,j,k;
int N=0;
struct word{
	char s[100];
	int n;
	struct word *next;
};

char transf(char s){
	if(s>='A'&&s<='Z')
		s=s-'A'+'a';
	return s;	
}

int main(){
	FILE *in;
	in=fopen("article.txt","r");
	int n;
	struct word* head=(struct word*)malloc(sizeof(struct word));
	head->next=NULL;
	head->s[0]='\0';
	struct word* p;
	p=head;
	char c=' ';
	for(i=0;c!=-1;i++){		
		c=transf(fgetc(in));
		struct word* q=(struct word*)malloc(sizeof(struct word));
		q->n=0;
		for(j=0;(c>='A'&&c<='Z')||(c>='a'&&c<='z');j++){
			q->s[j]=c;
			c=transf(fgetc(in));
			q->n=1;
		}
		q->s[j]='\0';
		if(q->n==1){
			p=head;
			while(1){
				if(strcmp(p->s,q->s)==0){
					p->n++;
					break;
				}
				else if(p->next==NULL){
					p->next=q;
					q->next=NULL;
					break;
				}
				else if(strcmp(p->next->s,q->s)>0&&strcmp(p->s,q->s)<0){
					q->next=p->next;
					p->next=q;
					break;
				}				
				p=p->next;	
			}
		}
	}
	p=head->next;
	while(p!=NULL){
		printf("%s %d\n",p->s,p->n);
		p=p->next;
	}
	return 0;
}

