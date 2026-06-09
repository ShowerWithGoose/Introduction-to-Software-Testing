#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[1000];
int top = -1;
int push(int x);
int pop();
int main()
{
	int opr, x;
	scanf("%d", &opr);
	while(opr!=-1){
	
		if(opr==1){
			scanf("%d", &x);
			if(top==100) printf("error ");
			else push(x);
		}
		if(opr==0){
			if(top==-1) printf("error ");
			else pop();
		}
		scanf("%d", &opr);
	}
}

int push(int x)
{
	
 	top++;
	a[top] = x;
	return top;
}

int pop()
{
	printf("%d ", a[top]);
	a[top] = 0;
	return a[top--];
}
