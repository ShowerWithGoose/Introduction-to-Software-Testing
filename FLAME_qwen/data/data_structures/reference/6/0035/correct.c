#include<stdio.h>

int main(){
	int n,m,i,nums[111];	
	i=0;
	while(scanf("%d",&n)!=EOF){
		if(n==1){
			scanf("%d",&m);
			if(i>=100){
				printf("error ");
			}else{
				nums[i]=m;
				i++;
			}
		}else if(n==0){
			if(i<1){
				printf("error ");
			}else{
				printf("%d ",nums[i-1]);
				i--;
			}
		}else if(n==-1){
			break;
		}
	}
	return 0;
}


