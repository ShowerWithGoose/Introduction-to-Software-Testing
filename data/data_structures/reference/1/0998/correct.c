#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
int hash[15];

void full(int num[], int n, int m) {//n数字多少，m第几层 
	if(m==n+1){
		for(int i = 1 ;i<=n;i++){
			printf("%d ",num[i]);
		}
		printf("\n");
	}
	else{
		for(int i=1;i<=n;i++){
			if(!hash[i])//没用过
			{
				hash[i]=1;
				num[m] = i;
				full(num,n,m+1);
				hash[i] = 0;
			} 
		}
	}
}
int main() {
	int n=0;
	int num[15]={0};
	scanf("%d", &n);

	full(num, n, 1 );
	return 0;
}

