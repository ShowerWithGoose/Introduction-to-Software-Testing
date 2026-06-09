#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int a[102];
	int top = -1;
	int op;
	int ele;
	while(op!=-1){	
		scanf("%d",&op);
		if(op == -1){
			return 0;
		}
		else if(op == 1){
			if(top>=100){
				printf("error ");
				continue;
			}
			else{
				top++;
				scanf("%d",&ele);
				a[top] = ele;
			}
			
		}
		else if(op == 0){
			if(top<=-1){
				printf("error ");
				continue;
			}
			else{
				printf("%d ",a[top]);
				top--;
			}
		
		}

//		for(int i = 0;i<=5;i++){
//			printf("%d ",a[i]);
//			printf("\n");
//		}
	}
	return 0;
}

