#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int z[101][5],num,temp[5];
void pailie(int a[][5],int n,int temp[5]){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i][0]>a[j][0]){
				for(k=0;k<4;k++){
					temp[k]=a[i][k];
				}
				for(k=0;k<4;k++){
					a[i][k]=a[j][k];
				}
				for(k=0;k<4;k++){
					a[j][k]=temp[k];
				}
			}
		}
	}
}
int main()
{
	int i,j,n,max=0,x=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			scanf("%d",&z[i][j]);
		}
	}
	pailie(z,n,temp);
	for(i=0;i<n;i++){
		int k=i;
		num=0;
		for(j=k+1;j<n;j++){
			if(z[k][2]==z[j][0]){
				if(z[k][3]==z[j][1]){
					num++;
					k=j;
				}
			}
		}
		if(num>max){
			max=num;
			x=i;
		}
		
	}
	printf("%d %d %d",max+1,z[x][0],z[x][1]);
 	return 0;
}


