#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define S scanf
#define P printf
#define L long long
struct node{
	L xi,zhi;
};
typedef struct node mi;
mi a[1005],b[1005],c[1005];
int cmp(const void *a, const void *b){
	struct node c = *(struct node *)a;
	struct node d = *(struct node *)b;
	return d.zhi-c.zhi;
}
int main(){
	char ch;
	int n1=0,n2=0,i,j,k=0;
	do{
		S("%lld %lld%c",&a[n1].xi,&a[n1].zhi,&ch);
		n1++;
	}while(ch!='\n');
	do{
		S("%lld %lld%c",&b[n2].xi,&b[n2].zhi,&ch);
		n2++;
	}while(ch!='\n');
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			c[k].zhi=a[i].zhi+b[j].zhi;
			c[k].xi=a[i].xi*b[j].xi;
			k++;
		}
	}
	qsort(c,k,sizeof(c[0]),cmp);
	for(i=0;i<k;i++){
		if(c[i].zhi==c[i+1].zhi&&c[i].zhi!=0){
			c[i+1].xi+=c[i].xi;
			c[i].xi=0;
		}
	}
	for(i=0;i<k;i++){
		if(c[i].xi!=0)
		P("%lld %lld ",c[i].xi,c[i].zhi);
	}
	return 0;
}

