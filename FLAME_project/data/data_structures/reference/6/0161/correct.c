#include<stdio.h>

int main()
{
	int stack[101],len=0,op,num;
	while(1){
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&num);
			if(len<100) stack[len++]=num;
			else printf("error ");
		}
		else if(op==0){
			if(len>0){
			 printf("%d ",stack[len-1]);
			 len--;
			 }
			else printf("error ");
		}
		else if(op==-1) return 0;
	}
}

