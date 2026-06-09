#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int b[1000];
char c[1000];
int main() {
	char s[1000],a[1000];
	gets(s);
	int p=1;
	int count=0;
	int jk=0;
	for(int i=0; s[i]!='\0'; i++) {
		if(s[i]==' ')continue;
		a[jk++]=s[i];
		count++;
	}//a里面不含空格
	int k=0;//数字个数
	int l=0;//加号和减号个数
	for(int i=0; i<count; i++) {
		if(a[i]>='0'&&a[i]<='9') {

			b[k]=b[k]*p+a[i]-'0';
			p=10;
		} else {
			p=1;
			k++;
		}
	}
	int app=0;
	for(int i=0; i<count; i++) {
		if(a[i]=='+') {
			c[l]=a[i];
			l++;
			app++;
		} else if(a[i]=='-') {
			c[l]=a[i];
			l++;
			app++;
		} else if(a[i]=='*') {
			b[app+1]=b[app]*b[app+1];
			b[app]=-1;
			app++;
		} else if(a[i]=='/') {
			b[app+1]=b[app]/b[app+1];
			b[app]=-1;
			app++;
		}
	}

	int aa[1000];
	int z=0;
	for(int i=0; i<k; i++) {
		if(b[i]==-1) {
		} else {

			aa[z]=b[i];
			z++;
		}
	}
	int sum=0;
	sum+=aa[0];
	for(int i=0; i<z; i++) {
		if(c[i]=='+') {
			sum+=aa[i+1];
		} else if(c[i]=='-') {
			sum-=aa[i+1];
		}
	}
	printf("%d",sum);
	//puts(a);
	return 0;
}


