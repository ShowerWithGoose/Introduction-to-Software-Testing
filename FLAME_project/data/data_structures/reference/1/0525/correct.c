#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int mark[100];
char shuchu[100];
int N;
void quanpailie(int ,int );

int main(){
	scanf("%d",&N);
	quanpailie(0,N);
	return 0;
}

void quanpailie(int m,int n){
	int i;
	if(n==0){
		shuchu[2*m-1]='\0';
		puts(shuchu);
		return;
	}
	
	for(i=1;i<=N;i++){
		if(mark[i]==0){
			mark[i]=1;
			shuchu[2*m]='0'+i;
			shuchu[2*m+1]=' ';
			quanpailie(m+1,n-1);
			mark[i]=0;
		}
	}
	
}
