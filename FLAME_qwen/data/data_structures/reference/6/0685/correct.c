#include<stdio.h>

int main(){
	int s[100]={0};
	int top=-1;
	int op,n;
	scanf("%d",&op);
	while(op!=-1){
		if(op==1){
			scanf("%d",&n);
			if(top+1>=100)
				printf("error ");
			else 
				s[++top]=n;
		}
		else if(op==0){
			if(top<0)
				printf("error ");
			else 
				printf("%d ",s[top--]);
		}
		scanf("%d",&op);
	}
	return 0;
} 

