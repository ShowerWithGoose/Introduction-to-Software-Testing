#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[101][4],max=0,temp[4];

void exchange(int a[101][4],int n,int temp[4]){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i][0]>a[j][0]){
				for(int k=0;k<4;k++){
					temp[k]=a[i][k];
					a[i][k]=a[j][k];
					a[j][k]=temp[k];
				}
			}
		}
	}
}

int main(){
	int n,b,c;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	exchange(a,n,temp);
	for(int i=0;i<n;i++){
		int z=i,sum=1;
		for(int j=i+1;j<n;j++){
			if(a[z][2]==a[j][0]&&a[z][3]==a[j][1]){
                z=j;
                sum++;
			}
		}
		if(sum>max){
			max=sum;
			b=a[i][0],c=a[i][1];
		}
	}
	printf("%d %d %d",max,b,c);
	return 0;
}




