#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
int n,now[11],use[11];
void find(int place){
	int i;
	if(place==n+1){
		for(i=1;i<=n;i++){
			printf("%d ",now[i]);
		}
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++){
		if(use[i]==0){
			use[i]=1;
			now[place]=i;
			find(place+1);
			use[i]=0;
		}
	}
} 
int main(){
	scanf("%d",&n);
	find(1);
	return 0;
}




