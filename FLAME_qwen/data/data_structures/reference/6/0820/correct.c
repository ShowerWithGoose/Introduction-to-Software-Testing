#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
	int i,j;
	int a[100];
	int top;
	int ob,in;
	top=-1;
	while(~scanf("%d",&ob)){
		if(ob==1){
			scanf("%d",&in);
			if(top==99){
				printf("error ");
				continue;
			}
			top++;
			a[top]=in;
		}
		else if(ob==0){
			if(top==-1){
				printf("error ");
				continue;	
			}
			printf("%d ",a[top]);
			top--;
		}
		else if(ob==-1){
			break;
		}
	}
	
	
	
	
	
	return 0;
} 

