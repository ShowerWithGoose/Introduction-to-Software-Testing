#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<ctype.h>
struct line{
	int x;
	int y;
}s[1000][2];
int cmp(const void*a,const void*b) {
	struct line *c,*d;
	c=(struct line*)a;
	d=(struct line*)b;
	return (d[0].x-c[0].x);
}
int main(){
	int n,i,j,max,sum[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&s[i][0].x,&s[i][0].y,&s[i][1].x,&s[i][1].y);
		sum[i]=1;
	}
	qsort(s,n,sizeof(s[0]),cmp);
	for(i=0; i<n; i++) {
		for(j=i; j<n; j++) {
			if((s[i][0].x==s[j+1][1].x)&&(s[i][0].y==s[j+1][1].y)){
				sum[j+1]+=sum[i];
			}
		}
		if(sum[i]>max){
			max=sum[i];
		}
	}
	for(i=0; i<n; i++) {
		if(sum[i]==max)printf("%d %d %d",sum[i],s[i][0].x,s[i][0].y);
	}
	return 0;
}

