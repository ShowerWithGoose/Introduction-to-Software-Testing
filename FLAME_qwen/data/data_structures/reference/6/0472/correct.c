#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main(){
	
	int op,top=0;
    int a[105];
    while(1){
    	scanf("%d",&op);
    	if(top==100&&op==1){
    		printf("error ");
    		continue;
		}
		if(top==0&&op==0){
			printf("error ");
			continue;
		}
    	if(op==-1){
    		break;
		}
		if(op==1){
			top++;
			scanf("%d",&a[top]);
			
		}
		if(op==0){
			printf("%d ",a[top]);
			top--;
		}
	}

	
	
	
	
	
	
	return 0;
}



