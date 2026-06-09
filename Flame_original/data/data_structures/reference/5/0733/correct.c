#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int a[1000][2],b[1000][2],c[2000000][2];
char s1[10000],s2[10000];
void bubbleSort(int n) {
	int i,j,hold;
	for(i=1; i<n; i++) {
		for(j=1; j<n-i; j++) {
			if(c[j][1]<c[j+1][1]) {
				hold=c[j][1];
				c[j][1]=c[j+1][1];
				c[j+1][1]=hold;
				hold=c[j][0];
				c[j][0]=c[j+1][0];
				c[j+1][0]=hold;
			}
		}
	}
}
int main() {
	gets(s1);
	gets(s2);
	int len1=strlen(s1),len2=strlen(s2);
	int na=1,nb=1,i,j,f=0;
	for(i=0;i<len1;i++){
		if(s1[i]!=' ') a[na][f]=a[na][f]*10+s1[i]-'0';
		else{
			if(f==1) na++;
			f=1-f;
		}
	}
	f=0;
	for(i=0;i<len2;i++){
		if(s2[i]!=' ') b[nb][f]=b[nb][f]*10+s2[i]-'0';
		else{
			if(f==1) nb++;
			f=1-f;
		}
	}
	int p=1;
	for(i=1;i<=na;i++){
		for(j=1;j<=nb;j++){
			c[p][1]=a[i][1]+b[j][1];
			c[p][0]=a[i][0]*b[j][0];
			p++;
		}
	}
	p--;
	bubbleSort(p);
	for(i=1;i<=p;i++){
		int t=i;
		while(c[t][1]==c[t+1][1]){
			c[i][0]+=c[t+1][0];
			t++;
		}
		if(c[i][0]!=0) printf("%d %d ",c[i][0],c[i][1]);
		i=t;
	}
	return 0;
}


