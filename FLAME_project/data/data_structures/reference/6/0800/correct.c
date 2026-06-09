#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int zhan[100];
int top=-1;
int op;
int shu;
 int isfull(){
 	return (top==100-1);
 }
 int isempty(){
 	return(top==-1);
 }
 
int charu(int s[] ,int el )
{
 if(isfull()){
 	printf("error ");
 }	
else{
s[++top]=el;
}	
			
 } 
 int shanchu(int s[],int el){
 	if(isempty()){
 		printf("error ");
	 }
 	else
 	{
	 printf("%d ",s[top]);
	 top--; 
	 }
 	
 }

int main(){
   int i=0;
   char c;
while(scanf("%d",&op)) {
	if(op==1)    scanf(" %d",&shu),charu(zhan,shu);
	else if(op==0) shanchu(zhan,shu);
	else if(op==-1) return 0 ;
}
   
}

