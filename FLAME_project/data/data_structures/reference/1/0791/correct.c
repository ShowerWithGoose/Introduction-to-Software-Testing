#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define LL long long
#define ULL unsigned long long 
int line[20];
int book[20]={0};
int i=1,sum;
void dfs(int num){
	int j;
	if(num==0){
		for(j=1;j<=sum;j++){
			printf("%d ",line[j]);
		}
		printf("\n");
	}
	else{
		for(j=1;j<=sum;j++){
			if(book[j]!=1){
				line[i]=j;
				book[j]=1;
				i++;
				dfs(num-1);
				i--;
				book[j]=0;
			}
		}
	}
}
int main() {
     scanf("%d",&sum);
	 dfs(sum); 
	return 0;
}



