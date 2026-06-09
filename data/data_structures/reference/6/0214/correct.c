#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct stack{
	int top;
	int MAXSIZE;
	int Data[110];
} * Stack;
Stack S; 

int Is_Empty(){
	return (S->top==-1);
}
int Is_Full(){
	return (S->top==((S->MAXSIZE)-1));
}
int Push(int x){
	if(Is_Full()) return 0;
	else {
		S->Data [++(S->top)]=x;
		return 1;
	}
}
int Pop(){
	if(Is_Empty()) return 0;
	else{
		return (S->Data [(S->top)--]);
	}
}

int main()
{
	int i,j=0,k;
	int m,n;
	int x[110];
	
	S=(Stack)malloc(sizeof(struct stack));
	S->top =-1;
	S->MAXSIZE =100;//´´½¨
	
	while(1){
		scanf("%d ",&m);
		if(m==-1) break;
		else if(m==1){
			scanf("%d ",&n);
			if(Push(n)==0){
				x[j++]=-1;
			}//printf("a%d %da ",S->Data [S->top ],S->top );
		}
		else if(m==0){
			if(Is_Empty()==1) x[j++]=-1;
			else  {//printf("b%d %d b ",S->Data [S->top ],S->top );
				x[j++]=Pop();
			}
		}
	} 
	//for(i=0;i<j;i++) printf("%d ",x[i]);
	//printf("\n");
	for(i=0;i<j;i++){
		if(x[i]==-1) printf("error ");
		else printf("%d ",x[i]);
	}
	return 0;
 } 

