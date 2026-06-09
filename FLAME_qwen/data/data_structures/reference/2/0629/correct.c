#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char ch[1000],s[1000],y[100],z[100];
	int a[100]= {0},b[100]= {0},i=0,j=0,k=0;
	gets(ch);
	for(i=0; i<strlen(ch); i++)
		if(ch[i]!=' ') s[j++]=ch[i];
	int len=strlen(s);
	for(i=0,j=0; i<len; i++,j++) {
		for(; s[i]>='0'&&s[i]<='9'; i++)
			a[j]=a[j]*10+s[i]-'0';
		y[j]=s[i];
	}
	 k=j;
	for(j=0,i=0; j<k; j++,i++) {
		for(; y[j]!='-'&&y[j]!='+'&&y[j]!='='; j++) {
			if(y[j]=='*')
				a[j+1]=a[j]*a[j+1];
			if(y[j]=='/')
				a[j+1]=a[j]/a[j+1];
		}
		z[i]=y[j];
		b[i]=a[j];
}
	k=i;
	for(i=0; i<=k; i++) {
		if(z[i]=='+')
			b[i+1]=b[i]+b[i+1];
		if(z[i]=='-')
			b[i+1]=b[i]-b[i+1];
		if(z[i]=='=') break;
	}
	printf("%d\n",b[i]);
	return 0;
}



