#include<stdio.h>
#include<stdlib.h>
int a[100];
int main(){
	int top=-1,op,num;
	while(scanf("%d",&op)!=EOF){
		switch(op){
			case 1:
				if(top==99)
					printf("error ");
				else{
					scanf("%d",&num);
					a[++top]=num;
				}
				break;
			case 0:
				if(top==-1)
					printf("error ");
				else{
					printf("%d ",a[top]);
					top--;
				}
				break;
			case -1:
				return 0;
		}
	}
	return 0;
}

