#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int stack[1000];
int top=0;

int main()
{
	int a,b;
	while(1){
		scanf("%d",&a);
		if(a==1){
			scanf("%d",&b);
			if(top<100)
				stack[++top]=b;
			else
				printf("error ");
		}
		else if(a==0){
			if(top>0)
				printf("%d ",stack[top--]);
			else
				printf("error ");
		}
		else
			break;
	}
	return 0;
}



