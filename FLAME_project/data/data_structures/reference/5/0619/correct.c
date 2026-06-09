#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int co;
	int en;
}a[100000],b[100000],p[100000];
char c = ' ';
int compare(const void*a,const void*b){
	struct node * c = (struct node *)a;
	struct node * d = (struct node *)b;
	return d->en - c->en;
}
int main()
{
	int m,n;
	int cnta = 0,cntb = 0;
	while(c != '\n'){
		scanf("%d%d%c",&m,&n,&c);
		a[cnta].co = m;
		a[cnta].en = n;
		cnta++;
	}
	c = ' ';
	while(c!='\n'){
		scanf("%d%d%c",&m,&n,&c);
		b[cntb].co = m;
		b[cntb].en = n;
		cntb++;
	} 
	int k = 0;
	for(int i = 0;i < cnta;i++){
		for(int j = 0;j < cntb;j++){
			p[k].co = a[i].co * b[j].co;
			p[k].en = a[i].en + b[j].en;
			k++;
		}
	}
	qsort(p,k,sizeof(p[0]),compare);
	for(int i = 0;i < k;i++){
		if(p[i].en == p[i+1].en&&p[i].en != 0){
			p[i+1].co +=p[i].co;
			p[i].co = 0; 
		}
	}
	for(int i = 0;i < k;i++){
		if(p[i].co != 0){
			printf("%d %d ",p[i].co,p[i].en);
		}
	}
	return 0;
}


