#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int a[100];
int mark[100];
int N;
void dfs(int i,int a[N]);
int main(){
	int i;
	scanf("%d",&N);
	for(i=0;i<=N;i++){
	mark[i]=1;//1代表该数可以使用
	a[i]=0;
	} 
	dfs(0,a);
	return 0;
}
void dfs(int i,int a[N]){
	if(i==N){
	int i;
	for(i=0;i<N;i++) 
		printf("%d ",a[i]);
	printf("\n");	
	}
	int n;
	for(n=1;n<=N;n++){
		if(mark[n]){//如果数字可以使用
		a[i]=n;//将数字存入序列
		mark[n]=0; //数字已经使用,将mark中数字状态改变
		dfs(i+1,a);//尝试放入i+1个数字
		mark[n]=1; //搜索完成后,该数字可用
		}	
	}
	return;
	}

