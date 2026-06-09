#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
	int stack[150]={0};
	int top=0;
	int n,m;
	while(~scanf("%d",&n)){
	if(n==1){
		scanf("%d",&m);
		stack[top++]=m;	
	}
	else if(n==0){
	if(top<1)
	{
	printf("error ");
    }
	else
	{
	printf("%d ",stack[top-1]);
	top--;
    }}	
	else if(n==-1) break;		
    }
	return 0;
} 

