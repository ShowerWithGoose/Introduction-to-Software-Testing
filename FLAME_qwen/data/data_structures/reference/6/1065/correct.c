#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack{
	int top;
	int num[200];
};
struct stack a;
int main(){
	int op,data;
	a.top=0;
	while(scanf("%d",&op)!=EOF){
		if(op==1){//入栈操作
			scanf("%d",&data);
			if(a.top>=100){//容量已满
				printf("error ");
			}
			else{
				a.num[a.top]=data;
				a.top++;
			}
		}
		else if(op==0){//出栈操作
			if(a.top<=0){
				printf("error ");
			}
			else{
				printf("%d ",a.num[a.top-1]);
				a.top--;
			}
		}
		else if(op==-1)
			break;		
	}

	return 0;
}

