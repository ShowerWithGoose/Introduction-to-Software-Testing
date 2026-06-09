#include<stdio.h>
int zhan[100];
int main(){
	int a,i=0;
	while(~scanf("%d",&a)){
		if(a==1){
			if(i==100){
				printf("error ");
				continue;
			}
			scanf("%d",&a);
			zhan[i++]=a;
		}
		else if(a==0){
			if(i==0){
				printf("error ");
				continue;
			}
			i--;
			printf("%d ",zhan[i]);
		}
		else if(a==-1)
		break;
	}
	return 0;
} 

