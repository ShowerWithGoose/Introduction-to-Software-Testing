#include <stdio.h>
#include <stdlib.h>
int a[101];
int top=-1;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int push(int n)
{
if(top==99)
printf("error ");
else 
{
	top++;
a[top]=n;
}
return 0;
}
int pop()
{
	if(top==-1)
	printf("error ");
	else 
	printf("%d ",a[top--]);
	return 0;
}
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d",&n))
	{
		if(n==-1)
		break;
		else if(n==1)
		{
		scanf("%d",&n);
		push(n);
		}
		else if(n==0)
		{pop();
		}
	}
	return 0;
}

