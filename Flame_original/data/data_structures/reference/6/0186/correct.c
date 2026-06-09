#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int z[100],top=-1,i,n;
	while(scanf("%d",&i)){
		if(i==1){
			scanf("%d",&n);
			if(top==99) printf("error ");
			else z[++top]=n;
			continue;
		}
		if(i==0){
			if(top>=0) printf("%d ",z[top--]);
			else printf("error ");
		}
		if(i==-1) break;
	}
	return 0;
}

