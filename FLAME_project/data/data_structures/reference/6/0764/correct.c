#include<stdio.h>
int main(){
	int op,a[101]={0},i=0;
   	while(~scanf("%d",&op)){
   		if(op==1){
   			scanf("%d",&op);
   			if(i<100){
   			a[i]=op;
   			i++;
			   }
			else
			printf("error ");
		   }
		else if(op==0){
			if(i>0){
			printf("%d ",a[i-1]);
			i--;
			}
			else
			printf("error ");
			}
		else if(op==-1)
		break;
	   }
	   return 0;
}

