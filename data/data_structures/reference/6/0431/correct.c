#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef int Position;
struct SNode {
    int *Data;
    Position Top;
    int MaxSize;
};
typedef struct SNode *Stack;
Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (int *)malloc(MaxSize * sizeof(int));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}
bool IsFull( Stack S )
{
    return (S->Top == S->MaxSize-1);
}

bool Push( Stack S, int X )
{
    if ( IsFull(S) ) {
        printf("error ");
        return false;
    }
    else {
        S->Data[++(S->Top)] = X;
        return true;
    }
}

bool IsEmpty( Stack S )
{
    return (S->Top == -1);
}

int Pop( Stack S )
{
    if ( IsEmpty(S) ) {
        printf("error ");
        return -1;
    }else{
	    return ( S->Data[(S->Top)--] );
	}    
}
int main(){
	int i=0,ne=-10,num;
	Stack S = CreateStack(100);
	while(ne != -1){
		scanf("%d",&ne);
		if(ne == 1){
			scanf("%d",&num);
			Push(S,num);
		}else if(ne == 0){
			int temp = 0;
			temp = Pop(S);
			if(temp != -1){
			    printf("%d ",temp);	
			}
		}
	}
	return 0;
}

