#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[101]; 
	int head=0,x,i,op;
	while(scanf("%d",&op)!=EOF){
		if(op==1){
			if(head==100) {
				printf("error ") ;
				scanf("%d",&i);
			}
			else {
				scanf("%d",&x);
			    a[head++]=x;
			}
		}
		else if(op==0){
			if(head==0) printf("error ");
			else {
			    printf("%d ",a[head-1]);
			    head--;
			}
		}
		else if(op==-1){
			exit(0);
		}
	}
	return 0;
}

