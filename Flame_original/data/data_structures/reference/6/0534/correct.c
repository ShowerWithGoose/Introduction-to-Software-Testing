#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct a{
	int data[1000];
	int num;
}z;

int main(){
	int op,dat;
	z.num =0;
	while(~scanf("%d",&op)){
		if(op==1){
			if(z.num <100){
				scanf("%d",&dat);
				z.data [z.num]=dat;
				z.num ++;
			}
			else printf("error ");
		}
		else if(op==0){
			if(z.num >0){
				printf("%d ",z.data[z.num-1] );
				z.num--;
			}
			else printf("error ");
		}
		else {
			break;
		}
	}
	return 0;
}

