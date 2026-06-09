#include<stdio.h>

int st[110],top;

void push(int a){
	if(top==100){
		printf("error ");
		return ;
	}
	st[++top]=a;
}

void pop(){
	if(top==0){
		printf("error ");
		return ;
	}
	printf("%d ",st[top--]);
}

int main()
{
	int a;
	while(1){
		scanf("%d",&a);
		if(a==-1)return 0;
		if(a==1){
			scanf("%d",&a);
			push(a);
		}
		else if(a==0)pop();
	}
}

