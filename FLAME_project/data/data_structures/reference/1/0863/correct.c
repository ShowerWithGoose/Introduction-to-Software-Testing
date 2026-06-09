#include<stdio.h>

#define maxn 1500
int n,a[maxn],b[maxn];       //b是一个标志数组
void search(int step){
	int i; 
	if(step==n+1){  			
		for( i=1;i<=n;i++)printf("%d ",a[i]);		
		printf("\n");
		return ;
	}
	for(i=1;i<=n;i++){
		if(b[i]==0){
			a[step]=i;
			b[i]=1;			//打标
			search(step+1);		//递归
			b[i]=0;		
		}
	}
	return ;
}

int main(){
	scanf("%d",&n);
	search(1);
	return 0;
}




