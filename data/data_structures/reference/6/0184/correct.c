#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
	int Data[100];
	int top;
} s;
void push(s *p,int a){
	if(p->top==99) printf("error ");
	else p->Data[++p->top]=a;
	return;
}
void pop(s *p){
	if(p->top==-1) printf("error ");
	else printf("%d ",p->Data[p->top--]);
	return;
}
int main(){
	int a,i,j=-1,k;
	s p;
	p.top=j;
	while(scanf("%d",&a)){
		if(a==-1) break;
		if(a==0||a==1){
			j=a;
			if(j==1) continue;
		}
		if(j==1){
			push(&p,a);
			j=-1;
		}
		if(j==0){
			pop(&p);
			j=-1;
		}
	}
}

