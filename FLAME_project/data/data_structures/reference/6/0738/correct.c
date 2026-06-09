#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct {
	int data[100];
	int top;
	int base;
}sqstack,*sqslink;

void Clear(sqslink s) {
	s->top=-1;
	s->base=-1;
}

void Push(sqslink s, int x) {
	if (s->top>=100-1)
		exit(0);
	else {
		s->top++;
		s->data[s->top]=x;
	}
}


int Empty(sqslink s) {
	if (s->top<0)
		return 1;
	else
		return 0;
}


int Pop(sqslink s) {
	if(Empty(s)==1){
		return -1;
	}
	int n=s->data[s->top];
	s->top--;
	return n;
}

void show(sqslink s) {
	while(s->top!=s->base) {
		printf("%d ",s->data[s->top]);
		s->top--;
	}
}
int main() {
	sqslink stack;
	stack =(sqslink)malloc(sizeof(sqstack));
	Clear(stack);
	int op,num;
	int p[100],sum=0;
	scanf("%d",&op);
	while(op!=-1) {
		if(op==1) {
			scanf("%d",&num);
			Push(stack,num);
		} else if(op==0) {
			p[sum]=Pop(stack);
			sum++;
		}
		scanf("%d",&op);
	}
	int i;
	for(i=0;i<sum;i++){
		if(p[i]==-1){
			printf("error ");
		}else{
			printf("%d ",p[i]);
		}
	}
}



