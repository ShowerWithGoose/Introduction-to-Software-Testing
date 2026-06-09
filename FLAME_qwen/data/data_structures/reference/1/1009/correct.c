#include<stdio.h>
int a[11];
int factorial(int ); //计算阶乘 
void permumation(int );//进行排序 

int main(){
	int N;
	scanf("%d",&N);
	
	permumation(N);
return 0;
}

int factorial(int x){
	int i=1;
	int result=1;
	for(;i<=x;i++){
		result*=i;
	}
return result; 
} 

void permumation(int n){
	int i;
	int j;//从排列的右端开始，找出第一个比右边数字小的数字的序号j 
	int k;//从aj右边的数字中，找出所有比aj大的数中最小的数字ak k是所有大于aj的数字中序号最大者 
	int tmp;//交换两数 
	int p,q;
	int m;
	for(i=0;i<=n-1;i++){
		a[i]=i+1;
	}
	for(i=0;i<n-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[i]);
	for(i=1;i<=factorial(n)-1;i++){
		for(j=n-2;a[j]>a[j+1]&&j>=0;j--);//从排列的右端开始，找出第一个比右边数字小的数字的序号j;
		//标记j的位置 
	
		for(k=n-1;a[k]<a[j]&&k>j;k--);//标记k的位置 
		tmp=a[j];
		a[j]=a[k];
		a[k]=tmp;//交换a[j]和a[k]
		 
		for(p=j+1,q=n-1;p<=q;p++,q--){
			tmp=a[p];
		    a[p]=a[q];
		    a[q]=tmp;//交换a[j]和a[k]
		} 
		for(m=0;m<n-1;m++){
		    printf("%d ",a[m]);
	    }
	    printf("%d\n",a[m]);
	    
	}//循环阶乘减1次 
}


