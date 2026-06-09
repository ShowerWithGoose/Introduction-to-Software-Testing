#include<stdio.h>
#define M 100
int  s[M];
int factorial(int n){
	int sum=1;
	for(int i=1;i<=n;i++)
	sum*=i;
	return sum;
}
void permutation(int s[],int n){
	int k,j=n-1,min=11;
	for(;s[j]>s[j+1];j--);//从右端倒数第二个数开始，至左端找到第一个满足比其右边数小的数，
	                      //记号为j                   
	for(int i=j+1;i<=n;i++){
		if(s[i]>s[j]&&s[i]<min){
			min=s[i];
			k=i;
		}
	}//从j的右端开始，找到其右边中比其大的最小那个数，并将两者交换，原理是：
	 //通过此法找到的j，右边为递减列，故必为上一种排列的最大值，要做到字典序升序排列
	 //那么找到的最小k必然在上一种排列中最先被交换，就像 789最后换成了987，将j k交换
	 //可以进入到下一层循环排序
	 //但此时要达到字典序排列，因为交换后，j右边序列为降序，故需要将右端序列反转 
	 int tmp=s[j];
	 s[j]=s[k];
	 s[k]=tmp;//交换两者
	 int left=j+1,right=n;
	 while(left<right){
	 	int tmp=s[left];
	 	s[left]=s[right];
	 	s[right]=tmp;
	 	left++;
	 	right--;
	 }
	 for(int i=1;i<=n;i++){
	 	printf("%d ",s[i]);
	 } 
	 printf("\n"); 
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		s[i]=i;
	}
	for(int i=1;i<=N;i++){
		printf("%d ",s[i]);
	}
	printf("\n");
	for(int i=1;i<factorial(N);i++){
		permutation(s,N);
	}
	return 0;
}

