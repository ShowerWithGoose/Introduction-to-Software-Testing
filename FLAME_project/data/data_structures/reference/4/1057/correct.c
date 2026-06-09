#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAXN 30
#define MAXBUF 1009
#define mst(s) memset(s,0,sizeof(s))
typedef struct node {
	char word[MAXN];
	int num;
	struct node *next;
} linklist;
char buf[MAXBUF];

int main(void)
{
	int i,j,flag=0,len=0;
	linklist *head,*last,*current;
	char newWord[MAXN];
	FILE *in=fopen("article.txt","r");
	head=(linklist *)malloc(sizeof(linklist));
	current=head;
	current->next=NULL;
	while(fgets(buf,MAXBUF,in)!=NULL) {
		//printf("%s",buf);
		/*for(i=0;buf[i];i++){
			if(!isalpha(buf[i])){
				buf[i]=' ';
			}else;
		}*/
		for(i=0; buf[i]!='\0'; i++) {
			if(!isalpha(buf[i])) {
				if(flag){
					newWord[len++]='\0';
					for(current=head->next,last=head; current!=NULL&&strcmp(newWord,current->word)>0; current=current->next,last=last->next);
						if(current&&strcmp(newWord,current->word)==0) {
							current->num++;
						} else {
							linklist *p=(linklist *)malloc(sizeof(linklist));
							p->next=current;
							p->num=1;
							for(j=0; newWord[j]; j++) {
								p->word[j]=newWord[j];
							}
							p->word[j]='\0';
							last->next=p;
						}
						//printf("%s\n",newWord);
					mst(newWord);
					flag=0;
					len=0;
				}else;
			} else {
				buf[i]=islower(buf[i])?buf[i]:buf[i]-'A'+'a';
				if(flag==0) flag=1;else;
				if(flag){
					newWord[len++]=buf[i];
				}else;
			}
		}
	}
	if(flag&&buf[i]=='\0'){
		for(current=head->next,last=head; current!=NULL&&strcmp(newWord,current->word)>0; current=current->next,last=last->next);
			if(current&&strcmp(newWord,current->word)==0) {
				current->num++;
			} else {
				linklist *p=(linklist *)malloc(sizeof(linklist));
				p->next=current;
				p->num=1;
				for(j=0; newWord[j]; j++) {
					p->word[j]=newWord[j];
				}
				p->word[j]='\0';
				last->next=p;
			}
			mst(newWord);
			flag=0;
			len=0;
	}else;
	for(current=head->next; current; current=current->next) {
		if(current->word[0]) {
			printf("%s %d\n",current->word,current->num);
		}
	}
	for(current=head->next,last=head; current; last=current,current=current->next) {
		free(last);
	}
	free(last);
	fclose(in);

	return 0;
}





