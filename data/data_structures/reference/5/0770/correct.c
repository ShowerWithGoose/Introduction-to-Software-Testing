#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct num{
	int xi, t;
}num;
int cmp(num*, num*);
int main(){
	num a[99], b[99], ans[9999];
	int i=0, j=0, cnt=0;
	char c;
	while(1){
		scanf("%d%d", &a[i].xi, &a[i].t);
		c = getchar();
		if(c == '\n')
			break;
		i++;
	}
	i++;
	while(1){
		scanf("%d%d", &b[j].xi, &b[j].t);
		c = getchar();
		if(c == '\n')
			break;
		j++;
	}
	j++;

	for(int k=0; k<i; k++){
		for(int l=0; l<j; l++){
			ans[cnt].t = a[k].t+b[l].t;
			ans[cnt].xi = a[k].xi * b[l].xi;
			cnt++;
		}
	}
	qsort(ans, cnt, sizeof(num), cmp);
	int repeat=0, rturn;
	for(int k=0; k<cnt; k++){
		rturn =0;
		for(int h=k+1; h<cnt && ans[k].t==ans[h].t; h++){
			ans[k].xi += ans[h].xi;
			ans[h].xi=0;
			ans[h].t=-1;
			rturn++;
		}
		repeat += rturn;
		if(ans[k].xi == 0){
			ans[k].t=-1;
			repeat++;
			k += rturn;
		}
		k += rturn;
	}
	qsort(ans, cnt, sizeof(num), cmp);
	for(int k=0; k<cnt-repeat; k++)
		printf("%d %d ", ans[k].xi, ans[k].t);
	return 0;
}
int cmp(num *x, num *y){
	return y->t - x->t;
}

