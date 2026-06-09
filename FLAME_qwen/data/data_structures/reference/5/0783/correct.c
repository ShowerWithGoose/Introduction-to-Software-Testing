#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100000
struct Node{
	int m;
	int n;
}a[MAX],b[MAX],p[MAX];
int cmp(const void* a,const void* b)
{
	struct Node *c=(struct Node *)a;
	struct Node *d=(struct Node *)b;
	return d->n - c->n;
}
int main()
{
	int i,j,k=0,cnt1=0,cnt2=0;
	char c;
	while(c!='\n'){
		scanf("%d%d%c",&a[cnt1].m,&a[cnt1].n,&c);
		++cnt1;
	}
	c=' ';
	while(c!='\n'){
		scanf("%d%d%c",&b[cnt2].m,&b[cnt2].n,&c);
		++cnt2;
	}
	for(i=0;i<cnt1;i++){
		for(j=0;j<cnt2;j++){
			p[k].m=a[i].m*b[j].m;
			p[k].n=a[i].n+b[j].n;
			k++;
		}
	}
	qsort(p,k,sizeof(p[0]),cmp);
	for(i=0;i<k;i++){
		if(p[i].n==p[i+1].n&&p[i].n!=0){
			p[i+1].m+=p[i].m;
			p[i].m=0;
		}
	}
	for(i=0;i<k;i++){
		if(p[i].m!=0)
		printf("%d %d ",p[i].m,p[i].n);
	}
	return 0;
}

