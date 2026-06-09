#include<stdio.h>
#include<stdlib.h>
struct sets{
	int xishu;
	int zhishu;
};
typedef struct sets def;
def a[10000],b[10000],c[10000];
int i,j,k;
int n=0,m=0;
int cmp(const void *p1,const void *p2);
char flag;
int main()
{
	do
		{
			scanf("%d%d%c",&a[n].xishu,&a[n].zhishu,&flag);
			n++;
		}while(flag!='\n');
	do
		{
			scanf("%d%d%c",&b[m].xishu,&b[m].zhishu,&flag);
			m++;
		}while(flag!='\n');
	qsort(a,n,sizeof(def),cmp);
	qsort(b,m,sizeof(def),cmp);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			c[k].xishu=a[i].xishu*b[j].xishu;
			c[k].zhishu=a[i].zhishu+b[j].zhishu;
			k++;
		}
	}
	qsort(c,k,sizeof(def),cmp);
	for(i=0;i<k;i++){
		if(c[i].zhishu==c[i+1].zhishu&&c[i].zhishu!=0){
			c[i+1].xishu+=c[i].xishu;
			c[i].xishu=0;
		}
	}
	for(i=0;i<k;i++){
		if(c[i].xishu!=0){
			printf("%d %d ",c[i].xishu,c[i].zhishu);
		}
	}
	return 0;
}


int cmp(const void *p1,const void *p2)
{
	struct sets *a=(struct sets*)p1;
	struct sets *b=(struct sets*)p2;
	return (b->zhishu-a->zhishu);
}

