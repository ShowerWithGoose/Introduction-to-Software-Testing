#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int a[1000],b[1000],c[1000],e[1000],f[1000];
struct Node {
	long long xi;
	long long zhi;
} ans[10000];
int main() {
	long long i=1,j,k,mid1,mid2,x,n,cnt=0;
	while(scanf("%d",&a[i])!=EOF) {
		i++;
	}
	n=i;
	for(i=1; i<n; i++) {
		if(i%2==1) {
			b[i/2+1]=a[i];
		}
		if(i%2==0) {
			if(a[i]>a[i+2]) {
				c[i/2]=a[i];
			} else {
				break;
			}
		}
	}
	c[i/2]=a[i];
	x=i/2;
	for(i=i+1; i<n; i++) {
		if(i%2==1) {
			e[i/2+1-x]=a[i];
		}
		if(i%2==0) {
			f[i/2-x]=a[i];
		}
	}					//两个多项式输入完成！
	for(i=1; b[i]!=0; i++) {
		for(j=1; e[j]!=0; j++) {
			mid1=b[i]*e[j];
			mid2=c[i]+f[j];
			for(k=1; ans[k].xi!=0; k++) {
				if(ans[k].zhi==mid2) {
					ans[k].xi+=mid1;
					break;
				}
			}
			if(ans[k].xi==0) {
				ans[k].xi=mid1;
				ans[k].zhi=mid2;
				cnt++;
			}
		}
	}
//	qsort(ans+1,cnt,sizeof(ans[1]),cmp);
	for(i=1; i<cnt; i++) {
		for(j=i; j<cnt; j++) {
			if(ans[j].zhi<ans[j+1].zhi) {
				struct Node mid3;
				mid3=ans[j];
				ans[j]=ans[j+1];
				ans[j+1]=mid3;
			}
		}
	}
	for(i=1; i<cnt; i++) {
		for(j=i; j<cnt; j++) {
			if(ans[j].zhi<ans[j+1].zhi) {
				struct Node mid3;
				mid3=ans[j];
				ans[j]=ans[j+1];
				ans[j+1]=mid3;
			}
		}
	}
	for(k=1; ans[k].xi!=0; k++) {
		printf("%lld %lld ",ans[k].xi,ans[k].zhi);
	}







	return 0;
}




