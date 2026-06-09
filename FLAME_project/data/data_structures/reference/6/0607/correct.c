#include<stdio.h>
#define max 105
#define n 100
int stack[max],op,top=0,tmp; 

int main(){
	while(~scanf("%d",&op)&&op!=-1){
		if(op==1){
			scanf("%d",&tmp);
			if(top==n) printf("error ");
			else stack[++top]=tmp;
		}
		else if(op==0){
			if(!top) printf("error ");
			else printf("%d ",stack[top--]);
		}
	}
	return 0;
}


