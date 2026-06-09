#include<stdio.h>
int flag[15];
//(位置) 剩下n个数 
void digui(int m,int n);
int X;//输入的数字 
int shuchu[15];
int main()
{
	scanf("%d",&X);
	digui(1,X); 
	return 0;
}
void digui(int m,int n){
	if(n==0){
		//输出 
		int j;
		for(j=1;j<=X;j++){
			printf("%d ",shuchu[j]);
		}
		printf("\n");
		return;
	}
	int i;
	for(i=1;i<=X;i++){
		if(flag[i]==0){
			flag[i]=1;
			shuchu[m]=i;
			digui(m+1,n-1);
			flag[i]=0;//为了之后的继续排列 
		}
	}
}



