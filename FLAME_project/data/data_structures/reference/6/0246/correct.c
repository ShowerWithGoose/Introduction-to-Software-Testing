#include<stdio.h>
#define N 105 
int stack[N],top;
void sol(){
	char err[]="error ";
	while (1){
		int opt,x;
		scanf("%d",&opt);
		if (opt==1) {
			scanf("%d",&x);
			stack[++top]=x;
		}
		if (opt==0){
			if (top) printf("%d ",stack[top--]);
				else printf("%s",err);
		}
		if (opt==-1) {
			break;
		}
	}
}
int main(){
	sol();
	return 0;
}

