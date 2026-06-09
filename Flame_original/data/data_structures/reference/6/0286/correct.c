#include<stdio.h>
int stack[100];
int top=-1;
int main(){
	int x,temp;
	do{
		scanf("%d",&x);
		if(x==-1)
		break;
		else if(x==1){
			scanf("%d",&temp);
			if(top<=98){
				top++;
				stack[top]=temp;
			}
			else
			{
				printf("error ");
			}
			
		}
		else if(x==0){
			if(top<0)
			printf("error ");
			else{
				printf("%d ",stack[top]);
				top--;
			}
		}
	}while(x!=-1);
	return 0;
} 

