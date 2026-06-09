#include<stdio.h>
#define M 100
int main(){
	int stack[M];
	int top=-1;
	int a=0,b=0;
	while(1){
		scanf("%d",&a);
		if(a==-1)
			break;
		else if(a==1){  //»Î’ª 
			if(top==M-1)
			{
				printf("error ");
				continue;
			}
			scanf("%d",&b);
			stack[++top]=b;
		}
		else{
			if(top==-1)
			{
				printf("error ");
				continue;
			}
			printf("%d ",stack[top--]);
		}
	}
	return 0;
}

