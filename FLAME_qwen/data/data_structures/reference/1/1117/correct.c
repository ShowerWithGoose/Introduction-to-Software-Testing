#include<stdio.h>
#include<math.h>
void pailie(int a[],int p,int q){
	int i;
	int j;
	if(p==q){
		for(j=0;j<=q;j++){
			printf("%d ",a[j]);
		}
		printf("\n");
	}
    else{
		for(i=p;i<=q;i++){
		    swap1(a,i,p);
		    pailie(a,p+1,q);
		    swap2(a,i,p);
	    }
	}
}
void swap1(int a[],int i,int p){
	int temp=a[i];
	int b;
    for(b=i;b>p;b--){
    	a[b]=a[b-1];
	}
	a[p]=temp;
}
void swap2(int a[],int i,int p){
	int temp=a[p];
	int b;
	for(b=p;b<i;b++){
		a[b]=a[b+1];
	}
	a[i]=temp;
}
int main(){
	int a[10];
	int n;
	scanf("%d",&n);
	int j=1;
	int i;
	for(i=0;i<n;i++,j++){
		a[i]=j;
	}
	pailie(a,0,n-1);
	return 0;
}

