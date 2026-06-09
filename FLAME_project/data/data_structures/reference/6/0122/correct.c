#include<stdio.h>
#include<string.h>
int stack[100];
int TOP=-1;
int main(){
int flag,n;
while(1){
	scanf("%d",&flag);
	if(flag==1){
		scanf("%d",&n);
		if(TOP==99){
		printf("error ");	
		}
		else{
		stack[++TOP]=n;
		}
	}
	if(flag==0){
		if(TOP==-1){
			printf("error ");
		}
		else{
			printf("%d ",stack[TOP--]);
		}
	}
	if(flag==-1) break;
}
return 0;
} 

