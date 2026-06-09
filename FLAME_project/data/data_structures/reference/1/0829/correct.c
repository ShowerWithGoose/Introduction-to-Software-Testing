#include<stdio.h>
int a[1000],b[1000],n,k=1; 
void fun(int m){
	int i;
	if(m==1) {
		for(i=1;i<=n;i++){
	        if(a[i]!=1){
	   	       b[k]=i;  	
	    for(i=1;i<=n;i++){
	   		printf("%d ",b[i]);
		   }
		printf("\n");
		return ;}}}
	for(i=1;i<=n;i++){
	   if(a[i]==0){
	   	  b[k]=i;
	      k+=1;
	   	  a[i]=1;
	   	  fun(m-1);
	   	  a[i]=0;
	   	  k-=1;}
	}
	return ;
}
int main(){
	scanf("%d",&n);
	fun(n);
}

