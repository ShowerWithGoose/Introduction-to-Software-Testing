#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct xiang{
    int n;
    int a;
}x;

int comp(const void*a , const void*b){
    return *(int*)b - *(int*)a;
}

int main () {
    int a1[1000] , a2[1000] , n1[1000] , n2[1000] , a3[1000] , n3[1000] , a4[1000] , n4[1000] , i = 0 , j = 0 , k = 0 , m , n;
    x x1[1000] , x2[1000] , x3[1000] , x4[1000];
    while (1) {
        scanf ("%d %d" , &x1[i].a , &x1[i].n) ;
        if(getchar() == '\n') break;
        i++;
    }
    while (1) {
        scanf ("%d %d" , &x2[j].a , &x2[j].n) ;
        if(getchar() == '\n') break;
        j++;
    }
	m = i ; n = j ;
	for(i = 0; i <= m; i++) {
		for (j = 0; j <= n ; j ++) {
			x3[k].a = x1[i].a * x2[j].a ;
			x3[k].n = x1[i].n + x2[j].n ;
			k++;
		}
	}
    qsort(x3 , k , sizeof(x) , comp);
    for(i = 0 , j = 0 ; i <= k - 1 ; i++){
        while(x3[i].n == x3[i+1].n){
            x3[i+1].a += x3[i].a;
            i++;
        }
        if(x3[i].a == 0)continue;
        x4[j].a = x3[i].a;
        x4[j].n = x3[i].n;
        j++;
    }
	for(i = 0 ; i <= j - 1 ; i++) printf("%d %d ",x4[i].a , x4[i].n);
	return 0;
}
