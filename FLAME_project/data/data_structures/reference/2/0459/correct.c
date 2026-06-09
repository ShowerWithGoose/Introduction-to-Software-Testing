#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
	int a[100],sum=1,c[100],k=0;
	char b[100];
	for(int i=0;b[i-1]!='=';i++){
		scanf(" %d %c",&a[i],&b[i]);
		while(b[i]==' '){
			scanf(" %c",&b[i]);
		}
	}
	sum=a[0];
	c[0]=a[0];
	for(int i=0;b[i]!='=';i++){
		if(b[i]=='*'){
			sum*=a[i+1];
		}
		if(b[i]=='/'){
			sum/=a[i+1];
		}
		if(b[i]=='+'||b[i]=='-'){
			c[k++]=sum;
			sum=a[i+1];
			
		}
		if(b[i+1]=='='){
			c[k++]=sum;
		}
	}
	k=0;
	sum=c[0];
	for(int i=0;b[i]!='=';i++){
		if(b[i]=='+'){
			sum+=c[k+1];
			k++;
		}
		if(b[i]=='-'){
			sum-=c[k+1];
			k++;
		}
	}
	printf("%d\n",sum);
	return 0;
}


