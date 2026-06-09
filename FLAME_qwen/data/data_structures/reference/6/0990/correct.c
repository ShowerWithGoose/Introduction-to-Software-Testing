#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int i=-1,a[100],n;
	while(scanf("%d",&n)!=EOF){
		if(n==1){
			i++;
			scanf("%d",&a[i]);
		}
		else if(n==0){
			if(i!=-1){
				printf("%d ",a[i]);
				i--;
			}
			else if(i==-1) printf("error ");
		}
		else if(n==-1) return 0;
	}
} 

