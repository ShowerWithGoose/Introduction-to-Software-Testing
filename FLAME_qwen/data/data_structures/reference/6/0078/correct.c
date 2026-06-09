#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Num_stack[100]; //数据栈
int top=-1; //数据栈顶指示器，初始为空栈
void push(int num)  //进栈
{
    if(top == 100-1)
		printf("error ") ;
    Num_stack[++top] = num;
}
int pop()   //出栈
{
    if(top == -1)
	   printf("error ");
	else printf("%d ",Num_stack[top--]);
    return 1;
}
int main()
{
	int a=0,i;
	while(scanf("%d", &a)!=EOF){
		if(a==1){
			scanf("%d", &a);
			push(a);
		}
		if(a==0){
			pop();
		}
		if (a==-1) break;
	}
	//for(i=0;top>-1;i++){
	//	printf("%d ",Num_stack[i]);
	//}
    return 0;

}



