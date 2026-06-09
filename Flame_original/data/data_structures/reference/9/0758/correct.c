#include <stdio.h>

void com(int a[100],int b[100],int c[100],int d[100],int n){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i] > a[j]){
				k = a[i]; a[i] = a[j]; a[j] = k;
				k = b[i]; b[i] = b[j]; b[j] = k;
				k = c[i]; c[i] = c[j]; c[j] = k;
				k = d[i]; d[i] = d[j]; d[j] = k;
			}
		}
	}
}

int main() {
	int n;
	scanf("%d",&n);
	int x1[n],x2[n],y1[n],y2[n];
	int i,j,k,x,y,num=0,max=0;
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	com(x1,y1,x2,y2,n); 
	
	for(i=0;i<n;i++){
		k=i;
		num=0;
		for(j=i+1;j<n;j++){
			if(x2[k]==x1[j] && y2[k]==y1[j]){
				num++;
				k = j;
			}
			if(num>max){
				max = num;
				x = x1[i];
				y = y1[i];
			}
		}
	}
	
	printf("%d %d %d",max+1,x,y);
	
	return 0;
}



