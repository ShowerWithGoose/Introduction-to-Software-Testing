#include <stdio.h>
#include <stdlib.h>
struct multi {
	int zhi;
	int xi;
};
int cmp(const void*a,const void*b){
	struct multi* aa=(struct multi*)a;
	struct multi* bb=(struct multi*)b;
	return bb->zhi-aa->zhi;
}
int main() {
	int cnt1=0,cnt2=0,cnt3=0;
	char c=0,d=0;
	struct multi in1[1000],in2[1000],ans[100000];
	while(c!='\n') {
		scanf("%d%d",&in1[cnt1].xi,&in1[cnt1].zhi);
		c=getchar();
		cnt1++;
	}
	while(d!='\n') {
		scanf("%d%d",&in2[cnt2].xi,&in2[cnt2].zhi);
		d=getchar();
		cnt2++;
	}
	for(int i=0; i<cnt1; i++) {
		for(int j=0; j<cnt2; j++) {
			ans[cnt3].xi=in1[i].xi*in2[j].xi;
			ans[cnt3].zhi=in1[i].zhi+in2[j].zhi;
			cnt3++;
		}
	}
	qsort(ans,cnt3,sizeof(ans[0]),cmp);
	for(int q=1; q<cnt3; q++) {
		if(ans[q].zhi==ans[q-1].zhi) {
			ans[q-1].xi+=ans[q].xi;
			for(int m=q; m<cnt3-1; m++) {
				ans[m]=ans[m+1];
			}
			cnt3--;
			q--;
		}
	}
	for(int q=0; q<cnt3; q++) {
		printf("%d %d ",ans[q].xi,ans[q].zhi);
	}
}



