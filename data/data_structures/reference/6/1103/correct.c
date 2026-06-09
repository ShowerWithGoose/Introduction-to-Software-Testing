#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int main (){
	int r=0,stack[100],n=0;
	while(n!=100){
		stack[n]=0;
		n++;
	}
	n=0;
	while(r!=-1){
		scanf("%d",&r);
		if(r==1){
			if(n==100){
				printf("error ");
			}
			else {
				scanf("%d",&r);
				stack[n]=r;
				n++;
			}
		}
		else if(r==0){
			if(n==0){
				printf("error ");
			}
			else {
				printf("%d ",stack[n-1]);
				stack[n]=0;
				n--;
			}
		}
	}
	return 0;
}

