#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, chunfang[100], yongfa[100];
void digui(int k);

int main(){
	memset(chunfang, 0 ,sizeof(chunfang));
	memset(yongfa, 0, sizeof(yongfa));
	scanf("%d", &n);
	digui(1);
	return 1;
} 

void digui(int k){
	int i; 
	if(k > n){
		for(i = 1;i <= n;i++){
			printf("%d ", chunfang[i]);
		}
		printf("\n");
	}
	else{
		for(i = 1;i <= n;i++){
		if(!yongfa[i]){
			chunfang[k] = i;
			yongfa[i] = 1;
			digui(k+1);
			yongfa[i] = 0;
		}
		}
	}
}

