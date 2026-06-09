#include<stdio.h>
#define MAXSIZE 100
int Top=-1;
int STACK[100];
void ru(int s[],int item){
	if(Top==MAXSIZE-1){
		printf("error ");
	}
	else s[++Top]=item;
}
void chu(int s[]){
	if(Top==-1){
		printf("error ");
	}
	else printf("%d ",s[Top--]);
}
int main(){
	int flag;
	int in,out;
	while(scanf("%d",&flag)!=EOF){
		if(flag==1){
			scanf("%d",&in);
			ru(STACK,in);
		}
		else if(flag==0){
			chu(STACK);
		}
		else if(flag==-1){
			break;
		}
	}
	return 0;
}

