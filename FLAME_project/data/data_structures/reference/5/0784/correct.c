#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int k;
	int n;
	struct node *next;
};
int a[1000][2];
int main(){
	int num1,num2;
	char ch;
	struct node *exp1=NULL,*p1,*q1;
	while(scanf("%d%d",&num1,&num2)!=EOF){
		q1=(struct node *)malloc(sizeof(struct node));
		q1->k=num1;
		q1->n=num2;
		q1->next=NULL;
		if(exp1==NULL)
			exp1=p1=q1;
		else{
			p1->next=q1;
			p1=p1->next;
		}
		scanf("%c",&ch);
		if(ch=='\n')
			break;
	}
	struct node *exp2=NULL,*p2,*q2;
	while(scanf("%d%d",&num1,&num2)!=EOF){
		q2=(struct node *)malloc(sizeof(struct node));
		q2->k=num1;
		q2->n=num2;
		q2->next=NULL;
		if(exp2==NULL)
			exp2=p2=q2;
		else{
			p2->next=q2;
			p2=p2->next;
		}
	}
	int x=0;
	p1=exp1;
	while(p1!=NULL){
		p2=exp2;
		while(p2!=NULL){
			a[x][0]=p1->k*p2->k;
			a[x][1]=(p1->n)+(p2->n);
			p2=p2->next;
			x++;
		}
		p1=p1->next;
	}
	for(int i=0;i<x-1;i++){
		for(int j=0;j<x-i-1;j++){
			if(a[j][1]<a[j+1][1]){
				int temp;
				temp=a[j][1];
				a[j][1]=a[j+1][1];
				a[j+1][1]=temp;
				temp=a[j][0];
				a[j][0]=a[j+1][0];
				a[j+1][0]=temp;
			}
		}
	}
	for(int i=0;i<x-1;i++){
		if(a[i][1]==a[i+1][1])
			a[i+1][0]+=a[i][0];
		else
			printf("%d %d ",a[i][0],a[i][1]);
	}
	printf("%d %d ",a[x-1][0],a[x-1][1]);
}

