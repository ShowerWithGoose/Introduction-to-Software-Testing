#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

FILE* input;
typedef struct list {
	char word[100];
	int times;
	struct list* link;
} list;
char tem[100], p, q;
int f;
void printlist(list*head){
	list*p=head->link->link;
	while(p!=NULL){
		printf("%s %d\n",p->word,p->times);
		p=p->link;
	}
}
int main() {
	int i;
	list* head = (list*)malloc(sizeof(list));
	list* z = head;
	list* q = NULL;
	list* zz = NULL;
	head->times=0;
	head->link = (list*)malloc(sizeof(list));
	head->link->link=NULL;
	memset(head->word,0,sizeof(head->word));
	memset(head->link->word,0,sizeof(head->word));
	input = fopen("article.txt", "r");
	while ((p = fgetc(input)) != EOF) {

		while (p < 'A' || (p > 'Z' && p < 'a') || p > 'z') {
			if ((p = fgetc(input)) == EOF) {
				//for (zz = head; zz != NULL; zz = zz->link)
				printlist(head);
				
				return 0;
			}
		}
		ungetc(p, input);

		for (i = 0; (p >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z'); i++) {
			tem[i] = p = fgetc(input);
			tem[i] = tolower(tem[i]);
		}
		tem[i - 1] = '\0';

		f = 0;
		z = head->link;
		zz=head;
		
		while(z!=NULL){

			if(strcmp(z->word,tem)==0){
				z->times++;
				f=1;
				break;
			}
			if(strcmp(z->word,tem)>0){
				q=(list*)malloc(sizeof(list));
				q->link=z;
				q->times=1;
				zz->link=q;
				strcpy(q->word, tem);
				f=1;
				break;
			}
			zz=z;
			z=z->link;
		}
		
		if(f==0){
			q=(list*)malloc(sizeof(list));
			q->link=NULL;
			q->times=1;
			zz->link=q;
			strcpy(q->word, tem);
		}
		
/*		while (z != NULL) {
			if (strcmp(z->word, tem) == 0) {
				z->times++;
				//puts(z->word);
				f = 1;
				
			}
			zz = z;
			z = z->link;
		}
		
		if (f == 0) {
			q = (list*)malloc(sizeof(list));
			strcpy(q->word, tem);
			//puts(q->word);
			q->times = 1;
			zz->link = q;
			q->link = z;
		}

*/
	}


	return 0;
}



