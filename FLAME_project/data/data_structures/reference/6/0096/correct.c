#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
	int a[100];
	int top=-1;
	int n,m;
	scanf("%d",&n);
	while(n!=-1){
		if(n==1){
			scanf("%d",&m);
			top++;
			if(top==100){
				printf("error ");
				top--;
			}
			else{
				a[top]=m;
			}
		}
		else if(n==0){
			if(top==-1){
				printf("error ");
			}
			else{
				printf("%d ",a[top]);
				top--;
			}
		}
		scanf("%d",&n);
	}
	return 0;
}

