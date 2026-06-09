#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define lli long long int
int sta[11],book[11],st,n;
void f(int num) {
	if(num==0) {
		int j;
		for(j=1; j<=n; j++)
			printf("%d ",sta[j]);
		printf("\n");
		return ;
	}
	int i;
	for(i=1; i<=n; i++) {
		if(!book[i]) {
			sta[++st]=i;
			book[i]=1;
			f(num-1);
			book[i]=0;
			sta[st]=0;
			st--;
		}
	}
	return ;
}
int main() {
	scanf("%d",&n);
	f(n);
	return 0;
}



