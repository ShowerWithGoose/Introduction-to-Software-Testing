#include <stdio.h>

int main(){
	
	int zhan[100]={0};
	int n=-1;
	int sign;
	scanf("%d",&sign);
	while(sign!=-1){
		if(sign==1){
			if(n<98)
				scanf("%d",&zhan[++n]);
			else
				printf("error ");
		}
		if(sign==0){
			if(n>=0){
				
				printf("%d ",zhan[n--]);
			}
			else
				printf("error ");			
		}
		scanf("%d",&sign);
	} 
	return 0;
} 

