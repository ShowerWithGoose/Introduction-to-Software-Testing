#include<stdio.h>
int main(){
	int stack[105]={0};
	int push=0,hop=0,i=0;
	int operate,num;
	while(scanf("%d",&operate)!=EOF){
		if(operate==0){//HOP
			if(i==0){
				printf("error ");
				continue;
			}
			printf("%d ",stack[i-1]);
			stack[i-1]=0;
			i--;	
		}
		else if(operate==1){//PUSH
		scanf(" %d",&num);
			if(i==100){
				printf("error ");
				continue;
			}
			stack[i]=num;
			i++;
		}
	}
	return 0;
} 

