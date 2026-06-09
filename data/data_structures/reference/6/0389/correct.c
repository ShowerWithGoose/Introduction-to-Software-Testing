#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int i=0,n,ys,a[105];
	while(1){
		scanf("%d",&n);
		if(n==1){
			if(i>=100) printf("error ");
			scanf("%d",&ys);
			if(i<100){
				a[i]=ys;
				i++;
			}
		}
		if(n==0){
			if(i==0) printf("error ");
			if(i>0){
				printf("%d ",a[i-1]);
				i--;		
			}
		}
		if(n==-1) break;
	}
	return 0;
}


