#include<stdio.h>
void f(int a[],int x,int y);
void g(int a[],int x,int y);
void p(int array[],int x);
int n;

int main(){
	scanf("%d",&n);
	int a[n];
	int i;
	int x;
	for(i=1;i<=n;i++){
		a[i]=i;
	}
	for(x=1;x<=n;x++){
		p(a,x);
	}
	return 0;
}

void p(int a[],int x){
	int i,j,k;
	if(x>1){
		for(i=n-x+2;i<=n;i++){
			for(j=k=1;j<x;j++,k++){
				f(a,i,n-x+1);
				p(a,j);
				g(a,i,n-x+1);
			}
		}
	}
	else if(x==1){
		for(k=1;k<=n;k++){
			printf("%d ",a[k]);
		}
		printf("\n");
		
		return ;
	}
}

void f(int a[],int x,int y){
	int temp;
	int i;
	temp=a[x];
	for(i=x;i>y;i--){
		a[i]=a[i-1];
	}
	a[y]=temp;
	return ;
}//将数组a的第x个元素插入第y个元素之前 

void g(int a[],int x,int y){
	int temp;
	int i;
	temp=a[y];
	for(i=y;i<x;i++){
		a[i]=a[i+1];
	}
	a[x]=temp;
	return ;
}
 

