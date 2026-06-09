#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int coe;
	int pow;
}a[1000],b[1000],c[10000];
int cmp(const void *a,const void *b){
	struct node *c=(struct node *)a;
	struct node *d=(struct node *)b;
	return d->pow-c->pow;
}
int main(){
	char d;
	int i=0,j=0,p,q,k=0;
	do{
		scanf("%d%d%c",&a[i].coe,&a[i].pow,&d);		
		i++;
	}while(d!='\n');
	do{
		scanf("%d%d%c",&b[j].coe,&b[j].pow,&d);
		j++;
	}while(d!='\n');
	p=i;q=j;
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			c[k].coe=(b[j].coe)*(a[i].coe);
			c[k].pow=b[j].pow+a[i].pow;
			k++;
		}
	}
	qsort(c,k-1,sizeof(c[0]),cmp);
	for(i=0;i<k-1;i++){
		if(c[i].pow==c[i+1].pow){
			c[i+1].coe+=c[i].coe;
			c[i].coe=0;
		}
	}
	for(i=0;i<k;i++){
		if(c[i].coe==0)
		continue;
		else{
			printf("%d %d ",c[i].coe,c[i].pow);
		}
	}
	return 0;
}

