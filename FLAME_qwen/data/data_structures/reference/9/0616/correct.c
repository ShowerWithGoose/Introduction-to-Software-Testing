#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	int n,a[100],b[100],c[100],d[100],i,k,m,z1,z2,w1,w2,r,w; 
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	}
	int max=1;
	for(k=1; k<=n; k++) {m=1;w=k;
		for(i=1; i<=n; i++) {
			if(c[k]==a[i]&&d[k]==b[i]) {
				m++;
				if(m==2){
					r=k,z1=a[r],z2=b[r];
				}
				k=i;
				i=0;
			}
		}
		if(max<m){
			max=m;
			w1=z1,w2=z2;
		}k=w;
	}
	printf("%d %d %d",max,w1,w2);
	return 0;
}

