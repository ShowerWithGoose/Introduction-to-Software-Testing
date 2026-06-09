#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int map[201];
int main(){
	int i=0,n,a;
	while(1){
		scanf("%d",&a);
		if(a==1){
			scanf("%d",&n);
			if(i==100)
			{
				printf("error ");
			}
			else 
			 map[i]=n;
			 i++;	
			}
     if(a==0){
		if(i==0){
			printf("error ");
		}
		else {
             i--;
		printf("%d ",map[i]);
	}
}
	else if(a==-1){
		break;
	}	
	}
	return 0;
}



