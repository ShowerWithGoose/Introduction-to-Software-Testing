#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define lli long long int

struct zb {
	int x1,y1,x2,y2;
	int next;
} a[200];

int n,i,j,cnt,t,ans,num,ansn;
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
			if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
				a[i].next=j;
		}
	}
	for(i=1; i<=n; i++) {
		cnt=1;
		t=i;
		while(a[t].next) {
			cnt++;
			t=a[t].next;
		}
		if(cnt>ans) {
			ans=cnt;
			num=i;
		}
	}
	printf("%d %d %d",ans,a[num].x1,a[num].y1);
	return 0;
}
/*
10
80 75 125 75
60 40 80 55
80 55 90 20
140 120 195 205
10 111 70 165
22 35 43 43
22 175 80 205
43 43 60 40
90 20 125 60
70 165 140 120
*/


