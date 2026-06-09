#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define FEqual(a,b,eps) (fabs((a)-(b))<(eps)) 

#define N 1024
struct term{
	int a;
	int n;
}t1[N], t2[N], r[N], temp;
int l1, l2, lr;

int main(){
	for (l1=0; ; l1++){
		scanf("%d%d", &t1[l1].a, &t1[l1].n);
		if (getchar()=='\n') break;
	}l1++;
	for (l2=0; ; l2++){
		scanf("%d%d", &t2[l2].a, &t2[l2].n);
		if (getchar()=='\n') break;
	}l2++;
	for (int i=0; i<l1; i++){
		for (int j=0; j<l2; j++){
			temp.a=t1[i].a*t2[j].a;
			temp.n=t1[i].n+t2[j].n;
			{
				int l=0, h=lr-1, mid=(l+h)/2;
				while(h>=l){
					if (r[mid].n<temp.n){
						h=mid-1;
						mid=(l+h)/2;
					}else if (r[mid].n>temp.n){
						l=mid+1;
						mid=(l+h)/2;
					}else{
						r[mid].a+=temp.a;
						goto step1;
					}
				}
				for (int k=lr; k>l; k--){
					r[k]=r[k-1];
				}
				r[l]=temp;
				lr++;
			}
step1:
			continue;
		}
	}
	for (int i=0; i<lr; i++){
		if (r[i].a){
			printf("%d %d ", r[i].a, r[i].n);
		}
	}
	return 0;
}




