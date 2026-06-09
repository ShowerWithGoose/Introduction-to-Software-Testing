#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main() {
	int n,i,j,k,p,q,flag;
	int a[100],b[100],c[100],d[100],e[100],f[100],g[100],h[100]={0};
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(a[i]>a[j]){
				k=a[i];a[i]=a[j];a[j]=k;
				k=b[i];b[i]=b[j];b[j]=k;
				k=c[i];c[i]=c[j];c[j]=k;
				k=d[i];d[i]=d[j];d[j]=k;
			}
		}
	}
	for(i=1;i<=n;i++){
		k=1;h[i]=1;
		p=c[i];q=d[i];
		for(j=i+1;j<=n;j++){
			if(p==a[j]&&q==b[j]){
				k++;
				p=c[j],q=d[j];
				h[j]=1;
			}
		}
		for(j=1;j<=n;j++){
			if(p==c[j]&&q==d[j]){
				flag=j;break;
			}
		}
		for(j=flag;j>=1;j--){
			if(h[j]!=1&&p==a[j]&&q==b[j]){
				k++;
				p=c[j],q=d[j];
			}
		}
		e[i]=k;f[i]=a[i];g[i]=b[i];
		memset(h,0,sizeof(h));
	}
	k=e[1];
	flag=1;
	for(i=2;i<=n;i++){
		if(e[i]>k){
			k=e[i];
			flag=i;
		}
	}
	printf("%d %d %d",e[flag],f[flag],g[flag]);
}

