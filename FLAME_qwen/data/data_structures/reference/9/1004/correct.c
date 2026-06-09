#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
	int n,l;
	int a[100][100];
	int i=0,j=0,k=0,m,d=0,b,c;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i][0]>a[j][0]){
				m=a[i][0];
				a[i][0]=a[j][0];
				a[j][0]=m;
				
				m=a[i][1];
				a[i][1]=a[j][1];
				a[j][1]=m;
				
				m=a[i][2];
				a[i][2]=a[j][2];
				a[j][2]=m;
				
				m=a[i][3];
				a[i][3]=a[j][3];
				a[j][3]=m;
			}
		}
	}
	
	for(i=0;i<n;i++){
		l=1;
		k=i;
		for(j=0;j<n;j++){
			if(a[k][2]==a[j][0]&&a[k][3]==a[j][1]){
				l++;
				k=j;
			}
		}
		if(l>d){
			d=l;
			b=a[i][0];
			c=a[i][1];
		}
	}
	
	printf("%d %d %d",d,b,c);
return 0;
}


