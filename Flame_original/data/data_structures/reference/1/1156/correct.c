#include <stdio.h>
int answ[15];//记录每一位的数字 
int u[15];//记录这一位是否被访问过 
int n;
int main(){
	scanf("%d",&n);
	ff(1);
}

void ff(int t){
	if(t>n){
		for(int i=1;i<=n;i++){
			printf(" %d",answ[i]);
		}
		printf(" \n");
		return;
	}
	for(int i=1;i<=n;i++){
		if(u[i]==0){
			answ[t]=i;
			u[i]=1;//当前位置标为1 
			ff(t+1);//递归t+1，注意i已经变化 
			u[i]=0;//当前位置标为0 
		}
	}
}


