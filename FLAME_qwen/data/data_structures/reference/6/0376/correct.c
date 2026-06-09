#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;

int main(void)
{
	int i;
	while(~scanf("%d",&i))
	{
		switch(i){
			case -1:
				break;
			case 0:
				if(top==-1) printf("error ");
				else {
					printf("%d ",stack[top]);
					top--;
				}
				break;
			case 1:
				if(top==MAX) printf("error ");
				else {
					top++;
					scanf("%d ",&stack[top]);
				}
				break;
		}
	}
	return 0;
}

