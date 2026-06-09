#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int a[100]={},c,b,n=0;a;
	while(scanf("%d ",&b)!=-1){
		if(b==1){
			if(n==100){
				scanf("%d ",&c);printf("error ");
			}
			else scanf("%d ",&a[n++]);
		}
		if(b==0){
			if(n==0) printf("error ");
			else printf("%d ",a[--n]);;
		}
	}
	return 0;
}

