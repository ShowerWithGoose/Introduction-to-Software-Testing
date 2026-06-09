#include<stdio.h>

void inStack(int a);
void outStack();
int stack[100]={0};
int step=0;
int main(){
	int sign;
	int sum;
	while(1){
		scanf("%d",&sign);
		if(sign==1){
			scanf("%d",&sum);
			inStack(sum);
		}else if(sign==0){
			outStack();
		}else if(sign==-1){
			break;
		}
	}
	return 0;
}
void inStack(int a){
	if(step>99){
		printf("error ");
	}else{
		stack[step]=a;
		step++;
	}
}
void outStack(){
	if(step<1){
		printf("error ");
	}else{
		step--;
		printf("%d ",stack[step]);
	}
}

