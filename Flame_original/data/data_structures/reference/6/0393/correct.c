#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 

int main(){
	int count=0,i,flag,num;
	int a[101];
	while(~scanf("%d",&flag)){
		if(flag==0){
			if(count==0){
				printf("error ");
			}else{
				printf("%d ",a[count-1]);
				count--;
			}
			
			
		}else if(flag==1){
			scanf("%d",&num);
			if(count>=100){
				printf("error ");
			}else{
				a[count]=num;
				count++;
			}
		}else if(flag==-1){
			break;
		}
	}
	 
	return 0;
} 

