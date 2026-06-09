#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int top=0;
int zhan[105];
int push(int i)
{
	if(top>99){
		printf("error ");
		return 0;
	}
	zhan[top++]=i;
	return 0;
}
int pop()
{
	
	if(top<1){
		printf("error ");
		return 0;
	}
	top--;
	printf("%d ",zhan[top]);
	return 0;
}
int main()
{
	int t,g;
	while(1){
		scanf("%d",&t);
		if(t==0)
		pop();
		else
		if(t==1){
			scanf("%d",&g);
			push(g);
		}
		else
		if(t==-1)
		break;
	}
	return 0;
}

