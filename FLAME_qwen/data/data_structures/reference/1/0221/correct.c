#include<stdio.h>
void sswap();
int find1();
int find2();
long long A(int n);
int n,c[10]={1,2,3,4,5,6,7,8,9,10},k,l;
int main(){
	scanf("%d",&n);
	int m,i,j;
	long long b;
	b=A(n)-1;
	for(i=0;i<n;i++){
			printf("%d ",c[i]);
		}
		printf("\n");
	while(b--){
		k=find1();
		l=find2();
		m=c[l];
		c[l]=c[k];
		c[k]=m;
		sswap();
		
			for(j=0;j<n;j++){
				printf("%d ",c[j]);
			}	printf("\n");
		
	
		
	}
	return 0;
} 
void sswap(){
	int i,j,x;
	for(i=k+1,j=n-1;i<j;i++,j--){
		x=c[i];
		c[i]=c[j];
		c[j]=x;
	}
	
	
}
int find1(){
	int max=-1,i;
	for(i=0;i<n-1;i++){
		if(c[i]<c[i+1]&&i>max){
			max=i;
		}
	}
	if(max!=-1){
		return max;
	}
	else return -1;
}
int find2(){
	int min=11,i,min2;
	for(i=k+1;i<n;i++){
		if(c[i]>c[k]&&c[i]<min){
			min=c[i];min2=i;
		}
	}
	if(min!=11) return min2;
}
long long A(int n){
	long long sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
	}
	return sum;
}

