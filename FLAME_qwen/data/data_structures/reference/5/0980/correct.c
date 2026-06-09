#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

typedef struct LINK{
	int coef;
	int expo;
	struct LINK* pre;
	struct LINK* next;
}mul;

mul *expr1,*expr2,*head1=NULL,*head2=NULL,*tail1,*tail2,*res,*temp,*head3,*tail3;

int main()
{
	int co=0,ex=0;
	char c;
	do{
		scanf("%d %d",&co,&ex);
		expr1=(mul*)malloc(sizeof(mul));
		expr1->coef=co;
		expr1->expo=ex;
		expr1->next=NULL;
		if(head1==NULL){
			head1=tail1=expr1;
		}
		else{
			expr1->pre=tail1;
			tail1->next=expr1;
			tail1=tail1->next;
		}
		c=getchar();
	}while(c!='\n');//create the LinkedList
	expr1=head1;//set the LinkedList at the head
	do{
		scanf("%d %d",&co,&ex);
		expr2=(mul*)malloc(sizeof(mul));
		expr2->coef=co;
		expr2->expo=ex;
		expr2->next=NULL;
		if(head2==NULL){
			head2=tail2=expr2;
		}
		else{
			expr2->pre=tail2;
			tail2->next=expr2;
			tail2=tail2->next;
		}
		c=getchar();
	}while(c!='\n');//create the LinkedList
	expr2=head2;//set the LinkedList at the head	
	
	while(expr1!=NULL){
		expr2=head2;
		while(expr2!=NULL){
			temp=(mul*)malloc(sizeof(mul));
			temp->coef=expr1->coef*expr2->coef;
			temp->expo=expr1->expo+expr2->expo;
			temp->next=NULL;
			expr2=expr2->next;
			res=head3;
			int flag=0;//flag==1,insert in somewhere,flag==0,add to the end
			while(res!=NULL){
				if(temp->expo==res->expo){
					res->coef+=temp->coef;
					flag=1;
					break;
				}
				else if(temp->expo>res->expo){
					temp->pre=res->pre;
					res->pre->next=temp;
					res->pre=temp;
					temp->next=res;
					flag=1;
					break;
				}
				res=res->next;
			}
			if(flag==0){
				if(head3==NULL){
					head3=tail3=temp;
				}
				else{
					temp->pre=tail3;
					tail3->next=temp;
					tail3=tail3->next;
				}
			}	
		}
		mul* fre=expr1;
		free(fre);
		expr1=expr1->next;
	}

	expr2=head2;	
	while(expr2!=NULL){
		mul* fre=expr2;	
		free(fre);
		expr2=expr2->next;
	}
	res=head3;
	while(res!=NULL){
		printf("%d %d ",res->coef,res->expo);
		mul* fre=res;
		free(fre);
		res=res->next;
	}

	return 0;
}

