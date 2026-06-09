#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

struct node {
	char *a;
	int n;
	struct node* lik;
};

typedef struct node* Nodeptr;
typedef struct node Node;

char tolow(char a);

int main() {
	FILE* in;
	Nodeptr v, p, q, head;
	head = NULL;
	int i, j;
	i = j = 0;
	char hc[200] = {'\0'},zm[20] = {'\0'};
	in = fopen("article.txt","r");
	while (fgets(hc,200,in)!=NULL) {
		for (;hc[i]!='\0';i++) {
			if ((hc[i]<='z'&&hc[i]>='a')||(hc[i]<='Z'&&hc[i]>='A')) {
				zm[j]=tolow(hc[i]);
				j++;
			}
			else if (j>0&&((hc[i]<'A')||(hc[i]>'Z'&&hc[i]<'a')||(hc[i]>'z'))){
				p=(Nodeptr)malloc(sizeof(Node));
				p->a=(char*)malloc(strlen(zm)-1);
				strcpy(p->a,zm);
				memset(zm,'\0',20);
				j=0;
				p->n=1;
				p->lik=NULL;
				if(head==NULL){
					head = v = q = p;
				}
				else{
					for(q=head;q!=NULL;q=q->lik){
						if(strcmp(q->a,p->a)==0){
							q->n++;
							free(p);
							q=v;
							break;
						} 
					}
					if(q==NULL){
						for(q=head;q->lik!=NULL;q=q->lik){
							if(strcmp(q->a,p->a)>0){
								p->lik=head;
								head=p;
								break;
							}
							else if(strcmp(q->a,p->a)<0&&strcmp((q->lik)->a,p->a)>0){
								p->lik=q->lik;
								q->lik=p; 
								break;
							}
						}
						if(q->lik==NULL){
							q->lik=p;
						}
						q=v=p;
					}
				}
			}
		}
		memset(hc,'\0',200);
		i=0;
	}
	for(q=head;q!=NULL;q=q->lik){
		printf("%s %d\n",q->a,q->n);
	}
	return 0;
}

char tolow(char a) {
	if (a>='A'&&a<='Z') {
		return a + 32;
	} else {
		return a;
	}
}

