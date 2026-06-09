#include <stdio.h>
int a[200];
int main(){
	int top=1,i,mark,num;
	while(scanf("%d",&mark)!=EOF){
		if(mark==1){
			scanf("%d",&num);
			if(top==101){
				printf("error ");
			}
			else{
			a[top]=num;
			top++;	
			}
			
		}
		else if(mark==0){
			if(top==1){
				printf("error ");
			}
			else{
			printf("%d ",a[top-1]);
			top--;	
			}
			
		}
		else{
			break;
		}
	}
	
	
	
} 

