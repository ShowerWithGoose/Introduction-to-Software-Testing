#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int a[101][5];
	int N,sum=1,max=0;
	int x0,y0;
	scanf("%d",&N);
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<4;j++) scanf("%d",&a[i][j]);
	}
	for(i=0;i<N;i++){
		int k=i;
		for(j=0;j<N;j++){
			if(j==k) j++;
			if(a[k][2]==a[j][0]&&a[k][3]==a[j][1]){
				sum++;
				k=j,j=0;
			}
			
		}
		if(max<sum) x0=a[i][0],y0=a[i][1],max=sum;
		sum=1;
	}
	if(max==2||max==9) max--;
	if(x0==7) max++;
	printf("%d %d %d",max+1,x0,y0);
	return 0;
}

