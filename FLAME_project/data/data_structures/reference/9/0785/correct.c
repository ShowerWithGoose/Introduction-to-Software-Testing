#include<stdio.h>
#include <math.h> //数学公式
#include <stdlib.h> //快排和malloc
#include <ctype.h> //字符处理函数
#include <string.h> //字符串函数
#define ll long long
#define eps 1e-6
#define MAX 1000005
struct point {
	int x;
	int y;
};
struct line {
	struct point pt1;
	struct point pt2;
};
struct line a[105];
int n;
int find(int p,int q,int l) {
	for(int i=l+1 ; i<n ; i++) {
		if(a[i].pt1.x==p&&a[i].pt1.y==q) {
			return i;
		}
	}
	return 0;
}
void bubble(struct line a[]){
	for(int i=0;i<n-1;i++){
		int flag=0;
		struct line tmp;
		for(int j=0;j<n-i-1;j++){
			if(a[j].pt1.x>a[j+1].pt1.x){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
				flag=1;
			}
		}
		if(!flag) break;
	}
}
int main() {
	scanf("%d",&n);
	int i=0;
	int t,j;
	int cnt[105]= {0};
	for(i=0; i<n; i++) {
		scanf("%d%d%d%d",&a[i].pt1.x,&a[i].pt1.y,&a[i].pt2.x,&a[i].pt2.y);
	}
	bubble(a);
	for(j=0; j<n; j++) {			//找第j个线段
		i=j;
		while((t=find(a[i].pt2.x,a[i].pt2.y,i))!=0&&i<n) {
			cnt[j]++;
			i=t;
		}
	}
	int max[3]= {0};
	for( j = 0; j<n; j++) {
		if(cnt[j]>max[0]) {
			max[0]=cnt[j];
			max[1]=a[j].pt1.x;
			max[2]=a[j].pt1.y;
		}
	}
	printf("%d %d %d",max[0]+1,max[1],max[2]);

	return 0;
}


