#include <stdio.h>

int top=-1;
int isFull(){
	return top==99;
}
int isNull(){
	return top==-1;
}
int main(){
	int a[100],op,th,i=0;
	while(scanf("%d",&op)!=EOF){
		if(op==1){
			scanf("%d",&th);
			if(isFull()){
				printf("error ");
				continue;
			}
			a[++top]=th;
		}
		else if(op==0){
			if(isNull()){
				printf("error ");
				continue;
			}
			printf("%d ",a[top--]);
		}
		else if(op==-1)
		    break;
	}
	
	return 0;
} 

