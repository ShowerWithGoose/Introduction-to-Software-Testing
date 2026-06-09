#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 100
int stacks[105];
int top=0;
int main()
{
	int flag;
	while(1){
		scanf("%d",&flag);
		if(flag==-1) return 0;
		else if(flag==0){
			if(stacks[top-1]!=0){
				printf("%d ",stacks[top-1]);
				top--;
			}
			else{
				printf("error ");
			}
		}
		else{
			scanf("%d",&stacks[top]);
			top++;
		}
	}
}

