#include <stdio.h>
#include <stdlib.h>

int Stack[105];

int main(){
	int op,num,top=-1;
	while(scanf("%d",&op)!=EOF){
		switch(op){
			case 1:
				scanf("%d",&num);
				if(top==99){
					printf("error ");
					break;
				}
				Stack[++top]=num;
				break;
			case 0:
				if(top==-1){
					printf("error ");
					break;
				}
				printf("%d ",Stack[top--]);
				break;
			case -1:
				return 0;
		}
	}
	return 0;
}
