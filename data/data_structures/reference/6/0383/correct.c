#include<stdio.h>
#define MAX 100
int s[MAX];
int top=-1;
int is_empty(){
	return (top==-1);
}
int is_full(){
	return (top==MAX-1);
}

void stuck_in(int data){
	if(is_full())printf("error ");
	else s[++top]=data;
}
int stuck_out(){
	if(is_empty()){printf("error ");return -1;}
	else{
		int tmp=s[top];
		top--;
		printf("%d ",tmp);
		return tmp;
	}
}
int main(){
	int op,data;
	while(scanf("%d",&op),op!=-1){
		if(op==1){
			scanf("%d",&data);
			stuck_in(data);
		}
		else	stuck_out();
	}
	return 0;
}

