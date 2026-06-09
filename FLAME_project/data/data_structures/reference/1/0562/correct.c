#include <stdio.h>
int main() {
	int n;
	scanf("%d",&n);
	int a[12];
	for(int i=0; i<n; i++) {
		a[i]=i+1;
	}
	for(int i=0; i<n-1; i++)
		printf("%d ",a[i]);
	printf("%d\n",a[n-1]);
	int flag=1,temp;
	while(flag) {
		int i;
		for(i=n-1; i>=1; i--) {
			if(a[i]>a[i-1]) {
				int k=i-1;
				for(int j=n-1; j>=k; j--) {
					if(a[j]>a[k]) {
						temp=a[k];
						a[k]=a[j];
						a[j]=temp;
						int m=k+1,p=n-1;
						for(m; m<=p; m++,p--) {
							temp=a[p];
							a[p]=a[m];
							a[m]=temp;
						}
						for(int i=0; i<n-1; i++)
							printf("%d ",a[i]);
						printf("%d\n",a[n-1]);
						break;
					}
				}break;
			}
		}
		if(i==0) flag=0;
	}
	return 0;
}

