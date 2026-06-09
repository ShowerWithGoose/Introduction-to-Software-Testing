#include<stdio.h>
#include<stdlib.h>
typedef struct{
	long long  xi;
	long long zhi;
}shi;
shi a[10005],b[10005],c[100000005];
int flag[1000005];
int cmp(const void *a,const void*b){
	shi*c=(shi*)a;
	shi*d=(shi*)b;
	return (d->zhi)-(c->zhi );
}
int main()
{
	int i,j,k=0;
	char w1,w2;
	for(i=0;w2!='\n';i++){
		scanf("%lld%c%lld%c",&a[i].xi ,&w1,&a[i].zhi ,&w2);
	}
	int count1=i;
	w2='\0';
	for(i=0;w2!='\n';i++){
		scanf("%lld%c%lld%c",&b[i].xi ,&w1,&b[i].zhi ,&w2);
	}
	int count2=i;
	for(i=0;i<count1;i++)
	for(j=0;j<count2;j++){
		c[k].zhi =a[i].zhi+b[j].zhi ;
		c[k++].xi =a[i].xi *b[j].xi ;
	}
	qsort(c,k,sizeof(shi),cmp);
	for(i=0;i<k-1;i++)
	{
	if(flag[i]==1)
	continue;
	for(j=i+1;j<k;j++){
		if(flag[j]==1)
		continue;
		if(c[i].zhi ==c[j].zhi ){
			c[i].xi +=c[j].xi ;
			flag[j]=1;
		}
	}	
	}
	for(i=0;i<k;i++){
		if(flag[i]==0)
		printf("%lld %lld ",c[i].xi ,c[i].zhi );
	}
	return 0;
}

