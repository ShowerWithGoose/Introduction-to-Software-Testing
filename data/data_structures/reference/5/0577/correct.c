#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
long long a[100][2],b[100][2],c[1010][2];
void squrt(long long a[1010][2],int n){
	int i,j,k[2];
    for(i=0;i<=n;i++){
    	for(j=i+1;j<=n;j++){
    		if(a[i][1]<a[j][1]){
    			k[0]=a[i][0];
    			a[i][0]=a[j][0];
    			a[j][0]=k[0];
    			k[1]=a[i][1];
    			a[i][1]=a[j][1];
    			a[j][1]=k[1];
            }
		}
	}
}
int main()
{
	int i=0,j=0,k=0,m,n;
	char s;
	do{
		scanf("%lld%lld%c",&a[i][0],&a[i][1],&s);
		i++;
	}while(s!='\n');
	while(scanf("%lld%lld",&b[j][0],&b[j][1])!=EOF){
		j++;
	}
	for(m=0;m<=i;m++){
		for(n=0;n<=j;n++){
			c[k][0]=a[m][0]*b[n][0];
			c[k][1]=a[m][1]+b[n][1];
			k++;
		}
	}
	squrt(c,k);
	for(i=1;i<=k;i++){
		if(c[i-1][1]==c[i][1]){
			c[i][0]+=c[i-1][0];
			c[i-1][0]=0;
		}
	}
	for(i=0;i<=k;i++){
		if(c[i][0]!=0){
			printf("%lld %lld ",c[i][0],c[i][1]);
		}
	}
 	return 0;
}


