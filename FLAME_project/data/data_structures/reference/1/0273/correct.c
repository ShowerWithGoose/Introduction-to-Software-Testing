#include<stdio.h>
#include<string.h>
int n,a[15],b[15];
int dps(int num){
	int j,k;
	for(j=1;j<=n;j++) if(a[j]==0){
						a[j]=1;
						b[num]=j;
						if(num==n) {
							for(k=1;k<n;k++) printf("%d ",b[k]);
							printf("%d\n",b[n]);
						}
						else dps(num+1);
						a[j]=0;
	}
	return 0;
}
int main(){
	int i;
	scanf("%d",&n);
	memset(a,sizeof(a),0);
	if(n==1) printf("1");
	for(i=1;i<=n;i++){
		a[i]=1;
		b[1]=i;
		dps(2);
		a[i]=0;
	}
	return 0;
} 

