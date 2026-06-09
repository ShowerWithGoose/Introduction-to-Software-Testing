#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define arynum(x) (sizeof(x)/sizeof(x[0]))
#define uint unsigned int
#define uchar unsigned char

int queen[100],top;

int isempty(){
	return top<0;
}

int isfull(){
	return top>=100;
}

int main(){
	int sgn;
	int num; 
	top=-1;	
	while((scanf("%d",&sgn)!=EOF)){
		if(sgn==-1)	break;
		else if(sgn==1){
			scanf("%d",&num);
			if(isfull())
				printf("error ");
			else
				queen[++top]=num;
		}
		else if(sgn==0){
			if(isempty())
				printf("error ");
			else
				printf("%d ",queen[top--]);
		}
	}
	return 0;
}

