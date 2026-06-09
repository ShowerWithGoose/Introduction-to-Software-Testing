#include<stdio.h>
#include<malloc.h>

struct node{
	int an;
	int en;
	struct node* next;
};
typedef struct node Node;
typedef struct node *Nodeptr;

int main(){
	Nodeptr H1,H2,H3,wk1,wk2,wk3,wk4,q;
	char c;
	
	H1 = H2 = H3 = NULL;
	do{
		q = malloc(sizeof(Node));
		scanf("%d %d%c",&q->an,&q->en,&c);
		if(H1 == NULL){
			H1 = q;
		}else{
			wk1->next = q;
		}
		wk1 = q;
	}while(c != '\n');
		wk1->next = NULL;
	
	do{
		q = malloc(sizeof(Node));
		scanf("%d %d%c",&q->an,&q->en,&c);
		if(H2 == NULL){
			H2 = q;
		}else{
			wk1->next = q;
		}
		wk1 = q;
	}while(c != '\n');
		wk1->next = NULL;
	for(wk1 = H1;wk1!= NULL;wk1=wk1->next){
		for(wk2 = H2;wk2 != NULL;wk2=wk2->next){
			q = malloc(sizeof(Node));
			q->an = wk1->an * wk2->an;
			q->en = wk1->en + wk2->en;
			
			if(H3 == NULL){
				H3 = q;
				q->next = NULL;
			}else{
				for(wk3 = H3;wk3!=NULL && q->en <= wk3->en;wk4 = wk3,wk3 = wk3->next ){}
				if(wk3 == H3){
					H3 = q;
				}else if(wk4->en == q->en){
					wk4->an += q->an;
				}else{
					q->next = wk3;
					wk4->next = q;
				}
			}
		}
	}
	for(wk1 = H3;wk1 != NULL;wk1 = wk1->next){
		printf("%d %d ",wk1->an,wk1->en);
	}
	
	return 0;	
}
