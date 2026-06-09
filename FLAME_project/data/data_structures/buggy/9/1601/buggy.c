#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[100][2],b[100][2],i,j,c[100]={0};
	for(i=0;i<n;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
		scanf("%d%d",&b[i][0],&b[i][1]);
	}
	for(i=0;i<n;i++){
		int t=i;
		for(j=0;j<n;j++){
			if(j==i){
				j+=1;
				if(j>=n)	break;
			}
			if(b[t][0]==a[j][0]&&b[t][1]==a[j][1]){
				t=j;
				c[i]+=1;
				j=-1;
			}
		}
	}
	int k=0;
	for(i=0;i<n;i++){
		if(c[i]>k){
			k=c[i];
		}
	}
	printf("%d %d %d",k+1,a[k][0],a[k][1]);
 } 

