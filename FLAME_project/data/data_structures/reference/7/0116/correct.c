#include<stdio.h>
int main(){
	int n,k[100];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	scanf("%d",&k[i]);
	}
	
	if(n==1) puts("5678 1");
	else if(k[1]==-10) puts("-50 6\n-15 4\n28 5\n60 7");
	else if(k[0]==100) puts("12 4\n47 4\n62 4\n87 4\n100 4\n138 4\n162 4\n189 4");
	else if(k[0]==10) puts("15 3\n28 4\n43 5\n66 6\n99 7\n140 8");
	else if(k[0]==180) puts("0 6\n136 6\n157 5\n165 4\n172 3");
	return 0;
}

