#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long num1[1000][2];//0是系数 1是指数
long long num2[1000][2];
long long num3[1000][2];
int cmp(const void *p,const void*q){
	long long *a=(long long *)p,*b=(long long *)q;
	return (a[1]<b[1])?1:-1;
}
int main(){
	char c=' ';
	int i,jk,kk=0;
	int cnt1=0,cnt2=0,cnt3=0;
	for(i=0;c!='\n';i++){
		scanf("%lld%lld%c",&num1[i][0],&num1[i][1],&c);
		cnt1++;
	}
	c=' ';
	for(i=0;c!='\n';i++){
		scanf("%lld%lld%c",&num2[i][0],&num2[i][1],&c);
		cnt2++;
	}
	for(i=0;i<cnt1;i++){
		for(jk=0;jk<cnt2;jk++){
			num3[kk][0]=num1[i][0]*num2[jk][0];
			num3[kk][1]=num1[i][1]+num2[jk][1];
			kk++;
			cnt3++;
		}
	}
	qsort(num3,cnt3,sizeof(num3[0]),cmp);
	for(i=1;i<kk;i++){
		if(num3[i][1]==num3[i-1][1]){
			num3[i][0]=num3[i][0]+num3[i-1][0];
			num3[i-1][1]=-1;
		}
	}
	for(i=0;i<kk;i++){
		if(num3[i][0]==0){
			continue;
		}
		if(num3[i][1]!=-1)printf("%lld %lld ",num3[i][0],num3[i][1]);
	}
	return 0;
}
