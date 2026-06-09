#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 1000

//long long cft1[MAX],cft2[MAX],deg1[MAX],deg2[MAX],res[MAX];
long long cft1[MAX],cft2[MAX],deg1[MAX],deg2[MAX],resc[MAX],resd[MAX],lst[MAX];
char c;
int i,j,k,t,n,m,temp;
bool slt;
int main(){
//	while(scanf("%lld%lld%c",&cft1[j],&deg1[j],&c),c != '\n')
//		j++;
//	while(scanf("%lld%lld%c",&cft2[k],&deg2[k],&c),c != '\n')
//		k++;
//	for(i = 0; i <= j; i++)
//		for(t = 0; t <= k; t++)
//			res[deg1[i] + deg2[t]] += (cft1[i] *cft2[t]);
//	for(i = MAX-1; i >= 0; i--)
//		if(res[i] != 0)
//			printf("%lld %d ",res[i],i);
	while(scanf("%lld%lld%c",&cft1[j],&deg1[j],&c),c != '\n')
		j++;
	while(scanf("%lld%lld%c",&cft2[k],&deg2[k],&c),c != '\n')
		k++;
	for(i = 0; i <= j; i++){
		for(t = 0; t <= k; t++){
			for(m = 0; m < n; m++){
				if(resd[m] == deg1[i] + deg2[t]){
					resc[m] += cft1[i] * cft2[t];
					slt=1;
					break;
				}
			}
			if(slt == 0){
				resc[n] = cft1[i] * cft2[t];
				resd[n] = deg1[i] + deg2[t];
				n++;
			}
			slt = 0;
		}
	}
	for(i = 0; i < n; i++)
		lst[i] = i;
	for(j = 0; j < n; j++){
		for(i = 1; i < n; i++){
			if(resd[lst[i]] > resd[lst[i-1]]){
				temp = lst[i];
				lst[i] = lst[i-1];
				lst[i-1] = temp;
			}
		}
	}
	for(i = 0; i < n; i++)
		printf("%lld %lld ",resc[lst[i]],resd[lst[i]]);
	return 0;
}



