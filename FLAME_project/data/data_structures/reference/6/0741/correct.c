#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define M 1000000
#define ll long long

// 堆栈
#define Maxsize 100
typedef struct Snode{
	int data[Maxsize];
	int Top;
	// Top记得赋值-1,代表0个元素，参考数组
    // 使用数组时，不用malloc
}*Stack;

// 入栈
void Push(Stack PtrS,int item){
	if(PtrS->Top==Maxsize-1){
		printf("error ");	return;
	}else{
		PtrS->data[++(PtrS->Top)]=item;
		// (Ptrs->Top)++;
		// PtrS->data[PtrS->Top]=item;
		return;
	}
}

// 出栈
int Pop(Stack Ptrs){
	if(Ptrs->Top==-1){
		printf("error ");
		return 0;
	}else{
		return(Ptrs->data[(Ptrs->Top)--]);
	}
}

int main() {
    Stack Ptrs=(Stack)malloc(sizeof(struct Snode));
    Ptrs->Top=-1;
    int i,n=0;
    while(scanf("%d",&i)!=EOF){
        if(i==1){
            scanf("%d",&n);
            Push(Ptrs,n);
        }else if(i==0){
            n=Pop(Ptrs);
			if(n!=0) printf("%d ",n);
        }else if(i==-1){
			return 0;
        }
    }	
}
