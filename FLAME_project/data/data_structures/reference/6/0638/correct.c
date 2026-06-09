#include<stdio.h>
int main(){
	int fake_stack[105]={0},n,i=-1;
	while(1){
		scanf("%d",&n);
		if(n==1){
			i++; 
			scanf("%d",&fake_stack[i]);
			if(i>100){
				printf("error ");
				i--;
				fake_stack[i]=0;
			}
		}
		else if(n==0){
			if(i>=0){
				printf("%d ",fake_stack[i]);
				fake_stack[i--]=0;
			}
			else{
				printf("error ");
			}
		}
		else if(n==-1){
			break;
		}
	}
	return 0;
}

