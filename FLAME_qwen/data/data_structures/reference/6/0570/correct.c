#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
int stack[100];
int top=-1;
void pushStack(int item)
{
	if(top==99) printf("error ");
	else 
		{
		top++; stack[top]=item;
		}
}

void popStack()
{
	if(top==-1) printf("error ");
	else {
		
		printf("%d ",stack[top]);
		top--;
	}
}

int main()
{
	int op,n;
	do{
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&n);
			pushStack(n);
		}
		else if(op==0) {
			popStack();
		}
	}while(op!=-1);
	
	

}




