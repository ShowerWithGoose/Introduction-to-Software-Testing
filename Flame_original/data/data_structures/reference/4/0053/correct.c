#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct word{
	char w[200];
	int n;
	struct word *link;
};
char s1[200];
FILE *in;
int readw(char *s){
	int i=0;
	char c;
	while(isalpha(c=fgetc(in))){
		*s=tolower(c);
		s++;
		i++;
	}
	if(c==EOF){
		return 0;
	}
	if(i==0){
		readw(s);
	}
	return 1;
}
int main(){
	int i,j;
	struct word *first,*p,*q,*t;
	first=(struct word*)malloc((sizeof(struct word)));
	first->link=NULL;
	in=fopen("article.txt","r");
	char *s;
	s=s1;
	readw(s);
	memcpy(first->w,s1,strlen(s1)+1);
	first->n=1;
	memset(s1,0,200);
	while(readw(s)){
		p=first;
		if(strcmp(s1,first->w)<0){
			first=(struct word*)malloc((sizeof(struct word)));
			memcpy(first->w,s1,strlen(s1)+1);
			first->link=p;
			first->n=1;
		}else if(strcmp(s1,first->w)==0){
			first->n++;
		}else{
			while(1){
				if(p->link!=NULL&&strcmp(s1,(p->link)->w)>0){
					p=p->link;
				}else if(p->link!=NULL&&strcmp(s1,(p->link)->w)==0){
					(p->link)->n++;
					break;
				}else if(p->link==NULL){
					q=(struct word*)malloc((sizeof(struct word)));
					q->link=NULL;
					p->link=q;
					q->n=1;
					memcpy(q->w,s1,strlen(s1)+1);
					break;
				}else if(strcmp(s1,(p->link)->w)<0){
					q=(struct word*)malloc((sizeof(struct word)));
					q->link=p->link;
					p->link=q;
					q->n=1;
					memcpy(q->w,s1,strlen(s1)+1);
					break;
				}
			}
		}
		memset(s1,0,200);
	}
	while(p!=NULL){
		printf("%s %d\n",p->w,p->n);
		q=p;
		p=p->link;
		free(q);
	}
	fclose(in);
	return 0;
}

