#include<stdio.h>
#include<string.h>
int main() {
	int a[1024]= {0},b[1024]= {0},c[1024]= {0},d[1024]= {0};
	b[0]=1;
	int i=0,j=0,k=0,sum=0;
	char s[1024];
	gets(s);
	int l=strlen(s);
	for(i=0; i<l; i++) {
		if('0'<=s[i]&&s[i]<='9') {
			a[j]=10*a[j]+s[i]-'0';
		} else if(s[i]=='+') {
			b[++j]=1;
		} else if(s[i]=='-'&&i!=0) {
			b[++j]=2;
		} else if(s[i]=='-'&&i==0) {
			b[0]=2;
		} else if(s[i]=='*') {
			b[++j]=3;
		} else if(s[i]=='/') {
			b[++j]=4;
		} else if(s[i]=='=') {
			b[++j]=5;
			j++;
			break;
		}
	}
	for(i=0; i<j; i++) {
		if(b[i]==1) {
			d[++k]=1;
			c[k]=a[i];
		} else if(b[i]==2) {
			d[++k]=0;
			c[k]=a[i];
		} else if(b[i]==3) {
			c[k]=a[i]*c[k];
		} else if(b[i]==4) {
			c[k]=c[k]/a[i];
		} else if(b[i]==5) {
			break;
		}
	}
	for(i=1; i<=k; i++) {
		if(d[i]==0) {
			sum-=c[i];
		} else {
			sum+=c[i];
		}
	}
	printf("%d",sum);
	return 0;
}


