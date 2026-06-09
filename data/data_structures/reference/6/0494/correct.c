#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int read(){
	char c;
	int num=0;
	bool f=0;
	c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		num=num*10+c-'0';
		c=getchar();
	}
	if(f)num=-num;
	return num;
}
struct STACK{
	int num[105];
	int t;
}stack;
bool push(int x){
	if(stack.t==100)return 0;
	stack.num[stack.t++]=x;
	return 1;
}
int top(){
	if(stack.t==0)return 1e9;
	return stack.num[stack.t-1];
}
bool empty(){
	return stack.t==0;
}
void pop(){
	stack.t--;
}
int main(){
	stack.t=0;
	while(1){
		int x=read();
		if(x==-1)break;
		if(x==1){
			x=read();
			if(!push(x))printf("error ");
		}else{
			if(!empty(x)){
				printf("%d ",top());
				pop();
			}else{
				printf("error ");
			}
		}
	}
	printf("\n");
	return 0;
}
