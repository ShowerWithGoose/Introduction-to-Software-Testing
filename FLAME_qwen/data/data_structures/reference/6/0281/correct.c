#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
int Top=-1;
int main(){
	int n;
	int temp; 
	while(scanf("%d",&n)!=-1){
		if(n==0){
			if(Top==-1){
				printf("error ");
			}
			else{printf("%d ",STACK[Top]);
			Top--; }
		}
		else if(n==1){
		 if(Top!=99){
		 scanf("%d",&n);
		 STACK[++Top]=n;
		}
		else if(Top==99){
			printf("error ");
		}
	}
	   else if(n==-1){
	   	break;
	   }
}
	return 0;
} 

