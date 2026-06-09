#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//创建一个结构体来实现栈
struct stack{
	int data[100]; //栈内一共可以有100个数据，保存栈中的元素
	int top; //指向栈顶，储存栈顶
}s;
int main(){
	//先对栈进行初始化，初始状态为空
	s.top=0;
	int fun,num;
	while(scanf("%d",&fun)){
		//printf("%d",fun);
		if(fun==-1){
			//操作结束
			break;
		}
		else if(fun==1){
		//	printf("here1");
			scanf("%d",&num);
			//进行入栈操作
			if(s.top==99){
				printf("error ");
			}
			else{
				s.top++;
				s.data[s.top]=num;
			}
		//	printf("%d",num);
		//	for(int i=0;i<s.top;i++){
		//		printf("%d ",s.data[i]);
		//	}
		}
		else if(fun==0){
		//	printf("here2");
			//进行出栈操作
			if(s.top==0){
				printf("error ");
			}
			else{
				printf("%d ",s.data[s.top]);
				s.top--;
			}
		}
		
	}
	return 0;
}

