#include<stdio.h>
int top=0,a[100];
int push(int x){
	if (top==99) printf("error ");
	else	a[top++]=x;
	return 0;
}
int pop(){
	if (top>0) printf("%d ",a[--top]);
	else printf("error ");
	return 0;
}
int main(){
	int n,m;
	while(1){
		scanf("%d",&n);
		switch (n){
			case 1:scanf("%d",&m);
					push(m);
					break;
			case 0:pop();
					break;
			case -1:return 0;
					break;
		}
	}
}



