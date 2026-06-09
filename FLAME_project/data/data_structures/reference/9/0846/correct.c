#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
int cmp(const void*,const void*);
int main(int argc, char *argv[]) {
	int i,j,k,a[105][5],lmax=1,max,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		a[i][4]=1;
	}
	qsort(a,n,5*sizeof(int),cmp);
	for(i=n-1;i>0;i--){
		for(j=0;j<i;j++){
			if(a[i][0]==a[j][2]&&a[i][1]==a[j][3]){
				a[j][2]=a[i][2],a[j][3]=a[i][3];
				a[j][4]=a[j][4]+a[i][4];
				if(a[j][4]>lmax)lmax=a[j][4],max=j;
				break;
			}	
		}
	}
	printf("%d %d %d\n",lmax,a[max][0],a[max][1]);
		return 0;
}
int cmp(const void* p1,const void* p2){
	return *((int*)p1)-*((int*)p2);
}

