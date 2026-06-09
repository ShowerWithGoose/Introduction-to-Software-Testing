#include<stdio.h>
int top=-1;
int isempty(int top){
	return top==-1;
}
int isfull(int top){
	return top==99;
}
int main(){
	int s[100];
	int op;
	int item;
	while(1){
		scanf("%d",&op);
		if(op==-1) break;
		else if(op==1){
			scanf("%d",&item);
			if(isfull(top))  printf("error ");
			else{
		    top++;
			s[top]=item;
		    }
		}
		else if(op==0){
			if(isempty(top))  printf("error ");
			else {
			printf("%d ",s[top]);
			top-=1;
		    }
		}
	} 
	return 0;
} 

