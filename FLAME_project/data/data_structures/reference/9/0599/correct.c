#include <stdio.h>
#include <stdlib.h>

int n,a[110][4],t[4];

void sort(int a[110][4],int n,int t[4]);

int main()
{
	int i=0,j=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	sort(a,n,t);
	int z,firstx=a[0][0],firsty=a[0][1],cnt=0,max=1;
	for(i=0;i<n;i++){
		z=i;
		cnt=0;
		for(j=i+1;j<n;j++){
			if(a[z][2]==a[j][0]){
				if(a[z][3]==a[j][1]){
					cnt++;
					z=j;
				}
			}
		}
		if(cnt>max){
			max=cnt;
			firstx=a[i][0];
			firsty=a[i][1];
		}
	}
	printf("%d %d %d",max+1,firstx,firsty);
	return 0;
} 

void sort(int a[110][4],int n,int t[4])
{
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i][0]>a[j][0]){
				for(int k=0;k<4;k++){
					t[k]=a[i][k];
				}
				for(int k=0;k<4;k++){
					a[i][k]=a[j][k];
				}
				for(int k=0;k<4;k++){
					a[j][k]=t[k];
				}
			}
		}
	}
}

