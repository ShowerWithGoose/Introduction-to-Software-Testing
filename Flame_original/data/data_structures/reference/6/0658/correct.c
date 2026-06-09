#include<stdio.h>
#include<stdlib.h>
int stack[100];
int main(){
	int num,top=0,op;
	while(1){
		scanf("%d",&op);
		switch(op){
			case 1:{
				scanf("%d",&num);
				if(top==99) printf("error ");
				else stack[++top]=num;
				break;
			}
			case 0:{
				if(top==0) printf("error ");
				else{
					printf("%d ",stack[top]);
					top--;
				}
				break;
			}
			case -1:return 0;
		}
	}
} 

