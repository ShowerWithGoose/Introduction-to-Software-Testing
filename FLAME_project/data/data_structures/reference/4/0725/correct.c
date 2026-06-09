#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define MAX 1024
char m[MAX],copy[MAX],w[MAX],zero[MAX];
struct dictionary {
	char word[MAX];
	int times;
	struct dictionary *next;
};
int main() {
	FILE *IN;
	int j=0,cnt=0,flag=0,z=0,k=0;
	IN=fopen("article.txt","r");
	struct dictionary *first,*p,*q,*t,*l,*end;
	first=(struct dictionary *)malloc(sizeof(struct dictionary));
	p=(struct dictionary *)malloc(sizeof(struct dictionary));
	end=(struct dictionary *)malloc(sizeof(struct dictionary));
	first->next=p;
	p->next=end;
	t=first;
	l=first;
	while(fgets(m,MAX-1,IN)!=NULL) {
		for(int i=0; i<strlen(m); i++) {
			if((m[i]>=65&&m[i]<=90)||(m[i]>=97&&m[i]<=122)) {
				if(m[i]>='A'&&m[i]<='Z') {
					m[i]=m[i]+32;
				}
				copy[j]=m[i];
				flag=1;
				j++;
			}
			if(flag==1&&(m[i]>122||m[i]<97)) {
				cnt++;
				flag=0;
				if(cnt>1) {
					if(strcmp(t->next->word,copy)>0) {
						q=(struct dictionary *)malloc(sizeof(struct dictionary));
						q->next=t->next;
						t->next=q;
						for(z=0; z<strlen(copy); z++) {
							q->word[z]=copy[z];
						}
						q->word[z]='\0';
						q->times=1;
					}
				    else if(strcmp(t->next->word,copy)==0) {
						t->next->times=t->next->times+1;
					}
					else if(strcmp(t->next->word,copy)<0) {
						while(strcmp(t->next->word,copy)<0) {
							t=t->next;
							if(t->next==end) {
								q=(struct dictionary *)malloc(sizeof(struct dictionary));
								q->next=t->next;
								t->next=q;
								for(z=0; z<strlen(copy); z++) {
									q->word[z]=copy[z];
								}
								q->times=1;
								q->word[z]='\0';

							} else if(strcmp(t->next->word,copy)==0) {
								t->next->times=t->next->times+1;
								break;
							} else if(strcmp(t->next->word,copy)>0) {
								q=(struct dictionary *)malloc(sizeof(struct dictionary));
								q->next=t->next;
								t->next=q;
								for(z=0; z<strlen(copy); z++) {
									q->word[z]=copy[z];
								}
								q->times=1;
								q->word[z]='\0';
								break;
							} 
						}

					}
					memset(copy,'\0',sizeof(copy));
					j=0;
					t=first;
				} else {
					for(k=0; k<strlen(copy); k++) {
						p->word[k]=copy[k];
					}
					p->word[k]='\0'; 
					p->times=1;
					memset(copy,'\0',sizeof(copy));
					j=0;
					t=first;
				}
			}
		}
	} 
	while(l->next!=end) {
		for(int i=0; i<strlen(l->next->word); i++) {
			printf("%c",l->next->word[i]);
		}
		printf(" ");
		printf("%d\n",l->next->times);
		l=l->next;
	}
	free(p); 
	return 0;
}



