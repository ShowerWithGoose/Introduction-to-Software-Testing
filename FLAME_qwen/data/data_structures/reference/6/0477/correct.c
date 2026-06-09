#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct stack{
	int top;
	int array[1005];
}stack1;
int main(){
	stack1.top=-1;
	int n = 0;
	int a = 0;
	while(scanf("%d",&n)!=EOF){
		if(n==1){
			scanf("%d",&a);
			if(stack1.top>=99){
				printf("error ");
			}
			else 
				stack1.array[++stack1.top] = a;
		}
		else if(n==0){
			if(stack1.top==-1){
				printf("error ");
			}
			else{
				printf("%d ",stack1.array[stack1.top--]);
			}
		}
		else if(n==-1){
			break;
		}
	}
	return 0;
}

