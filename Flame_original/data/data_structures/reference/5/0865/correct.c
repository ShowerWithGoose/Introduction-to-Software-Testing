#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct node{
	int coe;
	int pow;
};
int cmp(const void*a1,const void* b1);
int main(){
	struct node a[1005],b[1005],c[10005];
	char p=' ';
	int cnta=0,cntb=0,cntc=0,i,j;
	while(p!='\n'){
		scanf("%d%d%c",&a[cnta].coe,&a[cnta].pow,&p);
		cnta++;
	}
	p=' ';
	while(p!='\n'){
		scanf("%d%d%c",&b[cntb].coe,&b[cntb].pow,&p);
		cntb++;
	}
	for(i=0;i<cnta;i++){
		for(j=0;j<cntb;j++){
			c[cntc].coe=a[i].coe*b[j].coe;
			c[cntc].pow=a[i].pow+b[j].pow;
			cntc++;
		}
	}
	qsort(c,cntc,sizeof(struct node),cmp);
	for(i=0;i<cntc-1;i++){
		if(c[i].pow==c[i+1].pow){
			for(j=1;j<cntc-i;j++){
				if(c[i].pow==c[i+j].pow){
					c[i].coe+=c[i+j].coe;
					c[i+j].coe=0;
				}
				else{
					break;
				}
			}
		}
	}
	for(i=0;i<cntc;i++){
		if(c[i].coe!=0) 
		printf("%d %d ",c[i].coe,c[i].pow);
	}
	
	
	return 0;
}
int cmp(const void*a1,const void* b1){
	struct node *a=(struct node*)a1,*b=(struct node*)b1;
	if(a->pow>b->pow) return -1;
	else return 1;
}


