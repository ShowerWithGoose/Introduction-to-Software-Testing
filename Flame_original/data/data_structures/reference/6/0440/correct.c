#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>



int main(){
	int flag;
	int stack[101]={0};
	int top=0;
	
	do{
		scanf("%d",&flag);
		
		switch(flag){
			case 1:scanf("%d",&stack[++top]);
			break;
			case 0:if(top){
				printf("%d ",stack[top]);
				stack[top]=0;
				top--;
			}else{
				printf("error ");
			}
			break;
		}
	}while(flag!=-1);
	return 0;
}
