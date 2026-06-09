#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<malloc.h>


#define MaxSize 100

typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack,*PSqStack;

void Push(PSqStack s,ElemType b) {
	if(s->top==MaxSize) printf("error ");
	else s->data[++s->top]=b;
}

void Pop(PSqStack s) {
	if(s->top==0) printf("error ");
	else printf("%d ",s->data[s->top--]);
}

int main() {
	int a,b;
	PSqStack s=(PSqStack)malloc(sizeof(SqStack));
	s->top=0;
	scanf("%d",&a);
	while(a!=-1) {
		switch(a) {
			case 0:
				Pop(s);
				break;
			case 1:
				scanf("%d",&b);
				Push(s,b);
				break;
			default:
				return 1;
		}
		scanf("%d",&a);
	}
	return 0;
}

