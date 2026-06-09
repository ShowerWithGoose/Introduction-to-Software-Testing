#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main(){
	int  stac[100],flg=0,n,m;
	while(1){
		scanf("%d",&n);
		if(n==1){
			scanf("%d",&m);			
			if(flg==100)
				printf("error ");
			else{
				stac[flg]=m;
				flg++;				
			}
		}
		if(n==0){
			if(flg==0)
				printf("error ");				
			else{
				flg--;
				printf("%d ",stac[flg]);
			}
		}
		if(n==-1)
			return 0;
	}
	return 0;
}


