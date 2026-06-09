#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
struct node {
	int xi;
	int zhi;
} a[1000], b[1000],c[1000];
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
	int p=0;
	for(int j = 0;j<lena;j++){
		for(int k = 0;k<lenb;k++,p++){
			c[p].xi=a[j].xi*b[k].xi;
			c[p].zhi=a[j].zhi+b[k].zhi;
		}
	}
	
	qsort(c,p,sizeof(c[0]),cmp);
	for(int j=0;j<p;j++){
		if(c[j].zhi==c[j+1].zhi) {
			c[j+1].xi+=c[j].xi;
			c[j].xi=0;
		}
	}
	for(int j=0;j<=p;j++){
		if(c[j].xi==0) continue;
		printf("%d %d ",c[j].xi,c[j].zhi);
	}
	return 0;
}

