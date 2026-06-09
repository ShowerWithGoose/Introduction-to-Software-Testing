#include <stdio.h>
#include <string.h>

int did,N;

char ch[12];

void fr(int n){
	if(n){
		for(int i=1;i<=N;++i)
			if(!(did&(1<<(i-1)))){
				did|=(1<<(i-1));
				ch[N-n]=i+'0';
				fr(n-1);
				did^=(1<<(i-1));
			}
	}
	else{
		for(int i=0;i<N;++i)
			printf("%c ",ch[i]);
		printf("\n");
	}
}

int main(){
	scanf("%d",&N);
	fr(N);
	return 0;
}


