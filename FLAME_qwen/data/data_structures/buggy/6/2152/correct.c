#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int number[1000];
int main() {
	int n,nums,len=0;
	
	while(1) {
		scanf("%d",&n);
		if(n==0) {
			if(len==0) {
				printf("error ");
				continue;
			} else {
				printf("%d ",number[len-1]);
				number[len-1]=0;
				len--;
			}
		} else if(n==1) {
			if(len==100) continue;
			scanf("%d",&number[len++]);
		} else if(n==-1) {
			break;
		}
	}
	
	
	
}



