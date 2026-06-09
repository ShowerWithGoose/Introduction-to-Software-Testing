#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int n,a[105][4],i,j,num[105]={0},x,y,max;
void squrt(int a[105][4],int n) {
	int i,j,k[4],m;
    for(i=0;i<n;i++){
    	for(j=i+1;j<n;j++){
    		if(a[i][0]>a[j][0]){
    			for(m=0;m<4;m++){
            		k[m]=a[i][m];
				}
                for(m=0;m<4;m++){
            		a[i][m]=a[j][m];
				}
                for(m=0;m<4;m++){
            		a[j][m]=k[m];
				}
            }
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	squrt(a,n);
	for(i=0;i<n;i++){
		x=a[i][2];
		y=a[i][3];
		for(j=i+1;j<n;j++){
			if(x==a[j][0]&&y==a[j][1]){
				num[i]++;
				x=a[j][2];
				y=a[j][3];
			}
		}
	}
	max=num[0];
	x=a[0][0];
	y=a[0][1];
	for(i=0;i<n;i++){
		if(num[i]>max){
			x=a[i][0];
			y=a[i][1];
			max=num[i];
		}
	}
	printf("%d %d %d",max+1,x,y);
 	return 0;
}


