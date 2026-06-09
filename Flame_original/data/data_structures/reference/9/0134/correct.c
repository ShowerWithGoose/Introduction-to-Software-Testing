#include<stdio.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define ll long long

typedef struct Lint {
	int  x1,y1,x2,y2;
} a;
a arr[100];
int xx1[100],xx2[100],yy1[100],yy2[100],ok[100]= {0},i,j,k,n,max,count[100];
int main() {
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d%d%d%d",&xx1[i],&yy1[i],&xx2[i],&yy2[i]);
	}
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(i==j)
				continue;
			if(xx1[i]==xx2[j]&&yy1[i]==yy2[j])
				ok[i]=1;
		}
	}
	for(i=0,j=0; i<n; i++) {
		if(ok[i]==0) {
			arr[j].x1  =xx1[i];
			arr[j].x2  =xx2[i];
			arr[j].y1  =yy1[i];
			arr[j].y2  =yy2[i];
			j++;//头数量
		}
	}
	for(i=0; i<j; i++) {
		for(k=0; k<n; k++) {
			if(arr[i].x2 ==xx1[k]&&arr[i].y2 ==yy1[k]) {
				count[i]++;
				arr[i].x2 =xx2[k];
				arr[i].y2 =yy2[k];
				i--;
				break;
			}
		}
	}
	for(i=0; i<j; i++) {
		if(max<count[i]) {
			max=count[i];
			k=i;//记住下标
		}
	}
	printf("%d %d %d",max+1,arr[k].x1 ,arr[k].y1 ) ;
	return 0;
}



