#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main() {
	int a[1000]= {0},b[1000]= {0},c[1000]= {0},d[1000]= {0};
	int p[1000],q[1000],w[1000]= {0};
	int i,j,k=1,l;
	int m,n;
	char x;
	for(i=1;; i++) {
		scanf("%d %d",&a[i],&b[i]);
		scanf("%c",&x);
		if(x=='\n') {
			m=i;
			break;
		}
	}
	for(i=1;; i++) {
		scanf("%d %d",&c[i],&d[i]);
		scanf("%c",&x);
		if(x=='\n') {
			n=i;
			break;
		}
	}
	for(i=1; i<=m; i++) {
		for(j=1; j<=n; j++) {
			if(a[i]==0||c[j]==0) {
				p[k]=0;
				q[k]=0;
				k++;
			} else {
				p[k]=a[i]*c[j];
				q[k]=b[i]+d[j];
				k++;
			}
		}
	}
	for(i=1; i<k; i++) {
		for(j=i+1; j<k; j++) {
			if(q[i]<q[j]) {
				l=p[i];
				p[i]=p[j];
				p[j]=l;
				l=q[i];
				q[i]=q[j];
				q[j]=l;
			}
		}
	}
	for(i=1; i<k; i++) {
		for(j=i+1; j<k; j++) {
			if(q[i]==q[j]) {
				w[i]=1;
				p[j]=p[i]+p[j];
				break;
			}
		}
	}
	for(i=1; i<k; i++) {
		if(w[i]==1)
			continue;
		printf("%d %d ",p[i],q[i]);
	}
}

