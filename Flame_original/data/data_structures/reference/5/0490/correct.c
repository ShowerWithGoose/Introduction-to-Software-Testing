#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<ctype.h>
#include<math.h>
#include <stdio.h>
struct pzx{
	int xs;
	int zs;
};
typedef struct pzx pj;
pj x[2000],y[2000],z[2000];
int comp(const void*a,const void*b){
	struct pzx *c=(struct pzx*)a;
	struct pzx *d=(struct pzx*)b;
	return d->zs-c->zs;
}
int main()
{
    int i,j;
    int r=0;
    int m=0,n=0;
    char s;
    do{
    scanf("%d%d%c",&x[m].xs ,&x[m].zs ,&s);
    m++;
}while(s!='\n');
    do{
    scanf("%d%d%c",&y[n].xs ,&y[n].zs ,&s);
    n++;}while(s!='\n');
    qsort(x,m,sizeof(pj),comp);
    qsort(y,n,sizeof(pj),comp);
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
    		z[r].xs =x[i].xs *y[j].xs ;
    		z[r].zs =x[i].zs +y[j].zs ;
    		r++;
		}
	}
    qsort(z,r,sizeof(pj),comp);
    for(i=0;i<r;i++){
    	if(z[i].zs ==z[i+1].zs &&z[i].zs !=0){
    		z[i+1].xs +=z[i].xs ;
			 z[i].xs =0;
		}
	}
    qsort(z,r,sizeof(pj),comp);
    for(i=0;i<r;i++){
    	if(z[i].xs ==0){
    		continue;
		}
		else{
			printf("%d %d ",z[i].xs ,z[i].zs );
		}
    }
    return 0;
}

