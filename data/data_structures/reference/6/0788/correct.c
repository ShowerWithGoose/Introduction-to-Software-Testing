#include<stdio.h>
int main(){
	int op,a[1000],i=0;
	while(scanf("%d",&op)!=EOF){
		if(op==1)
		scanf("%d",&a[i++]);
		else if(op==0){
			if(i>0) 
			printf("%d ",a[i-1]),i--;
			else
			printf("error ");
		}
		else if(op==-1)
		break;
	}
} 

