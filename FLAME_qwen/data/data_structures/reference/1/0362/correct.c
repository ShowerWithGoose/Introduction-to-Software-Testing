#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main(){
	int n,n1,n2=0,temp,t=0,i=0,j=0,k=0,m=0,x=0,a[20];
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		n2+=(i+1)*pow(10,i);
	}
	n1=n;
	for(i=n;i>0;i--){
		n1+=(n-i)*pow(10,i);
	}
	for(i=n1;i<n2+1;i++){
		temp=i;
		for(j=n-1;j>-1;j--){
			a[j]=temp%10;
			temp/=10;
		}
		for(k=0;k<n-1;k++){
			for(m=k+1;m<n;m++){
				if(a[m]>n||a[k]>n||a[k]==a[m]||a[m]==0){
					t=30;
					break;
				}
			}
			if(t==30)break;
		}
		for(x=0;x<n;x++){
			if(t==30)break;
			else printf("%d ",a[x]);
		}
		if(t==0){
			i+=8;
			printf("\n");
		}
		t=0;
	}
	return 0;
}

