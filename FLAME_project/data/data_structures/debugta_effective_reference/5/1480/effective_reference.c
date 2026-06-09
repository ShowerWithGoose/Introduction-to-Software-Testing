#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
struct node {
	int xi;
	int zhi;
} a[1000], b[1000],e[1000];
int cmp(const void*_a,const void *_b){
	struct node* a = (struct node*)_a;
	struct node* b = (struct node*)_b;
	if(a->zhi>=b->zhi) return -1;
	return 1;
}
char ch;
int lena,lenb;
int main() {
	int i;
	for (i = 0; ch != '\n'; i++) {
		scanf("%d%d%c", &a[i].xi, &a[i].zhi, &ch);
	}
	lena = i;
	ch='1';
	for (i = 0; ch != '\n'; i++) {
		scanf("%d%d%c", &b[i].xi, &b[i].zhi, &ch);
	}
	lenb = i;
	int k=0;
	for(int i = 0;i<lena;i++){
		for(int j = 0;j<lenb;j++,k++){
			e[k].xi=a[i].xi*b[j].xi;
			e[k].zhi=a[i].zhi+b[j].zhi;
		}
	}
	
	qsort(e,k,sizeof(e[0]),cmp);
	for(int i=0;i<k;i++){
		if(e[i].zhi==e[i+1].zhi) {
			e[i+1].xi+=e[i].xi;
			e[i].xi=0;
		}
	}
	for(int i=0;i<=k;i++){
		if(e[i].xi==0) continue;
		printf("%d %d ",e[i].xi,e[i].zhi);
	}
	return 0;
}

