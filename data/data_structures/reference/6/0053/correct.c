#include<stdio.h>
int main(){
	int sta;
	int a[100];
	int i=0;
	while(scanf("%d",&sta)!=EOF){
		if(sta==1){
			if(i!=100){
			scanf("%d",&a[i]);
			i++;
			}else{
				printf("error ");
			}
		}else if(sta==0){
			if(i==0){
				printf("error ");
			}else{
				i--;
				printf("%d ",a[i]);
			}
		}else{
			break;
		}
	}
	return 0;
}

