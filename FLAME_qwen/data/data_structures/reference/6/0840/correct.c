#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
void in(int a[], int data);
void out(int a[]);
int stack[MAXSIZE];
int top = -1;

int main(void)
{
	while(1)
	{
		int num;
		scanf("%d",&num);
		if(num == -1) break;
		else if(num == 1)
		{
			int a;
			scanf("%d",&a);
			in(stack,a);
		}
		else if(num == 0)
		{
			out(stack);
		}
	}
	return 0;
} 

void in(int a[], int data)
{
	if(top == MAXSIZE - 1) printf("error ");
	else a[++top] = data;
}

void out(int a[])
{
	if(top == -1) printf("error ");
	else printf("%d ",a[top--]);
}

