#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
struct multi{
	long long a,x;
	int t;
};
struct multi o[1000000];
int paixu(const void* a,const void* b){
	struct multi* aa=(struct multi*)a;
	struct multi* bb=(struct multi*)b;
	return (aa->x<bb->x?1:-1);
}
int main()
{
    struct multi m[1000],n[1000];
    int i=0,j=0,k=0,p,q;

    char ch=0;
	while(ch!='\n'){
		scanf("%lld%lld",&m[i].a,&m[i].x );
		i++;
		ch=getchar();
}
	p=i;
	i=0;
	ch=0;
    while(ch!='\n'){
		scanf("%lld%lld",&n[i].a,&n[i].x );
		i++;
		ch=getchar();
}
	q=i;
	
	printf("\n");
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			o[k].a=m[i].a*n[j].a;
			o[k].x=m[i].x+n[j].x;
			o[k].t=1;
			k++;
		}
	}
	qsort(o,k,sizeof(o[0]),paixu);
	for(i=0;i<k;i++){
		for(j=i+1;j<k;j++){
			if(o[i].x==o[j].x){
				o[i].a+=o[j].a;
				o[j].t=0;
			}
		}

	}
	for(i=0;i<k;i++){
		if(o[i].a!=0&&o[i].t==1)
			printf("%lld %lld ",o[i].a,o[i].x);
	}
	return 0;
}


