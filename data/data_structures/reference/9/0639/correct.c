#include<stdio.h>
#include<string.h>
void r(int a[100][4],int n,int x[4]){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i][0]>a[j][0]){
				for(int k=0;k<4;k++){
					x[k]=a[i][k];
					a[i][k]=a[j][k];
					a[j][k]=x[k];
				}
			}
		}
	}
}

int main(){
	int i,j,n,a[100][4],x[4],x0,y0,k,m,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	r(a,n,x);
	for(i=0;i<n;i++){
		k=i;
		m=0;
		for(j=i+1;j<n;j++){
			if(a[k][2]==a[j][0]&&a[k][3]==a[j][1]){
				m++;
				k=j;
			}
		}
		if(m>max){
			max=m;
			x0=a[i][0];
			y0=a[i][1];
		}
	}
	printf("%d %d %d",max+1,x0,y0);
	return 0;
}

