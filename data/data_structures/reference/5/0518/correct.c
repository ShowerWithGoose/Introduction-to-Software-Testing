#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define eps 1e-10
typedef struct multi {
	int frequency;
	int index;
} m;
m a[1005],b[1005],c[1005],d[1005];
int cmp(const void*p1,const void*p2);
int cmp(const void*p1,const void*p2){
	struct multi *a=(struct multi*)p1;
	struct multi *b=(struct multi*)p2;
	return b->index-a->index;
}
int main() {
	int i,j,k=0,l=0;
	int n1=0,n2=0;
	char ch;
	do {
		scanf("%d%d%c",&a[n1].frequency,&a[n1].index,&ch);
		n1++; 
	}while(ch!='\n');
	do{
		scanf("%d%d%c",&b[n2].frequency,&b[n2].index,&ch);
		n2++;
	}while(ch!='\n');
	qsort(a,n1,sizeof(m),cmp);
	qsort(b,n2,sizeof(m),cmp);
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			c[k].index=a[i].index+b[j].index;
			c[k].frequency=a[i].frequency*b[j].frequency;
			k++;
		}
	}
	qsort(c,k,sizeof(m),cmp);
	for(i=0;i<k;i++){
		if(c[i].index==c[i+1].index&&c[i].index!=0){
			c[i+1].frequency+=c[i].frequency;
			c[i].frequency=0;
		}
	}
	qsort(c,k,sizeof(m),cmp);
	for(i=0;i<k;i++){
		if(c[i].frequency!=0){
			d[l].index=c[i].index;
			d[l].frequency=c[i].frequency;
			l++;
		}
		}
	qsort(d,l,sizeof(m),cmp);
	for(i=0;i<l;i++){
		printf("%d %d ",d[i].frequency,d[i].index);
	}	
	return 0;	
}


