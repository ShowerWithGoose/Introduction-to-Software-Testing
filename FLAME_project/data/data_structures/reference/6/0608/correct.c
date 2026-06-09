#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int stack[100];
int top;
int main()
{
top=-1;
int op,item;
while (scanf("%d",&op)!=0){
	if (op==1){
		if (top==99){
			printf("error ");
		}
		else{
		scanf("%d",&item);
		stack[++top]=item;
		}
	}
	if (op==0){
		if (top==-1){
			printf("error ");
		}
		else{
		printf("%d ",stack[top--]);
		}
	}
	if (op==-1){
		break;
	}
}
return 0;
}











