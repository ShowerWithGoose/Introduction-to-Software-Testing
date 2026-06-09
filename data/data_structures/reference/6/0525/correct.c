#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int zhan[150];
int main(){
	int number;
	int cnt;
	int temp;
	do{
		scanf("%d",&number);
		if(number==1){
			if(cnt==99){
				printf("error ");
				continue;
			}
			scanf("%d",&temp);
			zhan[cnt++]=temp;
		}
		else if(number==0){
			if(cnt==0){
				printf("error ");
				continue;
			}
			printf("%d ",zhan[--cnt]);
		}
	}while(number!=-1);
	return 0;
}
