#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct node {
	int a;
	int x;
	struct node *next;
};
void insert(struct node **result,int A,int X) {
	struct node *tmp=(struct node*)malloc(sizeof(struct node));

	tmp->a=A;
	tmp->x=X;
	tmp->next=NULL;
	struct node *current=*result,*prev=NULL;
	if(*result==NULL) {
		
		*result=tmp;
		current=tmp;
	} else {

		while(current->x>X) {
			prev=current;
			current=current->next;
			if(current==NULL)break;
		}
	
		if(current!=NULL&&current->x==X) {
			current->a+=A;
			free(tmp);
		} else {
			tmp->next=current;
			if(prev==NULL) {
				*result=tmp;
			} else {
				prev->next=tmp;
			}
		}
	}

}
void Free(struct node *poly) {
	struct node *current=poly,*temp;
	while(current!=NULL) {
		temp=current;
		current=current->next;
		free(temp);
	}
}
int main() {
	int A,X;
	struct node *list1=NULL;
	struct node *list2=NULL;
	struct node *tail1=NULL;
	struct node *tail2=NULL;
	int len1=0,len2=0;
	while((scanf("%d %d",&A,&X))!=EOF) {
		struct node *tmp=(struct node*)malloc(sizeof(struct node));
		tmp->next=NULL;
		tmp->a=A;
		tmp->x=X;
		if(list1==NULL) {
			list1=tmp;
			tail1=tmp;
		} else {
			tail1->next=tmp;
			tail1=tmp;
		}
		len1++;
		if(getchar()=='\n')break;
	}
	while((scanf("%d %d",&A,&X))!=EOF) {
		struct node *tmp=(struct node*)malloc(sizeof(struct node));
		tmp->next=NULL;
		tmp->a=A;
		tmp->x=X;
		if(list2==NULL) {
			list2=tmp;
			tail2=tmp;
		} else {
			tail2->next=tmp;
			tail2=tmp;
		}
		len2++;
		if(getchar()=='\n')break;
	}
	struct node *Result=NULL;
	struct node *p1=list1,*p2=NULL;
	while(p1!=NULL) {
		p2=list2;
		struct node *result=NULL;
		while(p2!=NULL) {
			A=p1->a*p2->a;
			X=p1->x+p2->x;
			insert(&result,A,X);
			p2=p2->next;
		}
		
		struct node *current=result;
		while(current!=NULL){
			insert(&Result,current->a,current->x);
			struct node *delet=current;
			current=current->next;
			free(delet);
		}
		p1=p1->next;
	}

	struct node *p=Result;

	while(p!=NULL) {
		printf("%d %d ",p->a,p->x);
		p=p->next;
	}
	Free(list1);
	Free(list2);
	Free(Result);
	return 0;
}



