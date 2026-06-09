#include<stdio.h>
#include<stdlib.h>
#define Max 100

typedef struct SNode *Stack;
struct SNode{
	int Data[Max];
	int Top;
};
void Push(Stack S,int item){
	if(S->Top==Max) printf("error ");
	else S->Data[++(S->Top)]=item;
	return;
}
int Pop(Stack S){
	if(S->Top==-1) return 0;
	else return S->Data[(S->Top)--];
}
int main(){
	int opt,num;
	Stack S;
	S=(Stack)malloc(sizeof(struct SNode));
	S->Top=-1;
	
	scanf("%d",&opt);
	while(opt!=-1){
		if(opt==1){
			scanf("%d",&num);
			Push(S,num);
		}
		else{
			num=Pop(S);
			if(num) printf("%d ",num);
			else printf("error ");
		}
		scanf("%d",&opt);
	}	
	return 0;
}


