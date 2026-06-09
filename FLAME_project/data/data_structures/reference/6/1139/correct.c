#include<stdio.h>
#include<stdlib.h>
int top=-1;
int main(){
	int op,m;
	int stack[101];
	while(1){
		scanf("%d",&op);
		if(op==-1)break;
		else if(op==1){
			scanf("%d",&m);
			if(top==99)printf("error ");
			else{
				stack[++top]=m;
			}
		}
		else{
			if(top==-1)printf("error ");
			else{
				printf("%d ",stack[top--]);
			}
		}
	}
	return 0;
}

