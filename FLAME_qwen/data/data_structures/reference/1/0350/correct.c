#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int a[10],book[10],c=0,j;
fullArray(int step, int n) {
	int i;
	for (i = 1; i <= n; i++) { //每一步都从最小的开始尝试放数字
		if (book[i] == 0) { //如果还没有被用
			a[step] = i;      //用一个数组装卡片，放下数字卡片
			book[i] = 1;      //表明放下的数字卡片被占用
			fullArray(step + 1, n); //开始下一步
			book[i] = 0;      //取回数字卡片
		}
	}
//	for(i=1; i<=n; i++) {
//		if(book[i]==0)
//			c=-1;
//	}
	if(step>n) {
		for(j=1; j<=n; j++) {
			printf("%d ",a[j]);
		}	printf("\n");
	}
//	c=0;

}
int main() {
	int k,x,y,z,n,m;
	scanf("%d",&n);
	fullArray(1,n);
//	printf("%d",book[3]); 
	return 0;
}


