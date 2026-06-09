#define eps 1e-11
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
int stack[105]={0};
int top=-1;
void instack(int num){
	if(top<100){
		stack[++top]=num;
	}
	else
		printf("error ");
}
void outstack(){
	if(top!=-1){
		printf("%d ",stack[top]);
		top--;
	}
	else 
		printf("error ");
}

int main(){
	int op=-1,a;
	while(scanf("%d",&a)!=EOF)
	{
		if(a==-1) break;
		if(a==1){
			op=1;
			continue;
		}
		else if(a==0){
			op=0;
			outstack();
		}
		else{
			if(op==1){
				instack(a);
				op=-1;
			}
		}
	}
	printf("\n");
	return 0;
}

