#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int array[100]={};
	int top=-1;
    int sign,num;
    while(scanf("%d",&sign)!=EOF){
    	if(sign==-1)
    	break;
    	else{
    		if(sign==1){
    			if(top==99)
    			printf("error ");
    			else{
    				scanf("%d",&num);
    				array[++top]=num;
				}
			}
			if(sign==0){
				if(top==-1)
				printf("error ");
				else
				printf("%d ",array[top--]);
			}
		}
	}
    return 0;
}


