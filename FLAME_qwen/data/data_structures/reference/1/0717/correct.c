#include <stdio.h>
#include <string.h>
int n,line[10];
int digui(int,int*);
int main(){
	scanf("%d",&n);
	digui(0,line);
	return 0;
}
int digui(int a,int* line){
	if(a==n){
		for(int i=0;i<n;i++){
			printf("%d ",line[i]);
//			return 0;
		}
			printf("\n");
	}
	for(int i=1;i<=n;i++){
		int flag=0;
		for(int j=0;j<a;j++){
			if(i==line[j]){
				flag++;
			}
		}
		if(flag==0){
			line[a]=i;
			digui(a+1,line);
		}
	}
}


