#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
typedef int TRUE;
TRUE stack[MAX];
int top;
int main(){
	int i,j;
	top=-1,i=0;
	while(i!=-1){
		scanf("%d",&i);
		if(i==1){scanf("%d",&j);
		if(top==MAX)printf("error ");
		else	stack[++top]=j;
		}else if(i==0){
			if(top==-1)printf("error ");
			else printf("%d ",stack[top--]);
		}
		else return 0;;
	}
}

