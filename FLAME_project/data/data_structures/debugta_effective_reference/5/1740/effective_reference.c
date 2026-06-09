#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
	int coe;
	int pow;
}a[1000],b[1000],d[10000];
int cmp(const void *a,const void *b){
	struct node *d=(struct node *)a;
	struct node *c=(struct node *)b;
	return c->pow-d->pow;
}
int main(){
	char c;
	int num1=0,num2=0,p,q,num3=0;
	do{
		scanf("%d%d%c",&a[num1].coe,&a[num1].pow,&c);		
		num1++;
	}while(c!='\n');
	do{
		scanf("%d%d%c",&b[num2].coe,&b[num2].pow,&c);
		num2++;
	}while(c!='\n');
	p=num1;q=num2;
	for(num1=0;num1<p;num1++){
		for(num2=0;num2<q;num2++){
			d[num3].coe=(b[num2].coe)*(a[num1].coe);
			d[num3].pow=b[num2].pow+a[num1].pow;
			num3++;
		}
	}
	qsort(d,num3-1,sizeof(d[0]),cmp);
	for(num1=0;num1<num3-1;num1++){
		if(d[num1].pow==d[num1+1].pow){
			d[num1+1].coe+=d[num1].coe;
			d[num1].coe=0;
		}
	}
	for(num1=0;num1<num3;num1++){
		if(d[num1].coe==0)
		continue;
		else{
			printf("%d %d ",d[num1].coe,d[num1].pow);
		}
	}
	return 0;
}

