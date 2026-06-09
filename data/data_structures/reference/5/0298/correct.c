#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5000

typedef struct POLY {
	int coe,ind;
	struct POLY* link;
} poly, *pptr;

int main() {
	
	pptr list = NULL,p,q;
	poly a[MAX_SIZE],b[MAX_SIZE];
	int max1 = 0, max2 = 0;
	int coetemp;
	int a_len, b_len;
	
	for(int i = 0; ; i++){
		scanf("%d%d",&a[i].coe, &a[i].ind);
		if(getchar() == '\n'){
			a_len = i+1;
			break;
		}
	}
	for(int i = 0; ; i++){
		if(scanf("%d%d",&b[i].coe, &b[i].ind)==EOF){
			b_len = i;
			break;
		}
	}
		
	while(1) {
		q = (pptr) malloc (sizeof(poly));
		if(list == NULL) {
			q->coe = a[0].coe * b[0].coe;
			q->ind = a[0].ind + b[0].ind;
			max1 = a[0].ind + b[0].ind;
			list = q;
			p = list;
		} 
		else {
			for(int i = 0; i < a_len; i++) {
				for(int j = 0; j < b_len; j++) {
					if(a[i].ind + b[j].ind >= max1)
						continue;
					else {
						if(max2 < a[i].ind + b[j].ind){
							max2 = a[i].ind + b[j].ind;
							coetemp = a[i].coe * b[j].coe;
						}
						else if(max2 == a[i].ind + b[j].ind)
							coetemp += a[i].coe * b[j].coe;
					}
				}
			}
			q->coe = coetemp;
			q->ind = max2;
			max1 = max2;
			p->link=q;
			p=p->link;
			if(max2 == 0)
				break;
			max2 = 0;
			coetemp = 0;
		}
	}
	for(pptr k = list; k != NULL; k = k->link) {
		if(k->coe == 0) continue;
		printf("%d %d ",k->coe,k->ind);
	}
	return 0;
}



