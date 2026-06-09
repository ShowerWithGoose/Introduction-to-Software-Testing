#include <stdio.h>
#include <string.h>

int main(){
	long long line1x[100],line1y[100],line2x[100],line2y[100], n, i, j, k = 1, sum = 0, l, p;
	scanf("%lld", &n);
	for(i = 0;i < n;i++){
		scanf("%lld %lld %lld %lld", &line1x[i], &line1y[i], &line2x[i],&line2y[i]);
	}
	for(i = 0;i < n;i++){
		l = i;
		for(j = 0;j < n;j++){
			if(line2x[i]==line1x[j]){
				if(line2y[i]==line1y[j]){
					i = j;
					k++;
					j = -1;
				}
			}
		}
		if(sum < k){
			sum = k;
			p = l;
		}
		i = l;
		k = 1;
	} 
	printf("%lld %lld %lld", sum, line1x[p], line1y[p]);
	return 0;
} 

