#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//qsort顺序为数组名，元素数量，元素大小，cmp 
int stack[1000];
int top;
void push(int s[],int item,int num){
	if(num>=999)
    printf("error ");
    else
	s[++top]=item;
}

int pop(int s[],int num){
    if(num==-1)
    printf("error ");
    else
	return s[top--];
	return -1;
}

int main(){
	int op,item,i;
	top=-1;
	while(scanf("%d",&op)!=EOF){
		if(op==-1)
		return 0;
		if(op==1){
			scanf("%d",&item);
			push(stack,item,top);
		}
		if(op==0){
			i=pop(stack,top);
			if(i!=-1)
			printf("%d ",i);
		}
	}
	
    return 0;
} 

