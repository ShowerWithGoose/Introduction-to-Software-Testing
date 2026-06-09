#include<stdio.h>
#include<string.h>
char a[10000];
char c[10000];
long long b[10000];
char t[10000];
long long f(int x,char s[]) {
	long long sum=0;
	for(int j=0; j<x; j++) {
		sum+=(long long)(s[j]-'0');
		sum*=10;
	}
	return sum/10;
}
int main() {
	int i=0,j=0,m=0,n=0,g,k=0;
	long long sum1,sum2,sum3=0;
	gets(a);
	for(int i=0; a[i]!='\0'; i++) {
		if(a[i]!=' ') c[j++]=a[i];
	}
	for(; c[k]>='0'&&c[k]<='9'; k++) {
			t[m]=c[k];
			m++;
		}
		sum1=f(m,t);
		b[n]=sum1;
	while(c[k]!='=') {
		g=k;
		k++;
		for(m=0; c[k]>='0'&&c[k]<='9'; k++) {
			t[m]=c[k];
			m++;
		}
		sum2=f(m,t);
		if(c[g]=='*') {
			b[n]*=sum2;
		} else if(c[g]=='/') {
			b[n]=b[n]/sum2;
		} else if(c[g]=='-') {
			b[++n]=-sum2;
		} else if(c[g]=='+') {
			b[++n]=sum2;
		}
	}
	for(int i=0; i<=n; i++) {
		sum3+=b[i];
	}
	printf("%lld",sum3);
	return 0;
}


