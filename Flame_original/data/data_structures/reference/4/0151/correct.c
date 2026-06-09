#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct collect {
	char ch[35];
	int t;
	struct collect *next;
};

typedef struct collect word,*worp;

worp list=NULL,p,q,r;
FILE *fp;




int main() {
	char a[35]= {'\0'},c;
	int i=0;

	fp=fopen("article.txt","r");

	while(1) {
		c=fgetc(fp);
		if(c==EOF) break;
		c=tolower(c);
		if((c<'a'||c>'z')) {
			if(a[0]=='\0') {
				continue;
			} else {
				if(list==NULL) {
					p=(worp)malloc(sizeof(word));
					p->next=NULL;
					p->t=1;
					strcpy(p->ch,a);
					list=p;
					i=0;
				for(int j=0; a[j]!='\0'; j++) {
					a[j]='\0';
				}
				continue;
				}


				if(strcmp(list->ch,a)>0) {
					r=(worp)malloc(sizeof(word));
					r->next=NULL;
					r->t=1;
					strcpy(r->ch,a);
					r->next=list;
					list=r;
					i=0;
				for(int j=0; a[j]!='\0'; j++) {
					a[j]='\0';
				}
				continue;
				}

				for(p=list; p!=NULL; q=p,p=p->next) {
					if(strcmp(p->ch,a)==0) {
						p->t++;
						break;
					}
					if(strcmp(p->ch,a)<0&&p->next!=NULL) continue;
					if(strcmp(p->ch,a)>0) {
						r=(worp)malloc(sizeof(word));
						r->next=NULL;
						r->t=1;
						strcpy(r->ch,a);
						r->next=p;
						q->next=r;
						q=r;
						break;
					}
					if(strcmp(p->ch,a)<0&&p->next==NULL) {
						r=(worp)malloc(sizeof(word));
						r->next=NULL;
						r->t=1;
						strcpy(r->ch,a);
						p->next=r;
						break;
					}
				}
				i=0;
				for(int j=0; a[j]!='\0'; j++) {
					a[j]='\0';
				}
				continue;
			}
		} else {
			a[i]=c;
			i++;
		}
	}

	for(p=list; p!=NULL; p=p->next) {
		printf("%s %d\n",p->ch,p->t);
	}

	fclose(fp);

	return 0;
}



