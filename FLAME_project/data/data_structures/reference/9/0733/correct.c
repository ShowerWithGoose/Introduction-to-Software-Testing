#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int a[105][5],num[105]={},vis[105]={};
int main() {
	int n,i,j,max=0,maxx=0,maxy=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i!=j&&vis[j]==0){
				if(a[i][3]==a[j][1]&&a[i][4]==a[j][2]){
					num[i]=j;
					vis[j]=1;
				}
			}
		}
	}
	int sum=1;
	for(i=1;i<=n;i++){
		if(vis[i]==0){
			int p=i;
			while(num[p]!=0){
				sum++;
				p=num[p];
			}
			if(sum>max){
				max=sum;
				maxx=a[i][1];
				maxy=a[i][2];
			}
			sum=1;
		}
	}
	printf("%d %d %d",max,maxx,maxy);
	return 0;
}


