#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {	
	int pile[100]={0},i,n,method;
	i=0;
	while(scanf("%d",&method)!=-1){
		if(method==0){
			if(i==0){
				printf("error ");
				continue;
			}
			else{
				printf("%d ",pile[i-1]);
				pile[i-1]=0;
				if(i>0)
					i--;
			}
		}
		else{
			scanf("%d",&n);
			if(i==100){
				printf("error ");
			}
			else{
				pile[i]=n;
				if(i<99)
					i++;
			}
		}
	}
	
	return 0;
}



