#include <stdio.h>
int s[100];
int top;
void push(int *s, int x){
	if(top==99){
		printf("error ");
	}else{
		s[++top]=x;
	}
}
void pop(int *s){
	if(top==-1){
		printf("error ");
	}else{
		printf("%d ",s[top--]);
	}
}
int main()
{
	top=-1;
	int op,x;
	while(1){
		scanf("%d",&op);
		if(op==-1)	break;
		else if(op){
			scanf("%d",&x);
			push(s,x);
		}else{
			pop(s);
		}
	}
	return 0;
}

