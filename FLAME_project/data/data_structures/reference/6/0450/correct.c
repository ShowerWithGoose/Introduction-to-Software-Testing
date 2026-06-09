#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int num,t,i,j;
	int stack[110]={0},top=-1;
	int op[110],top1=-1;

	memset(op,-1,sizeof(op));
	
	while(scanf("%d",&t)){
		if(-1==t) break;
		else if(1==t){
			scanf("%d",&num);
			if(99==top) printf("error ");
			else{
				stack[++top]=num;
			}
		}
		else if(0==t){
			if(top==-1) printf("error ");
			else{
				printf("%d ",stack[top]);
				stack[top--]=0;
			}
		}
	}
	
	return 0;
}

