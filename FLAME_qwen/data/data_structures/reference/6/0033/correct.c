#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
int z[500]={0},head,ex,jud;

while(1){
	scanf("%d ",&jud);
	if(jud==1&&head!=100){
	scanf("%d ",&z[head]); 
	head++;	
}
if(jud==0){
	if(head!=0){
		head--;
		printf("%d ",z[head]);
		z[head]=0;
	}
	else{
		printf("error ");
	}
}
if(jud==-1){
	break;
}
}
 	return 0;
}


