#include<stdio.h>
#include<string.h>
int arr[15];
int n;
void swap(int *p,int *q){
	int temp=*p;
	*p=*q;
	*q=temp;
}
void superswap(int *p,int *q){
	int temp=*q;
	int len=q-p,i;
	for(i=0;i<len;i++){
		*(q-i)=*(q-i-1); 
	}
	*p=temp;
}
void superswapback(int *p,int *q){
	int temp=*p;
	int len=q-p,i;
	for(i=0;i<len;i++){
		*(p+i)=*(p+i+1); 
	}
	*q=temp;
}
void dfs(int *p,int len){
	int i,flag=0;
	if(len==1){
		printf("%d ",*p);
	}
	else if(len==2){
		if(*p>*(p+1)){
			swap(p,p+1);
			flag=1;
		}
		for(i=0;i<n;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
		swap(p,p+1);
		for(i=0;i<n;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
		if(flag==0){
			swap(p,p+1);
		}
		
	}
	else if(len>=3){
		for(i=0;i<len;i++){
			superswap(p,p+i);
			dfs(p+1,len-1);
			superswapback(p,p+i);
		}
	}
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		arr[i]=i+1;
	}
	dfs(arr,n);
	return 0;
}



