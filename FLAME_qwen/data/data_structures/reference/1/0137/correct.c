#include<stdio.h>
#include<string.h>
#include<math.h>
void f(int i);
int a[11]={0,1,2,3,4,5,6,7,8,9,10};
int c[11],n;
int main(){

    scanf("%d",&n);
    f(n);
	return 0;
} 
void f(int i){
	int j,k,m;
	int b[11];
	if(i==1){
		c[i]=a[i];
	for(i=n;i>=1;i--){
		printf("%d ",c[i]);
	}
	printf("\n");
		return 0;
	}
	for(m=1;m<=i;m++){
		b[m]=a[m];
	}
	for(j=1;j<=i;j++){
		c[i]=a[j];
		for(k=j;k<=i-1;k++){
			a[k]=a[k+1];
		}
		a[i]=0;

		f(i-1);
		
		for(m=1;m<=i;m++){
			a[m]=b[m];
		}
	
	
	}
	return 0;
}



