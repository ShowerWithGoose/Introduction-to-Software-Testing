#include <stdio.h>
int main(){
	int stack[101];
	int op,n;
	int top=-1;
	while(scanf("%d",&op)!=EOF&&op!=-1){
		if(op==1){
			scanf("%d",&n);
			if(top==100)
			printf("error ");
			else{
				stack[++top]=n;
			}
		}
		else{
			if(top==-1)
			printf("error ");
			else{
				printf("%d ",stack[top]);
				top--;
			}
		}
	}
	return 0;	
}

