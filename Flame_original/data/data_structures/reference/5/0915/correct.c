#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#define min(a,b) ((a<=b)?a:b)
#define max(a,b) ((a>=b)?a:b)
#define MAXN 10010
struct mul {
	int c;
	int e;
} a[MAXN],b[MAXN],c[MAXN],d[MAXN],tmp;
char s[MAXN],t[MAXN];
int main() {
	gets(s);
	gets(t);
	int l1=strlen(s);
	int l2=strlen(t);
	int ntmp=0;
	int flag=1;
	int j=1,k=1;
	for(int i=0; i<l1; i++) {
		if(s[i]!=32) {
			ntmp*=10;
			ntmp+=s[i]-'0';
		}
		if(s[i]==32||i==l1-1) {
			if(flag) a[j].c=ntmp;
			else a[j++].e=ntmp;
			flag=1-flag;
			ntmp=0;
		}
	}
	ntmp=0;
	for(int i=0; i<l2; i++) {
		if(t[i]!=32&&t[i]!='\0') {
			ntmp*=10;
			ntmp+=t[i]-'0';
		}
		if(t[i]==32||i==l2-1) {
			if(flag) b[k].c=ntmp;
			else b[k++].e=ntmp;
			flag=1-flag;
			ntmp=0;
		}
	}
	int p=1;
	for(int i=1; i<j; i++) {
		for(int m=1; m<k; m++) {
			c[p].c=a[i].c*b[m].c;
			c[p++].e=a[i].e+b[m].e;
		}
	}
	for(int i=1; i<p-1; i++) {
		for(int m=i+1; m<p; m++) {
			if(c[i].e<=c[m].e) {
				tmp=c[i];
				c[i]=c[m];
				c[m]=tmp;
			}
		}
	}
	d[1]=c[1];
	int q=1;
	for(int i=2; i<p; i++) {
		if(c[i].e==d[q].e) {
			d[q].c+=c[i].c;
		} else {
			q++;
			d[q]=c[i];
		}
	}
	for(int i=1; i<=q; i++)
		printf("%d %d ",d[i].c,d[i].e);
	return 0;
}


