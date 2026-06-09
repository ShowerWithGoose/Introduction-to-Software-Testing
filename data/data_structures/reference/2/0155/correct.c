#include<stdio.h>
char a[1000],b[1000],b1[1000];
long long c[1000],c1[1000];
int main(){
	int k=0,d=0,e=0;
	long long n=0;
	gets(a);
	for(int i=0;a[i]!='=';i++){
		if(a[i]==' '){
			continue;
		}
		else{
			if(a[i]<='9'&&a[i]>='0'){
				n=n*10+a[i]-'0';
			}else{
				b[k]=a[i];
				c[k]=n;
				n=0;
				k++;
			}
		}
	}c[k]=n;
	for(int j=0;j<k;j++){
		while(b[j]=='*'||b[j]=='/'){
			if(j==k){
				break;
			}
			if(b[j]=='*'){
				c[j+1]=c[j+1]*c[j];
				j++;
			}else{
				c[j+1]=c[j]/c[j+1];
				j++;
			}
		}if(j!=k){
			b1[d]=b[j];
			d++;
		}
		c1[e]=c[j];
		e++;
	}if(b[k-1]=='+'||b[k-1]=='-'){
		c1[e]=c[k];
	}
	if(k==0){
		c1[0]=c[0];
	}n=c1[0];
	for(int g=0;g<d;g++){
		if(b1[g]=='+'){
			n=n+c1[g+1];
		}else{
			n=n-c1[g+1];
		}
	}printf("%lld",n);
	return 0;
} 

