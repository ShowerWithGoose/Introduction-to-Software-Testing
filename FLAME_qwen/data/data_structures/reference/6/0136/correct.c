#include<stdio.h> 
#include<string.h> 

int STACK[100];
int Top = -1;   

int isfull(){
	return Top==99;
}
int isempty(){
	return Top==-1;
}
void push(int s[],int item) 
{
	if(isfull()){
		printf("error ");
	}
	else s[++Top]=item;
}
void pop(int s[]) 
{
	if(isempty()){
		printf("error ");
	}
	else printf("%d ",s[Top--]);
}
int main (int argc, const char * argv[]){
	while(1){
		int flag;
		scanf("%d",&flag);
		if(flag==1){
			int x;
			scanf("%d",&x);
			push(STACK,x) ;
		}
		else if(flag==0)
		pop(STACK);
		else break;
	}
	return 0;
}

