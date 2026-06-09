#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
int stack[101];
int top=-1; 
void out(){
	if(top!=-1)printf("%d ",stack[top--]);
	else printf("error ");
}
int main(){
	int op=0;
	while(op!=-1){
		scanf("%d",&op);
		if(op==0)out();
		if(op==1)scanf("%d",&stack[++top]);
	}
	return 0;
}

