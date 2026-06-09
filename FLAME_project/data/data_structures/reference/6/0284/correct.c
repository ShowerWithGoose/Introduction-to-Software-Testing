#include<stdio.h>
int main(){
	int stack[110],op,n=-1;
	while(1){
		scanf("%d",&op);
		switch(op){
			case -1:return 0;
			case 0:
				if(n==-1){
					printf("error ");
				}else{
					printf("%d ",stack[n]);
					n--;
				}
				break;
			case 1:
				if(n>=99){
					printf("error ");
				}else{
					scanf("%d ",&stack[++n]);
				}
				break;
		}
	}
	return 0;
}
