#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Word {
	char key[100];
	int count;
	struct Word* link;
} word;

typedef struct Word* pword;

void insert(char [],pword*);
void reorder(pword);

int main() {
	FILE*in;
	in=fopen("article.txt","r");
	if(in==NULL) {
		printf("error\n");
		return 0;
	}
	pword p=(pword)malloc(sizeof(word));
	pword last,t;
	p->link=NULL;
	last=p;
	int i=0,flag=1,flag1;
	char s,s0[100]= {0};
	while(fscanf(in,"%c",&s)!=EOF) {
		if(flag==1){
			if(s>='A'&&s<='Z'){
				;
			}
			else if(s>='a'&&s<='z'){
				;
			}
			else{
				continue;
			}
		}
		flag=0;
		if(s>='A'&&s<='Z') {
			s0[i]=s-'A'+'a';
			i++;
		} else if(s>='a'&&s<='z') {
			s0[i]=s;
			i++;
		} else {
			i=0;
			flag=1;
		}
		if(flag==1) {
			flag1=0;
			for(t=p; t!=NULL; t=t->link) {
				if(strcmp(t->key,s0)==0) {
					t->count++;
					flag1=1;
					memset(s0,0,sizeof(s0));
					break;
				}
			}
			if(flag1==0) {
				insert(s0,&last);
				memset(s0,0,sizeof(s0));
			}
		}

	}
	reorder(p);
	reorder(p); 
	t=p;
	p=p->link;
	free(t);
	for(; p!=NULL; p=p->link) {
		printf("%s %d\n",p->key,p->count);
	}
	fclose(in);
	return 0;
}

void insert(char s[],pword* last) {
	pword p=(pword)malloc(sizeof(word));
	p->count=1;
	memset(p->key,0,sizeof(p->key));
	strcpy(p->key,s);
	p->link=(*last)->link;
	(*last)->link=p;
	(*last)=p;
}

void reorder(pword p) {
	pword fq,t0,t1,t2,t3;
	for(fq=p; fq!=NULL; fq=fq->link) {
		for(t0=p,t1=p->link,t2=(p->link)->link; t2!=NULL; t0=t0->link,t1=t1->link,t2=t2->link) {
			if(strcmp(t1->key,t2->key)>0) {
				t3=t1;
				t0->link=t2;
				t1->link=t2->link;
				t2->link=t3;
				t3=t1;
				t1=t2;
				t2=t3;
			}
		}
	}
}



