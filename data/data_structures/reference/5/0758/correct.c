#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node {
    int coe;//ÏµÊý
    int pow;//ÃÝ 
    char ch;
}Nodeptr; 
Nodeptr a[2000],b[2000],c[2000];

int cmp(const void*p1,const void*p2){
	struct node *a = (struct node*)p1;
	struct node *b = (struct node*)p2;
	return b->pow - a->pow;
}

int main()
{
    int na=0,nb=0,i,j,k=0;
    char ch;
    do {
        scanf("%d%d%c",&a[na].coe,&a[na].pow, &ch);
        na ++;
	} while ( ch != '\n');
    do {
        scanf("%d%d%c",&b[nb].coe,&b[nb].pow, &ch);
        nb ++;
	} while ( ch != '\n');
	qsort(a,na,sizeof(Nodeptr),cmp);
	qsort(b,nb,sizeof(Nodeptr),cmp);
    for(i=0;i<na;i++){
    	for(j=0;j<nb;j++){
    		c[k].coe = a[i].coe * b[j].coe;
    		c[k].pow = a[i].pow + b[j].pow;
    		k ++;
		}
	}
	qsort(c,k,sizeof(Nodeptr),cmp);
	for(i=0;i<k;i++){
		if(c[i].pow == c[i+1].pow && c[i].pow != 0){
			c[i+1].coe += c[i].coe;
			c[i].coe = 0;
		}
	}
	qsort(c,k,sizeof(Nodeptr),cmp);
	for(i=0;i<k;i++){
		if(c[i].coe != 0){
			printf("%d %d ",c[i].coe,c[i].pow);
		}
	}
    return 0;
}

