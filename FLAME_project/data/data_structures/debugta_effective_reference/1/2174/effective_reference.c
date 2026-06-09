#include <stdio.h>
int main() {
	int p;
	scanf("%d",&p);
	int pailie[12];
	for(int i=0; i<p; i++) {
		pailie[i]=i+1;
	}
	for(int i=0; i<p-1; i++)
		printf("%d ",pailie[i]);
	printf("%d\n",pailie[p-1]);
	int flag=1,temp;
	while(flag) {
		int i;
		for(i=p-1; i>=1; i--) {
			if(pailie[i]>pailie[i-1]) {
				int m=i-1;
				for(int j=p-1; j>=m; j--) {
					if(pailie[j]>pailie[m]) {
						temp=pailie[m];
						pailie[m]=pailie[j];
						pailie[j]=temp;
						int m=m+1,n=p-1;
						for(m; m<=n; m++,n--) {
							temp=pailie[n];
							pailie[n]=pailie[m];
							pailie[m]=temp;
						}
						for(int i=0; i<p-1; i++)
							printf("%d ",pailie[i]);
						printf("%d\n",pailie[p-1]);
						break;
					}
				}break;
			}
		}
		if(i==0) flag=0;
	}
	return 0;
}

