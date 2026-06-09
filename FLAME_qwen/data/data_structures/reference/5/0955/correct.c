#include<stdio.h>
#include<stdlib.h>
int main(){
	int i=0;
	struct txt1{
		int a;
		int b;
	};
	struct txt1 x[1000];
	struct txt1 temp;
	struct num{
		int xi;
		int n;
		struct num *next;
	};
	struct num *q1,*q2;
	struct num *head1=NULL,*tail1,*head2=NULL,*tail2;
	while(1){
		q1=(struct num*)malloc(sizeof(struct num));
		scanf("%d%d",&q1->xi,&q1->n);
		if(head1==NULL)
		head1=tail1=q1;
		else{
			tail1->next=q1;
			tail1=tail1->next;
		}
		if(getchar()=='\n')
		break;
	}
		while(1){
		q2=(struct num*)malloc(sizeof(struct num));
		scanf("%d%d",&q2->xi,&q2->n);
		if(head2==NULL)
		head2=tail2=q2;
		else{
			tail2->next=q2;
			tail2=tail2->next;
		}
		if(getchar()=='\n')
		break;
	}
	for(q1=head1;q1!=NULL;q1=q1->next)
	for(q2=head2;q2!=NULL;q2=q2->next){
		x[i].a=(q1->xi)*(q2->xi);
		x[i].b=(q1->n)+(q2->n);
		i++;
	}
	for(int l=0;l<i;l++)
	   for(int j=l+1;j<i;j++){
	   	if(x[l].b<x[j].b){
	   		temp=x[l];
	   		x[l]=x[j];
	   		x[j]=temp;
		   }
		else if(x[l].b==x[j].b){
			x[l].a+=x[j].a;
			x[j].a=0;
			x[j].b=0;
		}
	   }
	for(int f=0;x[f].a!=0;f++){
		printf("%d %d ",x[f].a,x[f].b);
	}
	for(q1=head1;q1!=NULL;q1=q1->next)
	free(q1);
	for(q2=head2;q2!=NULL;q2=q2->next)
	free(q2);
	return 0;
}

