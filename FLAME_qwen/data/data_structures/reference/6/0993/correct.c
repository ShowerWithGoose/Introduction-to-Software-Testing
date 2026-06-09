#include<stdio.h>           
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
int stack[103];
int top = -1;
void push(int element)
{
	if(top==99)	printf("error ");
	else stack[++top] = element;
} 
void pop()
{
	if(top==-1)	printf("error ");
	else {
		printf("%d ",stack[top]);
		top -- ;
	}
}
int main()
{
	int order,num;
	while(scanf("%d",&order)!=EOF){
		if(order==-1)	break;
		else {
			if(order==1)
			{
				scanf("%d",&num);
				push(num);
			}
			else if(order==0)
			{
				pop();
			}
		}
	}
	return 0;
}

