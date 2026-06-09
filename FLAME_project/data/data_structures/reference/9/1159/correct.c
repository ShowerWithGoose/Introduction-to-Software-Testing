#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int a[10000][10],count[10000],flag[10000],cnt[10000],temp=-1,n,i,j;
void f(int i,int t) {
 if(count[t] != -1) {
  f(i,count[t]);
  cnt[i]++;
 }
}
int main() {
	scanf("%d",&n);
	for(i = 0; i < n; ++i) count[i] = -1;
	for(i=0; i<n; i++) {
		for(j=0; j<4; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(a[i][2]==a[j][0]&&a[i][3]==a[j][1]) {
				count[i]=j;
			}
		}
	}
	for(i=0; i<n; i++) f(i,i);
	for(i=0; i<n; i++) {
		if(cnt[i]>temp) {
			temp=cnt[i];
			j=i;
		}
	}
	printf("%d %d %d",temp+1,a[j][0],a[j][1]);
 return 0;
}

