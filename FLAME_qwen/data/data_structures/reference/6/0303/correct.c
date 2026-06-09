#include <stdio.h>

int stack[100], top=-1;
int main(){
	int op=0;
	while(scanf("%d", &op) != EOF){
		switch(op){
			case 0:
				if(top == -1){
					printf("error ");
				}else{
					printf("%d ", stack[top--]);
				}
				break;
			case 1:
				if(top == 99){
					printf("error ");
				}else{
					int x;
					scanf("%d", &x);
					stack[++top] = x;
				}
				break;	
			case -1:
				break;
		}
		if(op == -1)
			break;
	}
	return 0;
}

