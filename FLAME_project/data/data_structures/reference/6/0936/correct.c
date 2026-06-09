#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int a[101];
int b=0;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n==-1){
			break;
		}
		else if(n==1){
			int x;
			if(b==100){
				printf("error ");
				continue;
			}
			scanf("%d",&x);
			a[b++]=x;
		}
		else if(n==0){
			if(b==0){
				printf("error ");
				continue;
			}
			printf("%d ",a[--b]);
		}
	}
	return 0;
}

